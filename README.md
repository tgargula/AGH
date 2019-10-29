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
$ git checkout -b *beakchName* #dodaj branch
$ git add [--all] #dodajemy pliki - wybieramy które lub wszystkie
$ git commit -m "description" #opisujemy którko wprowadzone zmiany - po polsku lub angielsku jak, kto woli
$ git push origin *branchName* #wysyłamy zmiany na GitHub
```

## Zalecany scenariusz korzystania

1. Git otwieramy w folderze do którego chcemy skopiować nasze repozytorium.
* Linux - wchodzimy terminalem do docelowego folderu
* Windows - wchodzimy do docelowego folderu, klikamy w folderze prawy klawisz myszy i wybieramy Git Bash Here (lub coś takiego)
*hint. ja (Szymon) nazwałem swój folder docelowy WDI_lokalne aby odróżnić go od pobranego repozytorium czyli WDI*

2. Pobieramy nasze repozytorium

3. Zmieniamy branch na inny niż master

4. Dodajemy nasze ostatnie zmiany do repozytorium

5. Wysyłamy nasze repozytorium na branch inny niż master (ostatni taki branch nazywa się "jakiegokolwiek")
*hint. po wysłaniu zmian na GitHub polecam usunąć repozytorium z komputera żeby się nie myliło*

#### Fajne tutoriale edycji tego pliku .md
* https://dillinger.io/
* https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax
* https://www.webfx.com/tools/emoji-cheat-sheet/
