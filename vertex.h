#pragma once
#include <iostream>
#include <string>
using namespace std;

class vertex
{
public:
	string nazwa1;
	string nazwa2;
	vertex* nast = nullptr;
	vertex(string nazwa1, string nazwa2);
	~vertex();
};
