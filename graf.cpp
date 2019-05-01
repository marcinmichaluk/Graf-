#include <iostream>
#include <string>
#include "Graf.h"
using namespace std;

graf::graf(string n )
{
	nazwa = n;
}
graf::~graf()
{

}
void graf::dodaj_wierzcholek()
{

}
void graf::usun_wierzcholek()
{

}
void graf::wyswietl()
{
	cout << "graf:  " << nazwa << endl;
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
