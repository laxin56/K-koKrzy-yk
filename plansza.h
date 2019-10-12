#pragma once
#ifndef plansza_h
#define plansza_h


/*
Klasa Plansza = Klasa która definiuje wyglad naszej planszy
*/

class Plansza {

	char** game;   //dynamiczna tablica dwuwymiarowa
public:
	int N; // rozmiar naszej kwadratowej planszy w postaci NxN
	int R; //ilosc danego znaku w rzedzie definiowana przez użytkownika

	int last_row; //pola prrzechowuja kolejno ostatnio wstawione: wiersz, kolumne i indeks uzytkownika
	int last_column;
	char last_player;

	//Konstruktor, ktory do pola N z klasy Plansza przypisuje argument rozmiar
	Plansza(int, int);
	//Destruktor niszczacy nasza pamiec
	~Plansza();

	//odczytuje aktualny element
	void gete();

	//Funkcja wyswietlajaca akutalna zawartosc tablicy
	void display();
	//funkcja zwracajaca nam dany element planszy
	char get_el(int, int);
	//funkcja zwracajaca wielkosc planszy
	int get_N();
	//funkcja sprawdzajaca wygrana
	char check_win() const;
	//funkcja sprawdzajaca remis
	char remis() const;
	//funkcja sprawdzajaca czy mamy remis badz wygrana
	char check_game();
	//funkcja wstawiajaca nam w dany wiersz i kolumne odpowiedni znak - x lub o
	void insert(int w, int k, char player);

	
};

#endif