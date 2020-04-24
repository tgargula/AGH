def sorting(val):               # tworzenie klucza do sortowania
    if val[1] == 0: return 586679842985647    # nie dziel przez 0 dla nieważkich płyn; takie płyny są nieskończenie wartościowe w stosunku do swojej masy
    return val[0]/val[1]

def knapsack(A, k):
    A.sort(key = sorting, reverse = True)
    currentWeight = 0.0
    currentValue = 0.0
    for i in A:
        if currentWeight + i[1] <= k:
            currentWeight += i[1]
            currentValue += i[0]
        else:
            currentValue += (k - currentWeight) * i[0] / i[1]
            currentWeight = k

    return A, currentValue
    
print( knapsack( [ (1,1), (10,2), (6,3) ], 3 ))