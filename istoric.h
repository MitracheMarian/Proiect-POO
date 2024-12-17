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
	Istoric() {

	}

	Istoric(string user, int id, string date, string time) : user(user), id(id), date(date), time(time) {}

	string getUser() {
		return user;
	}

	int getId() {
		return id;
	}
	
	string getDate() {
		return date;
	}

	string getTime() {
		return time;
	}
};