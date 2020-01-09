#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

void Finder(int values, int indexes, int pos, int chosen, int* minimal_chosen_value, int* minimal_chosen, int Tab[], int Tab_length)
{
	if (pos == Tab_length) // Jeśli doszliśmy do końca tablicy
	{
		if (values == indexes && chosen > 0 && values > 0) // a nasz podzbiór spełnia warunki zadania (values > 0, bo zabezpieczamy się przed cwanym wybraniem tylko nicnieznaczącego zera)
		{
		//	printf("Match for values = indexes = %d, %d chosen\n", values, chosen); to jest bajer
			if (*minimal_chosen > chosen) // oraz wybraliśmy mniej liczb niż kiedykolwiek
			{
				*minimal_chosen = chosen; // zapisujemy ile liczb udało nam się wybrać
				*minimal_chosen_value = values; // zapisujemy sumę podzbioru
			}
		}
		return;
	}
	else
	{
		Finder(values, indexes, pos + 1, chosen, minimal_chosen_value, minimal_chosen, Tab, Tab_length); // Sprawdzam co by było, gdybym nie brał aktualnego elementu
		Finder(values + (Tab[pos]), indexes + pos, pos + 1, chosen + 1, minimal_chosen_value, minimal_chosen, Tab, Tab_length); // Sprawdzam co by było, gdybym wziął aktualny element
	}
}

int minimal_chosen(int Tab[], int Tab_length)
{
	int minimal_chosen = Tab_length + 1; // Na pewno więcej niż długość tablicy nie wybierzemy
	int minimal_chosen_value = 0; // Byle co, to używamy jako zmienną do zwracania
	Finder(0, 0, 0, 0, &minimal_chosen_value, &minimal_chosen, Tab, Tab_length);
	return minimal_chosen_value; // Zwracamy co funkcja zwróciła
}

int main()
{
	int Tab[] = { 0,7,3,5,11,2,7,23,12,10 };
	int Tab_length = 10;

	cout << minimal_chosen(Tab, Tab_length);

	return 0;
}