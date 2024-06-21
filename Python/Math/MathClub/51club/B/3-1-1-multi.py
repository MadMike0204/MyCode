import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from scipy.optimize import minimize
from deap import creator, base, tools, algorithms
from scipy.special import comb
from datetime import datetime
from multiprocessing import Pool

def read_excel_data(filepath):
    # Load Excel data once and return the demands and the dataframe
    demands = {}
    try:
        demands_dataframe = pd.read_excel(filepath, sheet_name='Demands')
        for index, row in demands_dataframe.iterrows():
            origin_destination = (row['Start'], row['End'])
            demand_value = row['Demand']
            demands[origin_destination] = demand_value * 1.0
        return demands, demands_dataframe
    except Exception as e:
        print(f"Error reading the Excel file: {e}")
        return {}, pd.DataFrame()

def read_segment_capacities(filepath):
    # Load Excel data once and return the segment capacities and the dataframe
    capacities = {}
    try:
        capacities_dataframe = pd.read_excel(filepath, sheet_name='Capacities')
        for index, row in capacities_dataframe.iterrows():
            start_end_tuple = (row['Start'], row['End'])
            capacity_value = row['Capacity']
            capacities[start_end_tuple] = capacity_value
        return capacities, capacities_dataframe
    except Exception as e:
        print(f"Error reading the Excel file: {e}")
        return {}, pd.DataFrame()

def create_graph():
    # Creating a predefined graph structure
    G = nx.DiGraph()
    edges=[(0,1),(0,3),(0,6),
       (1,0),(1,4),
       (2,3),(2,15),(2,18),
       (3,0),(3,2),(3,36),(3,42),
       (4,1),(4,6),
       (5,6),(5,9),(5,16),(5,22),
       (6,0),(6,4),(6,5),(6,34),(6,36),
       (7,12),(7,24),(7,33),
       (8,9),(8,28),(8,37),(8,41),
       (9,5),(9,8),(9,10), 
       (10,9), (10,11), (10,16), (10,19), (10,41), 
       (11,10), (11,12), (11,20), (11,41),
       (12,7), (12,11), (12,35),
       (13,14), (13,15), (13,38), (13,39),
       (14,13),(14,17),(14,21),
       (15,2),(15,13),(15,42),
       (16,5),(16,10),(16,18),(16,36),
       (17,14),(17,21),(17,39),
       (18,2),(18,16),(18,19),(18,23),
       (19,10),(19,18),(19,20),(19,23),
       (20,11),(20,19),
       (21,14),(21,17),
       (22,5),(22,34),(22,40),
       (23,18),(23,19),
       (24,7),(24,32),
       (25,30),(25,33),
       (26,31),(26,32),(26,33),
       (27,30),(27,33),(27,35),
       (28,8),(28,35),(28,37),
       (29,31),(29,32),
       (30,25),(30,27),
       (31,26),(31,29),
       (32,24),(32,26),(32,29),
       (33,7),(33,25),(33,26),(33,27),
       (34,6),(34,22),(34,40),
       (35,12),(35,27),(35,28),(35,41),
       (36,3),(36,6),(36,16),
       (37,8),(37,28),
       (38,13),(38,39),(38,42),
       (39,13),(39,17),(39,38),
       (40,22),(40,34),
       (41,8),(41,10),(41,11),(41,35),
       (42,3),(42,15),(42,38)]
    G.add_edges_from(edges)
    return G

def generate_k_shortest_paths(G, source, target, k=5):
    """Generate k shortest simple paths from source to target in the graph G."""
    try:
        return list(islice(nx.shortest_simple_paths(G, source, target, weight=None), k))
    except nx.NetworkXNoPath:
        print(f"No path between {source} and {target}")
        return []
    
def evaluate(individual,demands,paths_dict):
    # Fitness evaluation function considering path failure probabilities
    total_network_demand = sum(demands.values())
    successful_demand = 0

    for (source, target), paths in paths_dict.items():
        path_weights = np.array(individual[:len(paths)], dtype=float)  # 确保权重数组是float类型
        individual = individual[len(paths):]
        normalized_weights = np.clip(path_weights, 0, 1)
        normalized_weights /= np.sum(normalized_weights) if np.sum(normalized_weights) != 0 else 1.0

        for path_idx, path in enumerate(paths):
            
            successful_prob = (128/133) ** (len(path) - 1)
            path_demand = demands[(source, target)] * successful_prob * normalized_weights[path_idx]
            successful_demand += path_demand

    return (successful_demand / total_network_demand,)

def checkBounds(min, max):
    # Decorator to enforce bounds on mutation
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

# Initialization and genetic algorithm setup
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

    pool = Pool()

    # Main function to run the genetic algorithm
    filepath = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\TDNetwork3.xlsx'
    filepathC = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\LCNetwork3.xlsx'

    demands, _ = read_excel_data(filepath)
    capacities,_ = read_segment_capacities(filepathC)

    G = create_graph()
    paths_dict = {key: generate_k_shortest_paths(G, *key) for key in demands.keys()}

    toolbox = setup_genetic_algorithm(demands, paths_dict)
    toolbox.register("map", pool.map)  # 将进程池的map注册到toolbox中以用于并行处理

    population = toolbox.population(n=300)
    NGEN = 20

    best_fitness = []
    all_generations_fitness = []
    all_best_path_info = []

    with pd.ExcelWriter('GP-Problem2-data'+datetime.now().strftime("%Y%m%d%H%M")+'.xlsx') as writer:
        for gen in range(NGEN):
            offspring = algorithms.varAnd(population, toolbox, cxpb=0.5, mutpb=0.2)
            fits = map(toolbox.evaluate, offspring)

            for fit, ind in zip(fits, offspring):
                ind.fitness.values = fit

            population = toolbox.select(offspring, k=len(population))
            best_individual = tools.selBest(population, k=1)[0]

            # Record best fitness
            best_fitness.append(best_individual.fitness.values[0])
            all_generations_fitness.append({'Generation': gen, 'Fitness': best_individual.fitness.values[0]})

            # Analyze path information for the best individual
            best_path_info = []
            individual = best_individual[:]
            for (source, target), paths in paths_dict.items():
                path_weights = np.array(individual[:len(paths)], dtype=float)
                individual = individual[len(paths):]
                normalized_weights = np.clip(path_weights, 0, 1)
                sum_weights = np.sum(path_weights)
                if sum_weights > 0:
                    normalized_weights = path_weights / sum_weights
                else:
                    normalized_weights = np.zeros_like(path_weights)

                for path_idx, path in enumerate(paths):
                    path_demand = demands[(source, target)] * normalized_weights[path_idx]
                    best_path_info.append({'Source': (source, target), 'Path': path, 'Assigned Demand': path_demand})
            
            # Save best individual path information for this generation
            df_best_path_info = pd.DataFrame(best_path_info)
            df_best_path_info.to_excel(writer, sheet_name=f'Best_Paths_Generation_{gen}', index=False)

        # Save fitness data
        df_all_generations_fitness = pd.DataFrame(all_generations_fitness)
        df_all_generations_fitness.to_excel(writer, sheet_name='All_Generations_Fitness', index=False)

    pool.close()  # 关闭进程池
    pool.join()  # 等待所有进程完成
    
    # Plot fitness over generations
#    plt.figure(figsize=(10, 5))
#    plt.plot(best_fitness, label='Best Fitness')
#    plt.title('Best Fitness Over Generations')
#    plt.xlabel('Generation')
#    plt.ylabel('Fitness')
#    plt.legend()
#    plt.grid(True)
#    plt.show()

    print("Analysis completed and data saved to Excel.")

if __name__ == "__main__":
    main()