#include <iostream>
#include <string>
using namespace std;

class graf
{
private:
	string nazwa;
public:
	graf(string="0");
	~graf();
	void wyswietl();
	void dodaj_wierzcholek();
	void usun_wierzcholek();
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
