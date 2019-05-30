#pragma once
#include <iostream>
#include <string>
using namespace std; 

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
	void dodaj_wektor(string , string);
	void usun_wektor(vertex*);
	void wyswietl_wektory();
	bool czy_mozna(string);
	bool czy_mozna_wierzcholek(string);
	void czy_spojny(int, int, graf*);
};
