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
			cout << "Jestes pewny, ze chcesz stworzyc tyle wierzcholkow ? :) " << endl<<"Wybierz  y[YES] lub n[NO]"<<endl;
			char odp = NULL;
			cin >> odp;
			if (odp != 'y' && odp != 'n')
			{
				cout << "wpisales niewlasciwy znak" << endl<<"sproboj jeszcze raz " <<endl;
			}
			if (odp == 'y')
			{
				cout << "no dobra, to powodzenia " << endl;;
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
	graf* w = new graf[ilosc];
	string n;
	for (int i = 0; i < ilosc; i++)
	{
		cout << "podaj nazwe wierzcholka " << i+1 << endl;
		cin >> n;
		w[i] = graf(n);
	}
	cout << "stworzono " << ilosc << " wierzcholkow" << endl;
	for (int i = 0; i < ilosc; i++)
	{
		w[i].wyswietl();
	}
	cout << "teraz nastapi laczenie wierzcholkow( dodawanie wektorow) " << endl << "Podaj poczatkowa ilosc wektorow" << endl;
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
	}
	system("pause");
	delete[] w;
	delete[] x;
	return 0;
}
