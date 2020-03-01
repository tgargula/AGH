def selectionSort (tab):
    N = len(tab)
    indeks = 0
    for i in range(N-1):
        indeks = i
        mini = tab[i]
        acct = tab[i]
        for j in range (i+1, N):
            if tab[j] < mini:
                mini = tab[j]
                indeks = j
            if j == N-1 and mini != indeks:
                tab[i] = mini
                tab[indeks] = acct
    return tab


size = int(input())
t = []

for i in range(size):
    t.append(int(input()))

tab = selectionSort(t)

print(tab)
