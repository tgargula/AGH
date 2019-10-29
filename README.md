# WDI
**Nasze kody na WDI** :heart:

## Zasada nazywania plików
Egzekwowane od zestawu nr 4 
c[numer_zestawu]z[numer_zadania]{m,s,t}.[rozszerzenie]

Przykład: zadanie 2 z zestawu 4 zrobione przez Szymona w C++ powinno mieć nazwę: c04z02s.cpp

## Potrzebne oprogramowanie
* [VS Code](https://code.visualstudio.com/download)
* [Git](https://git-scm.com/downloads)

## Potrzebne komendy 

### Git (lub terminal dla Linux)
```sh
$ git status #status wprowadzonych zmian; branch na, na którym aktualnie jesteśmy; ...
$ git clone https://github.com/mrrys00/WDI.git #pobieranie repozytorium
$ git checkout *branchName* #zmień edytowany branch
$ git checkout -b *branchName* #dodaj branch
$ code . #otwórz VS Code
$ git add [--all] #dodajemy pliki - wybieramy które lub wszystkie
$ git commit -m "description" #opisujemy którko wprowadzone zmiany - po polsku lub angielsku jak, kto woli
$ git push origin *branchName* #wysyłamy zmiany na GitHub
$ git pull #pobierz ostatnią wersję repozytorium
```

### VS Code
```sh 
$ g++ Cwiczenia4/c04z02s.cpp -o Cwiczenia4/c04z02s.out #skompiluj plik c04z02s.cpp do pliku c04z02s.out
$ ./Cwiczenia4/c04z02s.out #odpal plik zeby go sprawdzic - nie jestem pewny czy tak to ma wygladac :)
```

## Zalecany scenariusz korzystania

1a. Git otwieramy w folderze do którego chcemy skopiować nasze repozytorium.
* Linux - wchodzimy terminalem do docelowego folderu
* Windows - wchodzimy do docelowego folderu, klikamy w folderze prawy klawisz myszy i wybieramy Git Bash Here (lub coś takiego)
*hint. ja (Szymon) nazwałem swój folder docelowy WDI_lokalne aby odróżnić go od pobranego repozytorium czyli WDI*
1b. Robimy pull repozytorium jeżeli mamy je na komputerze

2. Pobieramy nasze repozytorium

3. Zmieniamy branch na inny niż master

4. Dodajemy nasze ostatnie zmiany do repozytorium

5. Wysyłamy nasze repozytorium na branch inny niż master (ostatni taki branch nazywa się "jakiegokolwiek")

## Dodatkowe informacje

* pliki z rozszerzeniami .exe, .out, .app, ... (są zapisane w pliku [.gitignore](https://github.com/mrrys00/WDI/blob/master/.gitignore)) nie są wysyłane do repozytorium żeby nie robić śmietnika
* od czasu do czasu trzeba będzie zrobić merge *branch* -> master - będziemy się umawiać kiedy
* **UWAGA!** jeśli ktoś robi coś na github w tym samym czasie co my to musimy ustalić kto pierwszy dodaje swoje zmiany (w przypadku dodawanie poleceniem *git push* - druga osoba musi wtedy pobrać repozytorium ze zmianami, dodać swoje zmiany i wysłać na GitHub
* jest opcja dodawania przez stronę internetową *jak ktoś umie niech napisze jak się to robi :smile: *

#### Fajne tutoriale edycji tego pliku .md
* https://dillinger.io/
* https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax
* https://www.webfx.com/tools/emoji-cheat-sheet/
