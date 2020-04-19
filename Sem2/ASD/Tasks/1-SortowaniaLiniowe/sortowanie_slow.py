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
#   2) Tworzymy nową tablicę w której zapisujemy elementy od lewej, jeśli 
#      będziemy sortować ten wyraz oraz od prawej, jeśli nie będziemy go sortować
#      Złożoność czasowa operacji: O(n) ( ≤ O(L) )
#   3) Sortujemy część tablicy "do posortowania" stabilnym counting sortem według i-tej litery
#      (czyli zmodyfikowany radix_sort do stringów)
#      Złożoność czasowa operacji: O(len(*część_do_posortowania*) dla każdego k)
#      – łącznie O(L)
#   4) Konkatenujemy obie tablice i nadpisujemy tablicę wejściową
#
# Uwagi:
#   1) ord() – funkcja ord() zwraca liczbę przypisaną do znaku w ASCII
#      (Niestety nie ma tak fajnie w tym przypadku jak w C/C++)
#   2) Korzystam z tego, że może definiować funkcje wewnątrz funkcji
#      – oczywiście tak nie trzeba robić (ale osobiście wydaje mi się to
#      nieco czytelniejsze)
#   3) reversed() – funkcja po prostu odwracająca kolejność.
#      Przykład:
#      for i in range(n-1, -1, -1) to to samo co: for i in reversed(range(n)),
#      ale z reversed wygląda imho ładniej

how_many_letters = ord('z') - ord('a') + 1

def sort_strings (A):

    def counting_sort (B, i):
        n = len(B)
        sorted_strings = [None] * n
        temp = [0] * how_many_letters

        for string in B: temp [ ord(string[i]) - ord('a') ] += 1

        for j in range(1, how_many_letters): temp[j] += temp[j-1]

        for string in B:
            temp [ ord(string[i]) - ord('a') ] -= 1
            sorted_strings [ temp [ ord(string[i]) - ord('a') ] ] = string
        
        return sorted_strings


    d = len(max(A, key=len))
    n = len(A)

    for k in reversed(range(d)):
        temp = [None] * n
        i = 0; j = n
        for string in A:
            if len(string) > k:
                temp[i] = string
                i += 1
            else:
                j -= 1
                temp[j] = string

        sorted_strings = counting_sort(temp[:i], k)
        sorted_strings.extend(temp[i:])
        A = sorted_strings[:]

    return A



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

A = sort_strings(A)

print(A)


L = [
    'abc',
    'aba',
    'abd',
    'abb',
    'abcdefghijkl'
]

L = sort_strings(L)

print(L)