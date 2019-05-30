#include <iostream>
#include<string>
#include<cstdlib>
#include <ctime> 
#include <vector>
#include "Graf.h"
#include "vertex.h"
#include "lista.h"
using namespace std;
int main()
{
	srand(time(NULL));
	int ilosc=0;
	for (int i = 0; i > -2; i++)
	{
		cout << "podaj poczatkowa liczbe wierzcholkow " << endl;
		cin >> ilosc;
		bool blad = cin.fail();
		cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		if (blad == 1)
		{
			cout << "To nie jest liczba, " << endl << "sproboj jeszcze raz";
		}
		cout << endl;
		if (ilosc > 10)
		{
			cout << "Jestes pewny, ze chcesz stworzyc tyle wierzcholkow? :) " << endl<<"Wybierz  y[YES] lub n[NO]"<<endl;
			char odp = NULL;
			cin >> odp;
			if (odp != 'y' && odp != 'n')
			{
				cout << "wpisales niewlasciwy znak " << endl<<"sproboj jeszcze raz " <<endl;
			}
			if (odp == 'y')
			{
				cout << "no dobra, to powodzenia  " << endl;;
				break;
			}
			if (odp == 'n')
			{
				cout << "dobry wybor," << endl << "sproboj jeszcze raz" << endl;
				ilosc = 0;
			}
		}
		if (ilosc < 0)
		{
			cout << "Podano nieprawidlowa ilosc, " << endl << "sproboj jeszcze raz" << endl;
		}
		if (ilosc > 0)
		{
			break;
		}
	}
	string nazwa, nazwa2;
	lista* nlist = new lista();
	string n;
	bool cm;
	for (int i = 0; i < ilosc; i++)
	{
		cout << "Podaj nazwe wierzcholka" << endl;
		cin >> nazwa;
		cm = nlist->czy_mozna_wierzcholek(nazwa);
		if (cm == 0)
		{
			i = i - 1;
			cout << "Wierzcholek o podanej nazwie juz istnieje." << endl;
		}
		if (cm == 1)
		{
			nlist->dodaj_wierzcholek(nazwa);
		}
	}
	cout << "stworzono " << ilosc << " wierzcholkow" << endl;
		nlist->wyswietl();
	cout << "teraz nastapi laczenie wierzcholkow( dodawanie wektorow) " << endl << "Podaj poczatkowa ilosc wektorow" << endl;
	int ile_wekt;
	cin >> ile_wekt;
	for (int i = 0; i < ile_wekt;i++)
	{
		cout << "Podaj nazwe pierwszego wierzcholka" << endl;
		cin >> nazwa;
		cout << "Podaj nazwe drugiego wierzcholka" << endl;
		cin >> nazwa2;
		nlist->dodaj_wektor(nazwa,nazwa2);
	}
	int operacja = 0;
	while (operacja > -2)
	{
		cout << "Wybierz operacjê na grafie " << endl << "Nacisnij:"<<endl<<"1 aby dodac wierzcholek" << endl << "2 aby usunac wierzcholek" << endl << "3 aby dodac wektor" << endl << "4 aby usunac wektor" << endl 
			<< "5 aby wyswietlic wierzcholki" <<endl<< "6 aby wyswietlic wektory"<<endl<<"7 aby zakonczyc program"<<endl;
		for (int i = 1; i > -2;)
		{
			cin >> operacja;
			bool blad = cin.fail();
			cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			if (blad == 1)
			{
				cout << "To nie jest liczba, " << endl << "sproboj jeszcze raz"<<endl;
			}
			if (operacja < 1 || operacja>7)
			{
				cout << "wybrano nieprawidlowa operacje " << endl ;
				blad = 1;
			}
			if (blad == 0)
			{
				break;
			}
		}
		if (operacja == 1)
		{
			cout << "Podaj nazwe nowego wierzcholka" << endl;
			cin >> nazwa;
			cm = nlist->czy_mozna_wierzcholek(nazwa);
			if (cm == 0)
			{
				cout << "wierzcholek o podanej nazwie juz istnieje." << endl;
			}
			if (cm == 1)
			{
				nlist->dodaj_wierzcholek(nazwa);
			}
		}
		if (operacja == 2)
		{
			bool czy_mozna;

			cout << "Podaj nazwe wierzcholka, ktory chcesz usunac" << endl;
			cin >> nazwa;
			czy_mozna = nlist->czy_mozna(nazwa);
			if (czy_mozna == 0)
			{
				graf* n = nlist->GetPosition(nazwa);
				if (n != nullptr)
				{
					nlist->usun_wierzcholek(nlist->GetPosition(nazwa));
				}
			}
		}
		if (operacja == 3)
		{
			cout << "Podaj nazwy wierzcholka, ktore ma laczyc wektor" << endl << "wierzcholek 1: ";
			cin >> nazwa;
			cout << endl << "wierzcholek 2: ";
			cin >> nazwa2;
			nlist->dodaj_wektor(nazwa, nazwa2);

		}
		if (operacja == 4)
		{
			cout << "Podaj nazwy wierzcholkow, ktore laczy wektor" << endl << "wierzcholek 1: ";
			cin >> nazwa;
			cout << endl << "wierzcholek 2: ";
			cin >> nazwa2;
			if (nlist->GetPosition(nazwa, nazwa2) != nullptr)
			{
				nlist->usun_wektor(nlist->GetPosition(nazwa, nazwa2));
			}
		}
		if (operacja == 5)
		{
			nlist->wyswietl();
			system("pause");
		}
		if (operacja == 6)
		{
			nlist->wyswietl_wektory();
			system("pause");
		}
		if (operacja == 7)
		{
			break;
		}
	}
	system("pause");
	delete nlist;
	return 0;
}
