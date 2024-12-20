#include "utilizator.h"

Utilizator::Utilizator() {

}
Utilizator::Utilizator(string type, string user, string pass) : type(type), user(user), pass(pass) {}

string Utilizator::getType() {
	return type;
}
string Utilizator::getUser() {
	return user;
}
string Utilizator::getPass() {
	return pass;
}
