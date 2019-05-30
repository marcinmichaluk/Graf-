#pragma once
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