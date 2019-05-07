#include <iostream>
#include <string>
#include "Graf.h"
using namespace std;

graf::graf(string n)
{
	nazwa = n;
	this->next = nullptr;
}
graf::~graf()
{
	next = nullptr;
}
vertex::vertex(string p,string k)
{
	poczatek = p;
	koniec = k;
}
vertex::~vertex()
{

}
void vertex::dodaj_wektor()
{

}
void vertex::usun_wektor()
{

}
void vertex::wyswietl()
{
	cout << "pooczatek wektora -> " << poczatek << " koniec wektora ->" << koniec << endl;
}
graf* lista::GetPosition(string naz)
{
	graf* temp = this->first;
	int rozmiar = ile();
	for (int i = 1; i <rozmiar ; i++)
	{
		if (temp->nazwa == naz)
		{
			return temp;
		}
	}
}
void lista::dodaj_wierzcholek(string nazwa)
{
	graf* n = new graf(nazwa);
	if (this->first == nullptr || this->last == nullptr)
	{
		this->first = this->last=n;
	}
		this->last -> next = n;
		this->last = n;

}
void lista::wyswietl()
{
	graf* pomoc = this->first;
	while(pomoc != nullptr)
	{
		cout << "Nazwa wierzcholka:  " << pomoc->nazwa << endl;
		pomoc = pomoc->next;
	}
}
int lista::ile()
{
	graf* pomoc = this->first;
	int i = 0;
	while (pomoc != nullptr)
	{
		i++;
		pomoc = pomoc->next;
	}
	return i;
}
void lista::usun_wierzcholek(graf* adres)
{
	graf* pomoc = this->first;
	for (int i = 0; i > -1; i++)
	{
		if (pomoc == adres)
		{
			this->first = this->first->next;
			delete pomoc;
			break;
		}
		if (pomoc == nullptr)
		{
			cout << "podano nieprawidlowa nazwe wiercholka" << endl;
			break;
		}
		pomoc = pomoc->next;
	}
}
