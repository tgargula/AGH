# PROGRAMOWANIE
**Nasze kody na WDI i MD** :heart:

## Zasada nazywania plików
Egzekwowane od zestawu nr 4 
c[numer_zestawu]z[numer_zadania]{f,k,m,s,t}.[rozszerzenie]

Przykład: zadanie 2 z zestawu 4 zrobione przez Szymona w C++ powinno mieć nazwę: c04z02s.cpp

## Potrzebne oprogramowanie
* [VS Code](https://code.visualstudio.com/download)
* [Git](https://git-scm.com/downloads)

## Potrzebne komendy 

### Git Bash (lub terminal dla Linux)
```sh
$ git status #status wprowadzonych zmian; branch na, na którym aktualnie jesteśmy; ...
$ git clone https://github.com/mrrys00/WDI.git #pobieranie repozytorium
$ git checkout *branchName* #zmień edytowany branch
$ git checkout -b *branchName* #dodaj branch
$ git add [--all] #dodajemy pliki - wybieramy które lub wszystkie
$ git commit -m "description" #opisujemy którko wprowadzone zmiany - po polsku lub angielsku jak, kto woli
$ git push origin *branchName* #wysyłamy zmiany na GitHub
$ git pull #pobierz ostatnią wersję repozytorium
$ git merge #zrób merge branchy
```

[więcej poleceń](https://rogerdudler.github.io/git-guide/index.pl.html)

### VS Code
```sh 
$ code . #otwórz VS Code
$ g++ Cwiczenia4/c04z02s.cpp -o Cwiczenia4/c04z02s.out #skompiluj plik c04z02s.cpp do pliku c04z02s.out
$ ./Cwiczenia4/c04z02s.out #odpal plik zeby go sprawdzic - nie jestem pewny czy tak to ma wygladac :)
```

## Zalecany scenariusz korzystania

*Hint. Warto znać swoje login i hasło na Github*
*Hint2. Github i Git czasem działać inaczej niż opisałem - wtedy ratuje nas umiejętność czytania i myślenia*

### Pierwsze pobieranie

1. Git otwieramy w folderze do którego chcemy skopiować nasze repozytorium.
* Linux - wchodzimy terminalem do docelowego folderu
* Windows - wchodzimy do docelowego folderu, klikamy w folderze prawy klawisz myszy i wybieramy Git Bash Here (lub coś takiego)

2. Pobieramy nasze repozytorium poleceniem ```$ git clone *URL*```

3. Zmieniamy branch na inny niż master - ```$ git checkout *branchName*``` (lub tworzymy nowy branch w przypadku gdy takiego niema ```$ git checkout -b *branchName*```)

### Update istniejącego lokalnie repo

1. (tak samo jak wyżej)

2. Aktualizujemy repozytorium używając ```$ git pull``` 

3. Przechodzimy na inny niż master branch ```$ git checkout *branchName*``` (lub tworzymy nowy branch w przypadku gdy takiego niema ```$ git checkout -b *branchName*``` i w tym scenariuszu to koniec zabawy)

4. Branch, na którego przeszliśmy musimy **bezstratnie** (dla nas i dla wersji pobranej) scalić z pobranymi zmianami. GitHub zapisuje pobrane zmiany w branchu origin/*branchName* a my mamy nasze ewentualne lokalne zmiany na branchu *branchName*. Scalamy je ze sobą poleceniem ```$ git merge origin/*branchName*```.  :exclamation: Nie bawić się z tym na branchu master  :exclamation:

### Wysyłanie zmian na GitHub

*Hint. Przed wysłaniem warto upewnić się czy ktoś nie dodał swoich zmian na Github żeby nie usunąć jego zmian. Jeśli nie mamy najnowszej wersji trzeba zrobić Update repo opisany powyżej*

1. Dodajemy nasze ostatnie zmiany do repozytorium poleceniem ```$ git add [--all]``` (wybieramy pliki lub dodajemy wszystkie)

2. Opisujemy zmiany ```$ git commit -m "description"``` 

3. Wysyłamy nasze repozytorium na branch inny niż master ```$ git push origin *branchName*``` (ostatni taki branch nazywa się "toCoding")

## Dodatkowe informacje

* pliki z rozszerzeniami .exe, .out, .app, ... (są zapisane w pliku [.gitignore](https://github.com/mrrys00/WDI/blob/master/.gitignore)) nie są wysyłane do repozytorium żeby nie robić śmietnika
* od czasu do czasu trzeba będzie zrobić merge *branch* -> master - będziemy się umawiać kiedy
* **UWAGA!** jeśli ktoś robi coś na github w tym samym czasie co my to musimy ustalić kto pierwszy dodaje swoje zmiany (w przypadku dodawanie poleceniem *git push* - druga osoba musi wtedy pobrać repozytorium ze zmianami, dodać swoje zmiany i wysłać na GitHub
* jest opcja dodawania przez stronę internetową *jak ktoś umie niech napisze jak się to robi :smile: *

#### Fajne tutoriale edycji tego pliku .md
* https://dillinger.io/
* https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax
* https://www.webfx.com/tools/emoji-cheat-sheet/
