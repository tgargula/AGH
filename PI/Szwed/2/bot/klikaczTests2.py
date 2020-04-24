from selenium import webdriver
import time

username = ""
password = ""
firefoxWebdriver = webdriver.Firefox("./firefoxDriver")
firefoxWebdriver.maximize_window()

# Logowanie
firefoxWebdriver.get("https://upel2.cel.agh.edu.pl/wiet/login/index.php")
firefoxWebdriver.find_element_by_id("username").send_keys(username)
firefoxWebdriver.find_element_by_id("password").send_keys(password)
firefoxWebdriver.find_element_by_id("loginbtn").click()

time.sleep(3)

# Wejdź w kurs
firefoxWebdriver.find_element_by_id("accept-cookies-checkbox").click()
firefoxWebdriver.find_element_by_link_text("Programowanie Imperatywne Wykład").click()
time.sleep(1)
# Wejdź w test 2
# firefoxWebdriver.find_element_by_id("accept-cookies-checkbox").click()
firefoxWebdriver.find_element_by_xpath('//span[contains(text(), "Test 2")]').click()

# Rozpocznij nowy lub kontynuuj rozpoczęty lub potwórz
if len(firefoxWebdriver.find_elements_by_xpath('//button[text()="Spróbuj teraz rozwiązać test"]')) is not 0:
    firefoxWebdriver.find_element_by_xpath('//button[text()="Spróbuj teraz rozwiązać test"]').click()
    firefoxWebdriver.find_element_by_id("id_submitbutton").click()
elif len(firefoxWebdriver.find_elements_by_xpath('//button[text()="Ponownie rozwiąż quiz"]')) is not 0:
    firefoxWebdriver.find_element_by_xpath('//button[text()="Ponownie rozwiąż quiz"]').click()
    firefoxWebdriver.find_element_by_id("id_submitbutton").click()
else: 
    firefoxWebdriver.find_element_by_xpath('//button[text()="Kontynuuj ostatnie podejście"]').click()

time.sleep(2)

