#pragma once
#include "admin.h"
#include "student.h"
#include "tutorial.h"
#include "utilizator.h"
#include "istoric.h"
#include "incarcare&actualizare.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <string>

class Platforma {
private:
	Admin adm;
	IncarcareActualizare obj;
	vector<Utilizator> utilizatori;
	vector<Tutorial> tutoriale;
	vector<Istoric> istoric;
	Utilizator utilizator_curent;
	int numar_tutoriale;
	int numar_accesari;

public:
	Platforma();

	void start();
	void oprire();
	void testare();

	void lista_tutoriale();
	void logare(string user, string pass);
	void citireDateDeLogare();
	void acceseaza_istoric();

	void afisareMeniuPrincipal();
	void meniu_principal();
	void afisareMeniuAdmin();
	void meniu_admin();
	void afisareMeniuStudent();
	void meniu_student();

	void citesteDateAdaugareStudent();
	void citesteDateStergereStudent();
	void citesteDateAdaugareTutorial();
	void citesteDateStergereTutorial();
	void citesteDateAccesareTutorial();
	void citesteDateCautareDupaTopic();
};