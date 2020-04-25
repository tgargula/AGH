inf = float("Inf")

def sorting(x):               # tworzenie klucza do sortowania
    if x[1] == 0: return inf  # nie dziel przez 0 dla nieważkich płynów; takie płyny są nieskończenie wartościowe w stosunku do swojej masy
    return x[0]/x[1]

def knapsack(A, k):
    w = 0.0
    v = 0.0
    A.sort(key = sorting, reverse = True)
    for x in A:
        if w + x[1] <= k:
            w += x[1]
            v += x[0]
        else:
            v += (k - w) * x[0] / x[1]
            w = k
    return A, v
    
print( knapsack( [ (1,1), (10,2), (6,3), (3, 0) ], 3 ))