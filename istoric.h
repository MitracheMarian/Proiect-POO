#pragma once
#include <iostream>
#include <string>
using namespace std;

class Istoric {
private:
	string user;
	int id;
	string date;
	string time;

public:
	Istoric();
	Istoric(string user, int id, string date, string time);

	string getUser();
	int getId();
	string getDate();
	string getTime();
};