# Zadanie 2
#
# Proszę zaproponować algorytm, który na wejście dostaje tablicę
# n słów (być może o różnych długościach) i sortuje je w porządku
# słownikowym w czasie O(L), gdzie L to suma długości słów.
#
# Opis algorytmu:
#   Niech d będzie długością najdłuższego słowa, a n – liczbą stringów
#       w tablicy.
#
#   1) Dekrementujemy k od d-1 do 0 włącznie
#   2) Sortujemy tablicę stabilnym counting sortem po długości O(n)
#   3) Definiujemy iterator i, który wyznacza miejsce w tablicy, od którego będziemy sortować
#      (Stworzenie O(1), iteracja O(n))
#   4) Sortujemy część tablicę od i-tego miejsca do końca stabilnym counting sortem
#      według k-tej litery (czyli zmodyfikowany radix_sort do stringów)
#      Złożoność czasowa operacji: O(len(*część_do_posortowania*) dla każdego k) – łącznie O(L)
#   5) Nadpisujemy posortowaną część
#
# Uwagi:
#   1) ord() – funkcja ord() zwraca liczbę przypisaną do znaku w ASCII
#      (Niestety nie ma tak fajnie w tym przypadku jak w C/C++)
#   2) reversed() – funkcja po prostu odwracająca kolejność.
#      Przykład:
#      for i in range(n-1, -1, -1) to to samo co: for i in reversed(range(n)),
#      ale z reversed wygląda imho ładniej

LETTERS = ord('z') - ord('a') + 1

def counting_sort_by_length(A, d):
    n = len(A)
    B = [None] * n
    C = [0] * (d+1)
    for i in range(n): C[len(A[i])] += 1
    for i in range(1, d+1): C[i] += C[i-1]
    for i in range(n):
        C[len(A[i])] -= 1
        B[C[len(A[i])]] = A[i]
    A[:] = B

def counting_sort_by_letter(D, i):
    n = len(D)
    sorted_strings = [None] * n
    C = [0] * LETTERS
    for j in range(n): C [ ord(D[j][i]) - ord('a') ] += 1
    for j in range(1, LETTERS): C[j] += C[j-1]
    for j in reversed(range(n)):
        C [ ord(D[j][i]) - ord('a') ] -= 1
        sorted_strings [ C [ ord(D[j][i]) - ord('a') ] ] = D[j]
    return sorted_strings

def sort_strings (A):
    d = len(max(A, key=len))
    n = len(A)
    counting_sort_by_length(A, d)
    i = n
    for k in reversed(range(d)):
        while i > 0 and len(A[i-1]) > k: i -= 1
        A[i:] = counting_sort_by_letter(A[i:], k)

A = [
    "prosze",
    "zaproponowac",
    "algorytm",
    "ktory",
    "na",
    "wejscie",
    "dostaje",
    "tablice",
    "n",
    "slow"
]
    
print(A)
sort_strings(A)
print(A)

L = [
    'abc',
    'aba',
    'abd',
    'abb',
    'abcdefghijkl'
]

sort_strings(L)
print(L)