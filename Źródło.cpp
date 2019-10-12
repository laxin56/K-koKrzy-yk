#include "plansza.h"
#include "G_AI.h"
#include "gra.h"

#include <iostream>

using namespace std;

int main()
{
	int n = 0; // liczba pol
	int r = 0; // liczba znakow w rzedzie
	
	cout << "--------------------------------------------------------------" << endl;
	cout << "Witaj w grze  KOLKO i KRZYZYK - Gra posiada kilka opcji wyboru" << endl;
	cout << "Masz mozliwosc wyboru trybu rozgrywki, oraz wielkosci planszy  " << endl;
	cout << "--------------------------------------------------------------" << endl;

	int menu;
	char znak;
	while (1)
	{

		cout << "Wybierz Swoj Typ Rozgrywki: " << endl;
		cout << "1. Gracz VS Gracz " << endl;
		cout << "2. Gracz Vs Komputer" << endl;
		cout << "3. Zakoncz gre" << endl;
		cout << "Twoj wybor:";
		cin >> menu;
		while (menu != 1 && menu != 2 && menu != 3)
		{
			cin.clear();
			cin.sync();
			cout << "Zly wybor! Wybierz poprawnie:";
			cin >> menu;
		}

		cout << endl << endl << "LICZBA POL:";
		cin >> n;
		cout << "LICZBA ZNAKOW W RZEDZIE DO WYGRANEJ:";
		cin >> r;
		cout << endl << endl;

		switch (menu)
		{
		case 1:
		 graczVSgracz(n, r);
		 cout << endl << endl << "Chcesz zagrac jeszcze raz ? " << endl;
		 cout << "t - tak  |||||  inny znak - nie (Opcja konczy gre) " << endl;
		 cout << "Twoj wybor: ";
		 cin >> znak;
		 cout << "------------------------------------------" << endl;
		 if (znak == 't')  break;
		 else  return 0;
		 
		case 2:
			graczVSkomputer(n, r);
			cout << endl << endl << "Chcesz zagrac jeszcze raz? " << endl;
			cout << "t - tak  |||||  inny znak - nie (Opcja konczy gre) " << endl;
			cout << "Twoj wybor: ";
			cin >> znak;
			cout << "------------------------------------------" << endl;
			if (znak == 't')  break;
			else  return 0;

		case 3:
			cout << "Koncze gre!" << endl;
			return 0;
		}

	}

	return 0;
}
