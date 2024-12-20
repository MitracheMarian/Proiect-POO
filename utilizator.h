#pragma once
#include <iostream>
#include <string>
using namespace std;

class Utilizator {
private:
	string type;
	string user;
	string pass;

public:
	Utilizator();
	Utilizator(string type, string user, string pass);

	string getType();
	string getUser();
	string getPass();
};