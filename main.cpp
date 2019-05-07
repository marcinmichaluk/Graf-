#include <iostream>
#include<string>
#include<cstdlib>
#include <ctime> 
#include <vector>
#include "Graf.h"
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
		if (ilosc > 20)
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
	string nazwa;
	lista* nlist = new lista();
	string n;
	for (int i = 0; i < ilosc; i++)
	{
		cout << "Podaj nazwe wierzchilka" << endl;
		cin >> nazwa;
		nlist->dodaj_wierzcholek(nazwa);
	}
	cout << "stworzono " << ilosc << " wierzcholkow" << endl;
		nlist->wyswietl();
	/*cout << "teraz nastapi laczenie wierzcholkow( dodawanie wektorow) " << endl << "Podaj poczatkowa ilosc wektorow" << endl;
	int ile_wekt;
	cin >> ile_wekt;
	string pocz, kon;
	vertex* x = new vertex[ile_wekt];
	for (int i = 0; i < ile_wekt; i++)
	{
		cout << "Wektor numer " << i + 1 << endl;
		cout << " podaj nazwe pierwszego wierzcholeka " << endl;
		cin >> pocz;
		cout << endl << " podaj nazwe drugiego wierzcholka " << endl;
		cin >> kon;
		x[i] = vertex(pocz, kon);

	}
	cout << "Stworzono " << ile_wekt << " wektorow: " << endl;
	for (int i = 0; i < ile_wekt; i++)
	{
		cout << "wektor " << i+1 << endl;
		x[i].wyswietl();
	}*/
	int operacja = 0;
	while (operacja > -2)
	{
		cout << "Wybierz operacjê na grafie " << endl << "Nacisnij 1 aby dodac wierzcholek" << endl << "2 aby usunac wierzcholek" << endl << "3 aby dodac wektor" << endl << "4 aby usunac wierzcholek" << endl 
			<< "5 aby wyswietlic wierzcholki" << "6 aby wyswietlic wektory"<<endl<<"7 aby zakonczyc program"<<endl;
		cin >> operacja;
		if (operacja == 1)
		{
			cout << "tu jestes" << endl;
			nlist->wyswietl();
		}
		if (operacja == 3)
		{
			cout << "Podaj nazwe wierzcholka, ktory chcesz usunac"<<endl;
			cin >> nazwa;
			graf* n = nlist->GetPosition(nazwa);
			nlist->usun_wierzcholek(n);
		}
		/*if (operacja == 2)
		{
			nlist->dodaj_wierzcholek();
		}*/
		/*if (operacja == 4)
		{
			x[5].usun_wektor();
		}
		if (operacja == 5)
		{

		}
		if (operacja == 6)
		{

		}*/
		if (operacja == 7)
		{
			break;
		}
		else
		{
			cout << endl << "podano nieprawidlowa operacje " << endl << "wybierz liczbe od 1 do 5" << endl;
		}
	}
	system("pause");
	delete nlist;
	return 0;
}
