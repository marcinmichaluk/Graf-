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
public:
	string nazwa1;
	string nazwa2;
	vertex* nast = nullptr;
	vertex(string nazwa1,string nazwa2);
	~vertex();
};

class lista
{
public:
	graf* first = NULL;
	graf* last = NULL;
	vertex* f = NULL;//f-first
	vertex* l = NULL;//l-last

	graf* GetPosition(string nazwa);
	vertex* GetPosition(string nazwa, string nazwa2);
	void dodaj_wierzcholek(string nazwa);
	void wyswietl();
	int ile();
	int ile_wektorow();
	void usun_wierzcholek(graf*);
	void dodaj_wektor(string , string );
	void usun_wektor(vertex*);
	void wyswietl_wektory();
	bool czy_mozna(string);
	bool czy_mozna_wierzcholek(string);
};