#include "plansza.h"

#include <iostream>
#include <string>
using namespace std;

int Plansza::get_N()
{
	return N;
}

Plansza::Plansza(int rozmiar, int wygrana)
{
	R = wygrana;
	N = rozmiar;
	game = new char* [N];
	for (int i = 0; i < N; ++i)
	{
		game[i] = new char[N];
	}

	//Zerujemy zawartosc naszej tablicy
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			game[i][j] = ' ';

}


//jesli bool ma wartosc 1 to znaczy ze znaleziono wygrana. Podajemy aktualna pozycje
char Plansza::check_win() const
{
	int _lastrow = last_row;
	int _lastcolumn = last_column;
	char _lastplayer = last_player;
	
	
	//Inicjujemy jedynka poniewaz, element ktory wlasnie wstawilismy rowniez jest zliczany
	int licznik_wiersz = 1;
	int licznik_kolumna = 1;
	int licznik_po1skosie = 1;
	int licznik_po2skosie = 1;

	// Poziomo dwie petle zliczajace najpierw w gore potem w dol

	for (int i = _lastcolumn + 1; i < N && game[_lastrow][i] == _lastplayer; ++i)
		licznik_wiersz++;

	for (int i = _lastcolumn - 1; i >= 0 && game[_lastrow][i] == _lastplayer; --i)
		licznik_wiersz++;

	// Pionowo dwie petle zliczajace najpierw w gore potem w dol
	for (int i = _lastrow - 1; i >= 0 && game[i][_lastcolumn] == _lastplayer; --i)
		licznik_kolumna++;

	for (int i = _lastrow + 1; i < N && game[i][_lastcolumn] == _lastplayer; ++i)
		licznik_kolumna++;

	// Liczymy po skosie od prawego gornego rogu do lewego dolnego
	for (int i = _lastrow - 1, j = _lastcolumn + 1; i >= 0 && j < N
		&& game[i][j] == _lastplayer; --i, ++j)
	{
		licznik_po1skosie++;
	}

	for (int i = _lastrow + 1, j = _lastcolumn-1; i < N && j >= 0
		&& game[i][j] == _lastplayer; ++i, --j)
	{
		licznik_po1skosie++;
	}

	// Liczymy po skosie od lewego gornego rogu do prawego dolnego
	for (int i = _lastrow - 1, j = _lastcolumn - 1; i >= 0 && j >= 0
		&& game[i][j] == _lastplayer; --i, --j)
	{
		licznik_po2skosie++;
	}

	for (int i = _lastrow + 1, j = _lastcolumn + 1; i < N && j < N
		&& game[i][j] == _lastplayer; ++i, ++j)
	{
		licznik_po2skosie++;
	}

	//Jesli ktorys licznik jest wiekszy lub rowny liczbie pol w rzedzie R podanej przez uzytkownika to mamy wygrana danego gracza
	if (licznik_wiersz >= R || licznik_kolumna >= R
		|| licznik_po1skosie >= R || licznik_po2skosie >= R)
	{
		return _lastplayer;
	}
	else
	{
		return 'N'; // w takim wypadku nie ma wygranej, poniewaz zaden licznik nie wyniosl R
	}
   
}

//Funkcja remis szuka pustego pola na planszy. Jesli go znajdzie zwraca false, jesli nie zwraca true, czyli wystapienie remisu
char Plansza :: remis() const
{
	int licznik = 0;
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (game[i][j] == ' ')
			{
				++licznik;
				
			}
			
		}

	if (licznik == 0)
			{
			return 'D';
			}
	else if(licznik > 0)	
	{
		return 'N';
	}
}

//Funkcja ktora wstawia nam znak w podany wiersz i kolumne
void Plansza::insert(int w, int k, char _player)
{

	game[w][k] = _player;

	if (_player == 'x' || _player == 'o')
	{
		last_row = w;
		last_column = k;
		last_player = _player;
	}
}
Plansza::~Plansza()
{
	for (int i = 0; i < N; ++i)
	{
		delete[] game[i];
	}
	delete[] game;
}

void Plansza::display()
{
	string r = " ~~~";
	for (int i = 0; i < N; ++i)
	{

		cout << "| ";
		for (int j = 0; j < N; ++j)
			cout << game[i][j] << " | ";

		cout << endl;
		for (int k = 0; k < N; ++k)
			cout << r;
		cout << endl;

	}
}

char Plansza::check_game()
{

	char winner = check_win(); //zmienna zawiera kolko lub krzyzyk czyli wygranego
	char rem = remis();        //jesli jest 1 to mamy remis, jesli 0 to nie ma remisu

	if (winner == 'x' || winner == 'o')
		return winner;
	else if (rem == 'D')
		return rem;
	else        // brak remisu albo wygranej
		return 'N';

}

char Plansza::get_el(int w, int k)
{
	return game[w][k];
}