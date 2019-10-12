#include "G_AI.h"
#include "plansza.h"
#include <vector>
#include <iostream>

using namespace std;

SI::SI()
{
}

SI::~SI()
{
}

char SI :: get_Human() const 
{
	return Human;
}

char SI :: get_AI() const
{
	return AI;
}

void SI :: set_depth(int _depth)
{
	depth = _depth;
}


int SI::min_max(Plansza& plansza, char player, int _depth, int alfa, int beta)
{
	//kontrolujemy glebokosc, jesli zejdzie do zera, wtedy zwracamy punkty jak za remis
	
	//sprawdzamy wygrana lub remis
	char w = plansza.check_game();
	
	if (w == AI) {
		return 10; //zwracamy 10 punktow bo wygral komputer
	}
	else if(w == Human)
	{
		return -10; // zwracamy -10 punktow bo wygral czlowiek, a nie komputer
	}
	else if(w == 'D')
	{
		return 0;   // zwracamy zero bo jest remis
	}

	if (_depth == 0)
	{
		return 0;
	}

	if (player == AI)
	{
		int Max = -100000000;
		for (int i = 0; i < plansza.get_N(); ++i)
			for (int j = 0; j < plansza.get_N(); ++j)
			{
				if (plansza.get_el(i, j) == ' ')
				{

					plansza.insert(i, j, player);
					int cd = min_max(plansza, Human, _depth - 1,alfa,beta);
					plansza.insert(i, j, ' ');
					if (cd > Max)
					{
						Max = cd;
					}
					
					if (Max > alfa)
					{
						alfa = Max;
					}
					
					if (beta <= alfa)
					{
						break;
					}
				}
			}
		return Max;
	}
	else
	{
		int Max = 100000000;
		for (int i = 0; i < plansza.get_N(); ++i)
			for (int j = 0; j < plansza.get_N(); ++j)
			{
				if (plansza.get_el(i, j) == ' ')
				{
					plansza.insert(i, j, player);
					int cd = min_max(plansza, AI, _depth - 1,alfa,beta);
					plansza.insert(i, j, ' ');
					if (cd < Max)
					{
						Max = cd;
					}

					if (Max < beta)
					{
						beta = Max;
					}

					if (beta <= alfa)
					{
						break;
					}
				}
			}
		return Max;
	}
		
}

// funkcja ktora na podstawie algorytmu min_max wykonuje nam ruch
void SI::SI_Turn(Plansza& plansza, char player)
{
	int max = -100000000, win =0;
	AIRUCH BEST;
	for (int i = 0; i < plansza.get_N(); ++i)
		for (int j = 0; j < plansza.get_N(); ++j)
		{
			if (plansza.get_el(i, j) == ' ')
			{
			plansza.insert(i, j, player);
			win = min_max(plansza, Human, depth, -100000000 , 100000000);
			plansza.insert(i, j, ' ');
			if (win > max)
			{
				max = win;
				BEST.row = i;
				BEST.column = j;
			}
		}
}
	
	plansza.insert(BEST.row, BEST.column, AI);
	
}
/*
AIRUCH SI::min_max(Plansza& plansza, char player, int _depth)
{
	//kontrolujemy glebokosc, jesli zejdzie do zera, wtedy zwracamy punkty jak za remis
	if (_depth == 0)
	{
		return AIRUCH(0);
	}

	//sprawdzamy wygrana lub remis
	char w = plansza.check_game();

	if (w == AI) {
		return AIRUCH(10); //zwracamy 10 punktow bo wygral komputer
	}
	else if (w == Human)
	{
		return AIRUCH(-10); // zwracamy -10 punktow bo wygral czlowiek, a nie komputer
	}
	else if (w == 'D')
	{
		return AIRUCH(0);   // zwracamy zero bo jest remis
	}

	// jesli nic nie zwrocilo to wchodzimy dalej i uzywamy rekurencji

	//Tworzymy vector zebby przechowywac nasze punkty za dany ruch

	std::vector<AIRUCH> punkty;

	for (int i = 0; i < plansza.get_N(); ++i)
		for (int j = 0; j < plansza.get_N(); ++j)
		{

			// jesli dany element jest pusty
			if (plansza.get_el(i, j) == ' ')
			{
				AIRUCH ruch;

				//przypisujemy wiersz i kolumne do naszego obiektu tak aby potem go uzyc
				ruch.row = i;
				ruch.column = j;

				//w puste miejsce przypisujemy tego dla ktorego szukamy najlepszego algorytmu. Bedzie sie to odbywac naprzemiennie w kolejnych wywolaniach rekurencji
				plansza.insert(i, j, player);

				if (player == AI)
				{
					//Przypisujemy teraz odpowiednie ilosci punktow naprzemiennie dla gracza i komputera
					//Oraz zmienjszamy zadana glebokosc tak aby algorytm nie trwal za dlugo
					ruch.score = min_max(plansza, Human, _depth - 1).score;
				}
				else
				{
					ruch.score = min_max(plansza, AI, _depth - 1).score;
				}

				punkty.push_back(ruch);
				//wstawiamy z powrotem pusty znak
				plansza.insert(i, j, ' ');
			}
		}

	int Naj_Ruch;
	//jesli konczymy SI to wtedy szukamy maksymalnej wartosci punktow
	if (player == AI)
	{
		int Max = -100000000;
		for (int i = 0; i < punkty.size(); ++i)
		{
			if (punkty[i].score > Max)
			{
				Naj_Ruch = i;
				Max = punkty[i].score;
			}
		}
	}
	else
	{
		int Max = 100000000;
		for (int i = 0; i < punkty.size(); ++i)
		{
			if (punkty[i].score < Max)
			{
				Naj_Ruch = i;
				Max = punkty[i].score;
			}
		}
	}

	return punkty[Naj_Ruch];
}

void SI::SI_Turn(Plansza& plansza, char player)
{
	
	AIRUCH BEST = min_max(plansza, player, depth);
	

	plansza.insert(BEST.row, BEST.column, AI);
}
*/