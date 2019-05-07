#include <iostream>
#include <string>
using namespace std;
class graf
{
public:
	string nazwa;
	graf * next=nullptr ;
	graf(string="0");
	~graf();
};

class vertex
{
	string poczatek;
	string koniec;
public:
	vertex(string="A",string="B");
	~vertex();
	void dodaj_wektor();
	void usun_wektor();
	void wyswietl();
};

class lista
{
public:
	graf* first = NULL;
	graf* last = NULL;

	graf* GetPosition(string position);
	void dodaj_wierzcholek(string nazwa);
	void wyswietl();
	int ile();
	void usun_wierzcholek(graf* );
};