# Pytanie 1
firefoxWebdriver.find_element_by_xpath('//label[text()="Rozpoczyna się od funkcji main()"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 2
firefoxWebdriver.find_element_by_xpath('//label[text()="Adres wskazany w wywołaniu "]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Wartość rejestru SP (stack pointer) ulega zmianie, ponieważ na stosie umieszczany jest co najmniej adres powrotu."]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 3
firefoxWebdriver.find_element_by_xpath('//label[text()=". Adres powrotu jest przechowywany w na stosie. Po wykonaniu tego rozkazu adres ze stosu jest ładowany do rejestru IP (instruction pointer) oraz usuwany ze stosu."]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 4
firefoxWebdriver.find_element_by_xpath('//label[text()="Adres powrotu"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Pamięć dla argumentów wywołania funkcji"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Pamięć dla zmiennych zadeklarowanych lokalnie, wewnątrz funkcji"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 5
firefoxWebdriver.find_element_by_xpath('//label[text()="Na stosie. Rozmiar stosu może zostać zwiększony przez zastosowanie specyficznych opcji kompilacji i konsolidacji."]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 6
firefoxWebdriver.find_element_by_xpath('//label[text()="Prototyp funkcji informuje kompilator o typie zwracanej wartości"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Prototyp funkcji informuje kompilator, jak nazywa się funkcja i jakiego typu są jej parametry"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 7
firefoxWebdriver.find_element_by_xpath('//label[text()="Zmiana wartości zewnętrznych obiektów istniejących poza funkcją jest efektem ubocznym"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Funkcja void swap(int*a,int*b) dokonująca wymiany wartości pomiędzy zmiennymi wskazanymi przez a i b  wywołuje efekt uboczny"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 8
firefoxWebdriver.find_element_by_xpath('//label[text()="Funkcje rekurencyjne to funkcje, które wołają same  siebie bezpośrednio."]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Nie jest możliwa nieskończona rekurencja. Ramki wywołań funkcji odkładane są na stosie i przy zbyt dużej liczbie wywołań stos zostanie wyczerpany."]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Jeżeli w funkcji f() znajduje się wywołanie g(), a w g() wywołanie f(), to funkcja f() jest również funkcją rekurencyjną"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 9
firefoxWebdriver.find_element_by_xpath('//label[text()="Maksymalny rozmiar stosu zajętego przez podmacierze b jest równy (1+2"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Dla n=10 maksymalna głębokość rekurencji (liczba ramek funkcji na stosie) wyniesie 10"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 10
firefoxWebdriver.find_element_by_xpath('//label[text()="Sumaryczna liczba S(n) wywołań funkcji rośnie szybciej, niż n!"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Sumaryczna liczba S(n) wywołań funkcji det wynosi S(n)=1+n*S(n-1)"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 11
firefoxWebdriver.find_element_by_xpath('//label[text()=" jest poprawna, ale niepoprawna jest instrukcja "]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 12
firefoxWebdriver.find_element_by_xpath('//label[text()="Instrukcja //1 wypisze tę samą liczbę, niezależnie od rozmiaru tablicy"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Instrukcja //3 nie zostanie skompilowana, ponieważ rozmiar tablicy tab1 jest nieznany"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Instrukcja //5 wypisze 23"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 13
firefoxWebdriver.find_element_by_xpath('//label[text()="Do funkcji dcompare() przekazywane są adresy pierwszych elementów tablic a i b. Te adresy umieszczane są na stosie"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Instrukcja //1 zwróci 0"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Wykonanie instrukcji //2 może wygenerować błąd, ale tak się prawdopodobnie nie stanie, ponieważ obszar zajmowany przez zmienne lokalne jest mniejszy niż rozmiar stosu."]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="Wynik instrukcji //3 jest nieokreślony, ponieważ w porównywaniu używany jest element poza tablicą a"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 14
firefoxWebdriver.find_element_by_xpath('//label[text()="//1"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="//3"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="//4"]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()="//5 nie wiadomo co się wydrukuje"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 15
firefoxWebdriver.find_element_by_xpath('//label[text()=" nie zostanie automatycznie zwolniona. Aby ją zwolnić musimy użyć "]').click()
firefoxWebdriver.find_element_by_xpath('//label[text()=" zostanie automatycznie zwolniona w momencie wyjścia z funkcji"]').click()
# firefoxWebdriver.find_element_by_xpath('//label[text()=" zapewnia kontrolę nad powodzeniem przydziału pamięci w czasie działania programu."]').click()
print("""
Dopisać, że drugą odpowiedź, że tab_malloc zapewnia kontrolę
""")
time.sleep(20)
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 16
firefoxWebdriver.find_element_by_xpath('//label[text()="24 16 16"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 17
firefoxWebdriver.find_element_by_xpath('//label[text()="24 bajty"]').click()
firefoxWebdriver.find_element_by_css_selector(".mod_quiz-next-nav").click()
time.sleep(1)

# Pytanie 18
print(f"""
AAAAAAAAAAA
Czlowieku
wpisuj sam odpowiedz ktora brzmi
AAA: i_am_int BBB: i_am_double CCC: printf("%s",v.sval)
Masz na to 3 minuty - pozniej test sie zamyka""")
time.sleep(20)
# firefoxWebdriver.find_element_by_xpath(f'//label[contains(text(), "AAA: i_am_int BBB: i_am_double CCC: printf("%s",v.sval)"]').click()
firefoxWebdriver.find_element_by_xpath('//input[@value="Zapisz podejście ..."]').click()
time.sleep(1)

# KONIEC
firefoxWebdriver.find_element_by_xpath('//button[text()="Zatwierdź wszystkie i zakończ"]').click()
# firefoxWebdriver.find_element_by_xpath('//input[@value="Zatwierdź wszystkie i zakończ"]').click()

time.sleep(15)
# firefoxWebdriver.close()
