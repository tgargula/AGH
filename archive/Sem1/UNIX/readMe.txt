W folderze ./bin umieściłem skrypty w bashu, które napisałem w tym semestrze.

Niektóre z nich wymagają do poprawnego działania zmiany w plikach konfiguracyjnych
(to są te z rozszerzeniem *.config). Niektórych jednak do końca nie dopracowałem,
więc tam trzeba będzie zmienić kilka rzeczy w skrypcie, żeby działało.

Do każdego skryptu dodałem pomoc tj. krótkie wyjaśnienie konstrukcji skryptu
i za co odpowiadają poszczególne opcje.

Jeśli chcecie, żeby te skrypty działały u Was na Linuksie, to trzeba najpierw
utworzyć folder o nazwie ~/bin/ (ew. ~/.local/bin)* oraz skonfigurować
zmienną $PATH, co można zrobić dodając poniższy kawałek kodu do pliku ~/.bashrc

	# set PATH so it includes user's private bin if it exists
	if [[ ! `echo $PATH | grep $HOME/bin` ]] && [[ -d "$HOME/bin" ]]; then
		PATH="$PATH:$HOME/bin"
	fi

* - jeśli wolicie trzymać te skrypty w folderze ~/.local/bin, to trzeba odpowiednio
skonfigurować powyższy kod

(Skrypt "open" działa, gdy folder z tym skryptem znajduje się w zmiennej $PATH wcześniej
od folderu /bash/bin lub, gdy stworzy się dodatkowo alias o tej nazwie, który odnosi się
do tego skryptu. Jest to spowodowane tym, że istnieje komenda open w bashu,
jednak wg mnie jest 1) nie tak często używana, 2) istnieje dokładnie ta sama komenda
o nazwie openvt. Stwierdziłem więc, że przeciążę tę nazwę. Swoją drogą bardzo podobnie
do "mojego" skryptu open działa komenda xdg-open.)

Dodałem jeszcze plik .bash_aliases (plik ukryty) z aliasami. Żeby działały u Was,
trzeba ten plik umieścić w folderze domowym na Waszym Linuksie.

Jak macie jakieś pytania/pomysły, chcielibyście mnie poprawić w czymś (też w angielskim xd),
to piszcie.

Te skrypty pisałem bardziej dla zabawy :)

Miłego przeglądania!
