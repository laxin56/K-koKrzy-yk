#include "G_AI.h"
#include "gra.h"
#include "plansza.h"
#include <iostream>

using namespace std;

void graczVSkomputer(int n, int r)
{
	int w, k;
	Plansza plansza(n, r); // obiekt plansza
	SI przeciwnik;         // obiekt SI
	/***************
	Uwaga!
	DANA GLEBOKOSC ZAPEWNIA OPTYMALNY CZAS ALGORYTMU I POPRAWNE DZIALANIE DLA PLANSZY 4x4 i 3x3. DLA WIEKSZYCH MUSI ULEC ZMIANIE
	****************/
	przeciwnik.set_depth(8);

	cout << "-------------------OPCJA DLA GRACZ VS KOMPUTER---------------------------" << endl;
	plansza.display();
	while (1)
	{
		cout << endl << "Podaj w ktory wiersz i kolumne chcesz wstawic krzyzyk" << endl;
		cout << "Wiersz:";
		cin >> w;
		cout << "Kolumna:";
		cin >> k;
		cout << endl;
		while (plansza.get_el(w - 1, k - 1) != ' ')
		{
			cout << "To miejsce jest pelne! Wybierz inne miejsce" << endl;
			cout << endl << "Podaj w ktory wiersz i kolumne chcesz wstawic krzyzyk" << endl;
			cout << "Wiersz:";
			cin >> w;
			cout << "Kolumna:";
			cin >> k;
			cout << endl;
		}
		plansza.insert(w - 1, k - 1, 'x');
		plansza.display();
		char xwin = plansza.check_game();
		if (xwin == 'x')
		{
			cout << "-----Wygral Gracz!-----" << endl;
			break;
		}
		else if (xwin == 'D')
		{
			cout << "-----Mamy remis!-----" << endl;
			break;
		}

		cout << "---------- TURA KOMPUTERA -----------" << endl;
		cout << endl;
		przeciwnik.SI_Turn(plansza, 'o');
		plansza.display();
		char owin = plansza.check_game();
		if (owin == 'o')
		{
			cout << "-----Zwyciezyl Komputer!-----" << endl;
			break;
		}
		else if (owin == 'D')
		{
			cout << "-----Mamy remis!-----" << endl;
			break;
		}
	}
}

void graczVSgracz(int n, int r)
{
	int w, k;
	Plansza plansza(n, r);
	cout << "-----------------OPCJA DLA DWOCH GRACZY-------------------" << endl;
	plansza.display();
	while (1)
	{

		cout << endl << "Podaj w ktory wiersz i kolumne chcesz wstawic krzyzyk" << endl;
		cout << "Wiersz:";
		cin >> w;
		cout << "Kolumna:";
		cin >> k;
		cout << endl;

		while (plansza.get_el(w - 1, k - 1) != ' ')
		{
			cout << "To miejsce jest pelne! Wybierz inne miejsce" << endl;
			cout << endl << "Podaj w ktory wiersz i kolumne chcesz wstawic krzyzyk" << endl;
			cout << "Wiersz:";
			cin >> w;
			cout << "Kolumna:";
			cin >> k;
			cout << endl;
		}
		plansza.insert(w - 1, k - 1, 'x');
		plansza.display();
		char xwin = plansza.check_game();
		if (xwin == 'x')
		{
			cout << "-----Wygral Gracz Operujacy X!-----" << endl;
			break;
		}
		else if (xwin == 'D')
		{
			cout << "-----Mamy remis!-----" << endl;
			break;
		}
		cout << endl << "Podaj w ktora kolumne i wiersz chcesz wstawic kolko" << endl;
		cout << "Wiersz:";
		cin >> w;
		cout << "Kolumna:";
		cin >> k;
		cout << endl;
		while (plansza.get_el(w - 1, k - 1) != ' ')
		{
			cout << "To miejsce jest pelne! Wybierz inne miejsce" << endl;
			cout << endl << "Podaj w ktory wiersz i kolumne chcesz wstawic kolko" << endl;
			cout << "Wiersz:";
			cin >> w;
			cout << "Kolumna:";
			cin >> k;
			cout << endl;
		}
		plansza.insert(w - 1, k - 1, 'o');
		plansza.display();
		char owin = plansza.check_game();
		if (owin == 'o')
		{
			cout << "-----Wygral Gracz Operujacy O!-----" << endl;
			break;
		}
		else if (owin == 'D')
		{
			cout << "-----Mamy remis!-----" << endl;
			break;
		}
	}
}
