import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from scipy.optimize import minimize
from deap import creator, base, tools, algorithms
import numba
from numba import typed

def read_excel_data(filepath):
    demands = typed.Dict.empty(
        key_type=numba.types.UniTuple(numba.types.int64, 2),
        value_type=numba.types.float64
    )
    try:
        demands_dataframe = pd.read_excel(filepath, sheet_name='Demands')
        for index, row in demands_dataframe.iterrows():
            origin_destination = (int(row['Start']), int(row['End']))
            demand_value = row['Demand']
            demands[origin_destination] = float(demand_value)
        return demands, demands_dataframe
    except Exception as e:
        print(f"Error reading the Excel file: {e}")
        return demands, pd.DataFrame()

def create_graph():
    G = nx.Graph()
    edges = [(1, 2), (1, 4), (2, 3), (2, 5), (3, 6), (4, 5), (4, 7), (5, 6), (5, 8), (6, 9), (7, 8), (8, 9)]
    G.add_edges_from(edges)
    return G

def generate_all_paths(G, source, target, cutoff=None):
    # Generate all simple paths from source to target and convert each path to a numpy array
    return [np.array(path, dtype=np.int64) for path in nx.all_simple_paths(G, source=source, target=target, cutoff=cutoff)]

@numba.jit(nopython=True)
def evaluate(individual, demands, paths_dict):
    total_network_demand = sum(demands.values())
    successful_demand = 0.0

    individual_idx = 0

    for (source, target), paths in paths_dict.items():
        num_paths = len(paths)
        path_weights = individual[individual_idx:individual_idx + num_paths]
        individual_idx += num_paths

        normalized_weights = np.clip(path_weights, 0, 1)
        weight_sum = np.sum(normalized_weights)
        if weight_sum != 0:
            normalized_weights /= weight_sum

        for path_idx, path in enumerate(paths):
            path_failure_prob = 1 - (1 - 1/12) ** (len(path) - 1)
            successful_prob = 1 - path_failure_prob
            path_demand = demands[(source, target)] * successful_prob * normalized_weights[path_idx]
            successful_demand += path_demand

    return (successful_demand / total_network_demand,)

def checkBounds(min, max):
    def decorator(func):
        def wrappper(*args, **kargs):
            offspring = func(*args, **kargs)
            for child in offspring:
                for i in range(len(child)):
                    if child[i] > max:
                        child[i] = max
                    elif child[i] < min:
                        child[i] = min
            return offspring
        return wrappper
    return decorator

def setup_genetic_algorithm(demands, paths_dict):
    n_genes = sum(len(paths) for paths in paths_dict.values())  # Calculate total number of genes required
    creator.create("FitnessMax", base.Fitness, weights=(1.0,))
    creator.create("Individual", list, fitness=creator.FitnessMax)
    toolbox = base.Toolbox()
    toolbox.register("attr_float", random.random)
    toolbox.register("individual", tools.initRepeat, creator.Individual,
                     toolbox.attr_float, n=n_genes)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("evaluate", evaluate, demands=demands, paths_dict=paths_dict)
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=0.1, indpb=0.2)
    toolbox.decorate("mutate", checkBounds(0, 1))
    return toolbox

def main():
    filepath = r'Python/Math/MathClub/51Club/B//data/TDNetwork2.xlsx'
    demands, _ = read_excel_data(filepath)
    G = create_graph()
    paths_dict = typed.Dict.empty(
        key_type=numba.types.UniTuple(numba.types.int64, 2),
        value_type=numba.types.List(numba.types.int64[:])  # Specify a list of 1D int64 arrays
    )
    for key in demands.keys():
        paths = generate_all_paths(G, *key)
        paths_dict[key] = paths  # Directly use the list of numpy arrays
    toolbox = setup_genetic_algorithm(demands, paths_dict)

    population = toolbox.population(n=300)
    NGEN = 80
    best_fitness = []

    all_generations_data = []

    for gen in range(NGEN):
        offspring = algorithms.varAnd(population, toolbox, cxpb=0.5, mutpb=0.2)
        fits = map(toolbox.evaluate, offspring)

        gen_data = []

        for fit, ind in zip(fits, offspring):
            ind.fitness.values = fit
            
            path_info = []
            individual = ind[:]
            for (source, target), paths in paths_dict.items():
                path_weights = individual[:len(paths)]
                individual = individual[len(paths):]
                normalized_weights = np.clip(path_weights, 0, 1)
                normalized_weights /= np.sum(normalized_weights) if np.sum(normalized_weights) != 0 else 1

                for path_idx, path in enumerate(paths):
                    path_demand = demands[(source, target)] * normalized_weights[path_idx]
                    path_info.append({'Source': source, 'Target': target, 'Path': path, 'Assigned Demand': path_demand})
            
            gen_data.extend(path_info)

        if gen > 75:
            all_generations_data.append(pd.DataFrame(gen_data))

        population = toolbox.select(offspring, k=len(population))
        best_individual = tools.selBest(population, k=1)[0]
        best_fitness.append(best_individual.fitness.values[0])
    all_generations_data = pd.concat(all_generations_data,ignore_index=True)
    all_generations_data.to_excel('output_path_flows.xlsx',index=False)
    plt.figure(figsize=(10, 5))
    plt.plot(best_fitness, label='Best Fitness')
    plt.title('Best Fitness Over Generations')
    plt.xlabel('Generation')
    plt.ylabel('Fitness')
    plt.legend()
    plt.grid(True)
    plt.show()

    print("Best Fitness:", best_individual.fitness.values[0])

if __name__ == "__main__":
    main()
