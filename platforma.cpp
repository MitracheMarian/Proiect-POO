#include "platforma.h"

Platforma::Platforma() {

}

void Platforma::start() {
	obj.startProgram(tutoriale, utilizatori, istoric, numar_accesari, numar_tutoriale);
}
void Platforma::oprire() {
	obj.oprireProgram(tutoriale, utilizatori, istoric);
}
void Platforma::testare() {
	//start();
	//citireDateDeLogare();
	//lista_tutoriale(tutoriale);
	//citesteDateCautareDupaTopic();
	//lista_tutoriale(tutoriale);
	//citesteDateAccesareTutorial();
	//lista_tutoriale(tutoriale);
	//lista_tutoriale(tutoriale);
	//citesteDateStergereTutorial();
	//lista_tutoriale(tutoriale);
	//sterge_tutorial(tutoriale, 2);
	//lista_tutoriale(tutoriale);
	//citesteDateAdaugareTutorial();
	//lista_tutoriale(tutoriale);
	//adauga_tutorial(tutoriale, 6, "Programare", "Invata sa codezi in Java", "Hai sa invatam Java");
	//lista_tutoriale(tutoriale);
	//lista_utilizatori(utilizatori);
	//adauga_student(utilizatori, "student3", "pass_student3");
	//lista_utilizatori(utilizatori);
	//sterge_student(utilizatori, "student6");
	//lista_utilizatori(utilizatori);
	//sterge_student(utilizatori, "student1");
	//lista_utilizatori(utilizatori);
}

void Platforma::lista_tutoriale() {
	system("CLS");

	for (auto& t : tutoriale) {
		cout << endl << "----------------------------------------------------------";
		cout << endl << "ID: " << t.getId();
		cout << endl << "TOPIC: " << t.getTopic();
		cout << endl << "TITLU: " << t.getTitlu();
		cout << endl << "DESCRIERE: " << t.getDescriere();
		cout << endl << "VIZUALIZARI: " << t.getNrVizualizari();

	}
	cout << endl << "----------------------------------------------------------\n" << endl;

	cout << "Apasati orice tasta pentru a reveni...\n";
	_getch();
}
void Platforma::logare(string user, string pass) {
	
	bool ok = 0;
	for (auto& u : utilizatori) {
		if (u.getUser() == user) {
			if (u.getPass() == pass) {
				ok = 0;
				if (u.getType() == "admin") {
					utilizator_curent = u;
					meniu_admin();
				}
				if (u.getType() == "student") {
					utilizator_curent = u;
					meniu_student();
				}
			}
			else {
				ok = 1;
			}
		}
		else {
			ok = 1;
		}
	}
	if (ok == 1) {
		cout << endl << "ERROR: User-ul sau Parola sunt incorecte!";
		cout << endl << "Apasati orice tasta pentru a continua...";
		_getch();
	}
}
void Platforma::citireDateDeLogare() {
	string user;
	string pass;

	cout << endl << "Username: ";
	getline(cin, user);
	cout << "Password: ";
	getline(cin, pass);
	cout << endl;

	logare(user, pass);
}
void Platforma::acceseaza_istoric() {
	system("CLS");

	if (utilizator_curent.getType() == "admin") {
		for (auto& i : istoric) {
			cout << endl << "-----------------------------------------------";
			cout << endl << "User-ul: " << i.getUser();
			cout << endl << "A accesat tutorialul cu id-ul: " << i.getId();
			cout << endl << "La data: " << i.getDate();
			cout << endl << "La ora: " << i.getTime();
		}
		cout << endl << "-----------------------------------------------\n";
	}
	if (utilizator_curent.getType() == "student") {
		for (auto& i : istoric) {
			if (utilizator_curent.getUser() == i.getUser()) {
				cout << endl << "-----------------------------------------------";
				cout << endl << "User-ul: " << i.getUser();
				cout << endl << "A accesat tutorialul cu id-ul: " << i.getId();
				cout << endl << "La data: " << i.getDate();
				cout << endl << "La ora: " << i.getTime();
			}
		}
		cout << endl << "-----------------------------------------------\n";
	}

	cout << "Apasati orice tasta pentru a reveni...\n";
	_getch();
}

