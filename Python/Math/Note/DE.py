import numpy as np

def de(fobj, bounds, mut=0.8, crossp=0.7, popsize=20, its=1000):
    dimensions = len(bounds)
    pop = np.random.rand(popsize, dimensions)
    min_b, max_b = np.asarray(bounds).T
    diff = np.fabs(min_b - max_b)
    pop_denorm = min_b + pop * diff
    fitness = np.asarray([fobj(ind) for ind in pop_denorm])
    best_idx = np.argmin(fitness)
    best = pop_denorm[best_idx]
    for i in range(its):
        for j in range(popsize):
            idxs = [idx for idx in range(popsize) if idx != j]
            a, b, c = pop[np.random.choice(idxs, 3, replace = False)]
            mutant = np.clip(a + mut * (b - c), 0, 1)
            cross_points = np.random.rand(dimensions) < crossp
            if not np.any(cross_points):
                cross_points[np.random.randint(0, dimensions)] = True
            trial = np.where(cross_points, mutant, pop[j])
            trial_denorm = min_b + trial * diff
            f = fobj(trial_denorm)
            if f < fitness[j]:
                fitness[j] = f
                pop[j] = trial
                if f < fitness[best_idx]:
                    best_idx = j
                    best = trial_denorm
        yield best, fitness[best_idx]

def fobj(variables):
    x,y,z,t = variables
    return [
            (((0.241-x)*111263)**2+((0.204-y)*97304)**2+(824-z)**2-(340*(100.767-t))**2 +

             ((0.780-x)*111263)**2+((0.456-y)*97304)**2+(727-z)**2-(340*(112.220-t))**2 +

             ((0.712-x)*111263)**2+((0.785-y)*97304)**2+(742-z)**2-(340*(188.020-t))**2 +

             ((0.047-x)*111263)**2+((0.121-y)*97304)**2+(575-z)**2-(340*(163.024-t))**2   )
]

bounds = [(-50, 50), (-50, 50), (10, 10000000), (-20, 100)]

result = list(de(fobj,bounds))
print(result[-1])