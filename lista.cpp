#include "Graf.h"
#include "vertex.h"
#include "lista.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<stack>

using namespace std;

graf* lista::GetPosition(string naz)
{
	graf* temp = this->first;
	int rozmiar = ile();
	for (int i = 0; i < rozmiar; i++)
	{
		if (temp->nazwa == naz)
		{
			return temp;
		}
		temp = temp->next;
	}
	cout << "Podano nieprawidlowa nazwe" << endl;
	return 0;
}
void lista::dodaj_wierzcholek(string nazwa)
{
	graf* n = new graf(nazwa);
	if (this->first == nullptr || this->last == nullptr)
	{
		this->first = n;
		this->last = n;
	}
	else
	{
		this->last->next = n;
		this->last = n;
	}

}
void lista::wyswietl()
{
	graf* pomoc = this->first;
	while (pomoc != nullptr)
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
	graf* pomoc2 = this->first;
	for (int i = 0; i > -1; i++)
	{
		pomoc2 = pomoc->next;
		if (pomoc2->next == nullptr)
		{
			pomoc->next = nullptr;
			this->last = pomoc;
			break;
		}
		if (pomoc->next == adres)
		{

			pomoc->next = pomoc2->next;
			break;
		}
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
void lista::dodaj_wektor(string n1, string n2)
{
	bool a = 0;
	bool b = 0;
	bool mozna = 0;
	graf* pomoc = this->first;
	for(int i=0;i<1;)
	{
		if (pomoc == nullptr)
		{
			if (a == 0)
			{
				cout << "Wierzcholek numer 1 nie istnieje " << endl;
				mozna = 0;
			}
			if (b == 0)
			{
				cout << "Wierzcholek numer 2 nie istnieje " << endl;
				mozna = 0;
			}
			break;
		}
		if (pomoc->nazwa == n1)
		{
			a = 1;
		}
		if (pomoc->nazwa == n2)
		{
			b = 1;
		}
		if (a == 1 && b == 1)
		{
			mozna = 1;
			break;
		}
		pomoc = pomoc->next;
	}
	vertex* pomoc2 = this->f;
	while(pomoc2!=nullptr)
	{
		if (pomoc2 == nullptr) break;
		if ((pomoc2->nazwa1 == n1 && pomoc2->nazwa2 == n2) || (pomoc2->nazwa1 == n2 && pomoc2->nazwa2 == n1))
		{
			cout << "Podany wektor juz istnieje. " << endl;
			mozna = 0;
		}
		pomoc2 = pomoc2->nast;
	}
	if (mozna == 1)
	{
		vertex* x = new vertex(n1, n2);
		if (this->f == nullptr || this->l == nullptr)
		{
			this->f = x;
			this->l = x;
		}
		else
		{
			this->l->nast = x;
			this->l = x;
		}
	}
}
void lista::wyswietl_wektory()
{
	vertex* pomoc1 = this->f;
	for (int i = 1; pomoc1 != nullptr; i++)
	{
		cout << "Wektor nr " << i << " Nazwa wierzcholka poczatkowego:  " << pomoc1->nazwa1 << " Nazwa wierzcholka koncowego: " << pomoc1->nazwa2 << endl;
		pomoc1 = pomoc1->nast;
	}
}
vertex* lista::GetPosition(string naz, string naz2)
{
	vertex* pomoc = this->f;
	int rozmiar = ile_wektorow();
	for (int i = 1; i < rozmiar + 1; i++)
	{
		if (pomoc->nazwa1 == naz && pomoc->nazwa2 == naz2)
		{
			return pomoc;
		}
		pomoc = pomoc->nast;
	}
	cout << "Podano nieprawidlowa nazwe" << endl;
	return 0;
}
int lista::ile_wektorow()
{
	vertex* pomoc = this->f;
	int i = 0;
	while (pomoc != nullptr)
	{
		i++;
		pomoc = pomoc->nast;
	}
	return i;
}
//void lista::usun_wektor(vertex* adres)
//{
//	vertex* pomoc = this->f;
//	vertex* pomoc2 = this->f;
//	for (int i = 0; i > -1; i++)
//	{
//		pomoc2 = pomoc->nast;
//		if (pomoc2->nast == nullptr)
//		{
//			this->f = nullptr;
//			this->l = nullptr;
//		}
//		if (pomoc->nast == adres)
//		{
//
//			pomoc->nast = pomoc2->nast;
//			break;
//		}
//		if (pomoc == adres)
//		{
//			this->f = this->f->nast;
//			delete pomoc;
//			break;
//		}
//		if (pomoc2->nast == nullptr)
//		{
//			this->l = nullptr;
//			pomoc->nast = nullptr;
//			break;
//		}
//		if (pomoc == nullptr)
//		{
//			cout << "podano nieprawidlowa nazwe wiercholka" << endl;
//			break;
//		}
//		if (pomoc2->nast == nullptr)
//		{
//			pomoc->nast = nullptr;
//			break;
//		}
//		pomoc = pomoc->nast;
//	}
//}
void lista::usun_wektor(vertex* adres)
{
	vertex* pomoc = this->f;
	vertex* pomoc2 = this->f;
	for (int i = 0; i > -1; i++)
	{
		pomoc2 = pomoc2->nast;
		if (pomoc->nast==nullptr && pomoc==adres)
		{
			this->f = nullptr;
			this->l = nullptr;
			delete pomoc;
			break;
		}
		if (pomoc2 == adres && pomoc2->nast == nullptr)
		{
			pomoc->nast = nullptr;
			this->l = pomoc;
			delete pomoc2;
			break;
		}
		if (pomoc==this->f && pomoc==adres)
		{
			this->f = pomoc2;
			delete pomoc;
			break;

		}
		if (pomoc2 == adres)
		{
			pomoc->nast = pomoc2->nast;
			delete pomoc2;
			break;
		}
	}
}
bool lista::czy_mozna(string a)
{
	bool czy_mozna;
	vertex* pomoc = this->f;
	for (int i = 0; i > -2;)
	{
		if (pomoc == nullptr)
		{
			break;
		}
		if (pomoc->nazwa1 == a || pomoc->nazwa2 == a)
		{
			cout << "Nie mozna usunac wierzcholka, poniewaz jest on polaczony wektorem." << endl << "najpierw usun polaczenie wektorami" << endl;
			return czy_mozna = 1;
		}
		pomoc = pomoc->nast;
	}
	return czy_mozna = 0;
}
bool lista::czy_mozna_wierzcholek(string b)
{
	bool a = 1;
	graf* pomoc = this->first;
	if (this->first == nullptr)
	{
		return a = 1;
	}
	while (pomoc != NULL)
	{
		if (pomoc->nazwa == b)
		{
			return a = 0;
		}
		pomoc = pomoc->next;
	}
	return a;
}
//void czy_spojny(int n,int m, vertex* g)
////{
////	bool* visited = new bool[n];
////	vertex* pomoc = g;
////	for (int i = 0; i < n; i++)
////	{
////		visited[i] = 0;
////	}
////	stack<bool>stos;
////	int vc = 0; //vertex count 
////	int v = 0;//vertex
////	stos.push(0);
////	visited[0] = 1;
////	while (stos.empty() == 0)
////	{
////		v = stos.top();
////		stos.pop();
////		vc++;
////	}
////}