void Platforma::afisareMeniuPrincipal() {
	system("CLS");
	cout << endl << "------- Meniu Principal -------" << endl;
	cout << "1. Logare" << endl;
	cout << "2. Vizualizare tutoriale" << endl;
	cout << "3. Iesire" << endl;
	cout << "-------------------------------" << endl;
}
void Platforma::meniu_principal() {
	bool run = true;
	char x;

	while (run) {

		afisareMeniuPrincipal();
		cout << endl << "Introduceti optiunea dorita: ";
		x = _getch();

		switch (x) {
		case '1':
			citireDateDeLogare();
			break;
		case '2':
			lista_tutoriale();
			break;
		case '3':
			run = false;
			oprire();
			exit(0);
			break;
		default:
			cout << endl << "ERROR: Ati introdus un numar gresit!\nApasati orice tasta pentru a continua" << endl;
			_getch();
			break;
		}
	}
}
void Platforma::afisareMeniuAdmin() {
	system("CLS");
	cout << endl << "------- Meniu Administrator -------" << endl;
	cout << "1. Adaugare student" << endl;
	cout << "2. Stergere student" << endl;
	cout << "3. Adaugare tutorial" << endl;
	cout << "4. Stergere tutorial" << endl;
	cout << "5. Vizualizare istoric Student" << endl;
	cout << "6. Vizualizare lista tutoriale" << endl;
	cout << "7. Lista utilizatori" << endl;
	cout << "8. Log out" << endl;
	cout << "-----------------------------------" << endl;
}
void Platforma::meniu_admin() {
	bool run = true;
	char x;

	while (run) {

		afisareMeniuAdmin();
		cout << endl << "Introduceti optiunea dorita: ";
		x = _getch();

		switch (x) {
		case '1':
			citesteDateAdaugareStudent();
			break;
		case '2':
			citesteDateStergereStudent();
			break;
		case '3':
			citesteDateAdaugareTutorial();
			break;
		case '4':
			citesteDateStergereTutorial();
			break;
		case '5':
			acceseaza_istoric();
			break;
		case '6':
			lista_tutoriale();
			break;
		case '7':
			adm.lista_utilizatori(utilizatori);
			break;
		case '8':
			run = false;
			meniu_principal();
			break;
		default:
			cout << endl << "ERROR: Ati introdus un numar gresit!\nApasati orice tasta pentru a continua" << endl;
			_getch();
			break;
		}
	}
}
void Platforma::afisareMeniuStudent() {
	system("CLS");
	cout << endl << "------- Meniu Student -------" << endl;
	cout << "1. Vizualizare Tutoriale" << endl;
	cout << "2. Acceseaza tutorial" << endl;
	cout << "3. Istoric" << endl;
	cout << "4. Cauta tutorial dupa topic" << endl;
	cout << "5. Log out" << endl;
	cout << "-----------------------------" << endl;
}
void Platforma::meniu_student() {
	char x;
	bool run = true;

	while (run) {
		afisareMeniuStudent();
		cout << endl << "Introduceti numarul optiunii dorite: ";
		x = _getch();

		switch (x) {
		case '1':
			lista_tutoriale();
			break;
		case '2':
			citesteDateAccesareTutorial();
			break;
		case '3':
			acceseaza_istoric();
			break;
		case '4':
			citesteDateCautareDupaTopic();
			break;
		case '5':
			run = false;
			meniu_principal();
			break;
		default:
			cout << endl << "ERROR: Ati introdus un numar gresit!\nApasati orice tasta pentru a continua" << endl;
			_getch();
			break;
		}
	}
}

void Platforma::citesteDateAdaugareStudent() {

	string user, pass;
	cout << endl << "Introduceti userul: ";
	getline(cin, user);
	cout << "Introduceti o parola: ";
	getline(cin, pass);

	adm.adauga_student(utilizatori, user, pass);
}
void Platforma::citesteDateStergereStudent() {

	string user;
	cout << endl << "Introduceti userul: ";
	getline(cin, user);

	adm.sterge_student(utilizatori, user);
}
void Platforma::citesteDateAdaugareTutorial() {

	int id;
	string topic, titlu, descriere, buffer;

	cout << endl << "----------------------------------";
	cout << endl << "Introduceti id-ul dorit: ";
	cin >> id;
	cout << "Introduceti topicul tutorialului: ";
	getline(cin, buffer);
	getline(cin, topic);
	cout << "Introduceti titlu tutorialului: ";
	getline(cin, titlu);
	cout << "Introduceti descrierea tutorialului: ";
	getline(cin, descriere);
	cout << "----------------------------------" << endl;
	adm.adauga_tutorial(tutoriale, id, topic, titlu, descriere);
}
void Platforma::citesteDateStergereTutorial() {

	int id;
	cout << endl << "Introduceti id-ul tutorialului pe care doriti sa il stergeti: ";
	cin >> id;
	cin.get();
	adm.sterge_tutorial(tutoriale, id);
}
void Platforma::citesteDateAccesareTutorial() {

	Student stud;
	int id;
	cout << endl << "Introduceti id-ul tutorialului pe care doriti sa il accesati: ";
	cin >> id;
	cin.get();

	stud.Acceseaza_tutorial(tutoriale, id, utilizator_curent, istoric);
	numar_accesari++;

	cout << "Apasati orice tasta pentru a reveni...\n";
	_getch();
}
void Platforma::citesteDateCautareDupaTopic() {

	Student stud;
	string topic;
	cout << endl << "Introduceti topicul pe care il cautati: ";
	getline(cin, topic);

	stud.afiseazaTutorialeDupaTopic(tutoriale, topic);

	cout << "Apasati orice tasta pentru a reveni...\n";
	_getch();
}
