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
#   1) Dekrementujemy i od d-1 do 0 włącznie
#   2) Tworzymy tablicę dwóch tablic: w jednej pierwszej będziemy zapisywać
#      elementy, których długość jest mniejsza bądź równa i,
#      a w drugiej – resztę. Złożoność czasowa operacji: O(n) ( ≤ O(L) )
#   3) Sortujemy drugą tablicę stabilnym counting sortem według i-tej litery
#      (czyli zmodyfikowany radix_sort do stringów)
#      Złożoność czasowa operacji: O(len(split_tab[1]) dla każdego i)
#      – łącznie O(L)
#   4) Konkatenujemy obie tablice i nadpisujemy tablicę wejściową
#
# Uwagi:
#   1) ord() – funkcja ord() zwraca liczbę przypisaną do znaku w ASCII
#      (Niestety nie ma tak fajnie w tym przypadku jak w C/C++)
#   2) Zrobiłem split_tab w formie tablicy dwóch tablic, bo wydaje mi się
#      to czytelniejsze. Można również zrobić zwykłą tablicę, wpisywać
#      wartości od początku, jeśli nie sortujemy oraz od końca – jeśli
#      sortujemy. Potem sortować split_tab[k:], gdzie k to liczba
#      elementów, których nie sortujemy – ten sposób jest o tyle lepszy,
#      że nie trzeba konkatenować tablic.
#   3) Korzystam z tego, że może definiować funkcje wewnątrz funkcji
#      – oczywiście tak nie trzeba robić (ale osobiście wydaje mi się to
#      nieco czytelniejsze)
#   4) reversed() – funkcja po prostu odwracająca kolejność.
#      Przykład:
#      for i in range(n-1, -1, -1) to to samo co: for i in reversed(range(n)),
#      ale z reversed wygląda imho ładniej


def sort_strings (tab):

    def counting_sort (tab, i):
        n = len(tab)
        sorted_tab = [None] * n
        how_many_letters = ord('z') - ord('a') + 1
        temp_tab = [0] * how_many_letters

        for string in tab: temp_tab [ ord(string[i]) - ord('a') ] += 1

        for j in range(1, how_many_letters): temp_tab[j] += temp_tab[j-1]

        for string in reversed(tab):
            temp_tab [ ord(string[i]) - ord('a') ] -= 1
            sorted_tab [ temp_tab [ ord(string[i]) - ord('a') ] ] = string

        return sorted_tab

    
    def split_tab (tab, i):
        split_tab = [ [], [] ]
        for string in tab:
            if len(string) <= i: split_tab[0].append(string)
            else:                split_tab[1].append(string)
        
        return split_tab
    

    def concatenate_tab (tab1, tab2):
        tab = tab1
        tab.extend(tab2)
        return tab


    d = len(max(tab, key=len))
    n = len(tab)

    for i in reversed(range(d)):
        split_list = split_tab(tab, i)
        split_list[1] = counting_sort(split_list[1], i)
        tab = concatenate_tab(split_list[0], split_list[1])
    
    return tab



tab = [
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
    
print(tab)

tab = sort_strings(tab)

print(tab)


L = [
    'abc',
    'aba',
    'abd',
    'abb',
    'abcdefghijkl'
]

L = sort_strings(L)

print(L)