#pragma once
#include "plansza.h"
#ifndef g_ai_h
#define g_ai_h

//Struktura definiujaca ostatni ruch
struct AIRUCH
{
	AIRUCH() {};

	AIRUCH(int _score) : score(_score) {};
	AIRUCH(int _row, int _column) : row(_row), column(_column) {};

	//Pola ktore przechowuja ostatnia wstawione wspolrzedne przez graczy lub komputer i punkty
	int row;
	int column;
	int score;


};

//Klasa SI definiuje nam komputer z ktorym bedziemy walczyc
class SI {
public:
	SI();
	~SI();

	//zainicjowane znaki dla czlowieka i komputera oraz glebokosc rekurencji
	char Human = 'x';
	char AI = 'o';
	int depth;

	char get_Human() const;
	char get_AI() const;
	void set_depth(int _depth);

	//Funkcje wykonujace algorytm min_max i ruch gracza

int min_max(Plansza& plansza, char player , int _depth,int,int);

  //AIRUCH min_max(Plansza& plansza, char player, int _depth);

	void SI_Turn(Plansza& plansza, char player);
	

};

#endif