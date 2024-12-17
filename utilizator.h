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
	Utilizator() {

	}

	Utilizator (string type, string user, string pass ) : type(type), user(user), pass(pass) {}

	string getType() {
		return type;
	}

	string getUser() {
		return user;
	}

	string getPass() {
		return pass;
	}
};