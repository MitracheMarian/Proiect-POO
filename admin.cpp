#include "admin.h"

void Admin::adauga_student(vector<Utilizator>&utilizatori, string user, string pass) {

	if (isAdmin() == true) {
		string type = "student";
		utilizatori.push_back(Utilizator(type, user, pass));
		cout << endl << "Utilizatorul " << user << " a fost adaugat cu succes!";
	}
	else {
		cout << endl << "ERROR: Acces respins!";
	}
}
void Admin::sterge_student(vector<Utilizator>& utilizatori, string user) {

	if (isAdmin() == true) {
		auto x = find_if(utilizatori.begin(), utilizatori.end(), [=](auto& u) {return u.getUser() == user; }); // lambda function

		if (x != utilizatori.end()) {
			utilizatori.erase(x);
			cout << endl << "Utilizatorul " << user << " a fost eliminat cu succes!";
		}
		else {
			cout << endl << "Utilizatorul " << user << " nu s-a gasit!";
		}
	}
	else {
		cout << endl << "ERROR: Acces respins!";
	}
}
void Admin::adauga_tutorial(vector<Tutorial>& tutoriale, int id, string topic, string titlu, string descriere) {

	if (isAdmin() == true) {
		tutoriale.push_back(Tutorial(id, topic, titlu, descriere, 0));
		cout << endl << "Tutorialul " << titlu << " a fost adaugat cu succes!";
	}
	else {
		cout << endl << "ERROR: Acces respins!";
	}
}
void Admin::sterge_tutorial(vector<Tutorial>& tutoriale, int id) {

	if (isAdmin() == true) {
		auto x = find_if(tutoriale.begin(), tutoriale.end(), [=](auto& u) {return u.getId() == id; }); // lambda function

		if (x != tutoriale.end()) {
			tutoriale.erase(x);
			cout << endl << "Tutorialul cu id " << id << " a fost eliminat cu succes!";
		}
		else {
			cout << endl << "Tutorialul cu id " << id << " nu s-a gasit!";
		}
	}
	else {
		cout << endl << "ERROR: Acces respins!";
	}
}
void Admin::lista_utilizatori(vector<Utilizator>& utilizatori) {

	if (isAdmin() == true) {
		system("CLS");
		for (auto& u : utilizatori) {
			cout << endl << "--------------------------------------";
			cout << endl << "Tip utilizator: " << u.getType();
			cout << endl << "User utilizator: " << u.getUser();
			cout << endl << "Pasword utilizator: " << u.getPass();

		}
		cout << endl << "--------------------------------------\n";
	}
	else {
		cout << endl << "ERROR: Acces respins!";
	}
	cout << "Apasati orice tasta pentru a reveni...\n";
	_getch();

}

bool Admin::isAdmin() {
	return true;
}
