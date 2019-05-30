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
