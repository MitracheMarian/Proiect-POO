#include "istoric.h"

Istoric::Istoric() {

}
Istoric::Istoric(string user, int id, string date, string time) : user(user), id(id), date(date), time(time) {}

string Istoric::getUser() {
	return user;
}
int Istoric::getId() {
	return id;
}
string Istoric::getDate() {
	return date;
}
string Istoric::getTime() {
	return time;
}
