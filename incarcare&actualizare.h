#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "utilizator.h"
#include "tutorial.h"
#include "istoric.h"
using namespace std;

class IncarcareActualizare {
private:
	void incarcare_utilizatori(vector<Utilizator>& utilizatori) {

		ifstream file("utilizatori.txt");
		if (!file.is_open()) {
			cout << endl << "!ERROR: Nu sa putut deschide fisierul cu utilizatori!" << endl;
		}
		else {

			string type, user, pass;
			while (file >> type >> user >> pass) {
				utilizatori.push_back(Utilizator(type, user, pass));
			}

		}
		file.close();
	}

	void incarcare_tutoriale(vector<Tutorial>& tutoriale, int& numar_tutoriale) {

		string topic, titlu, descriere, buffer;
		int nr_vizualizari, id, i = 0;
		ifstream file("tutoriale.txt", ios::app);
		if (!file.is_open()) {
			cout << endl << "ERROR: eroare la deschiderea fisierului tutoriale.txt!";
		}
		else {
			file >> numar_tutoriale;

			while (i < numar_tutoriale) {
				file >> id;
				getline(file, buffer);
				getline(file, topic);
				getline(file, titlu);
				getline(file, descriere);
				file >> nr_vizualizari;

				tutoriale.push_back(Tutorial(id, topic, titlu, descriere, nr_vizualizari));
				i++;
			}
		}
		file.close();
	}

	void incarcare_istoric(vector<Istoric>& istoric, int& numar_accesari) {
		ifstream file("istoric.txt");
		if (!file.is_open()) {
			cout << endl << "!ERROR: Nu sa putut deschide fisierul istoric.txt!" << endl;
		}
		else {
			string user, date, time, buffer;
			file >> numar_accesari;
			getline(file, buffer);
			int i = 0, id;
			while (i < numar_accesari) {
				getline(file, user);
				file >> id;
				getline(file, buffer);
				getline(file, date);
				getline(file, time);
				i++;

				istoric.push_back(Istoric(user, id, date, time));
			}
		}
		file.close();
	}

	void actualizare_utilizatori(vector<Utilizator>& utilizatori) {
		
		ofstream file("utilizatori.txt", ios::trunc);
		if (!file.is_open()) {
			cout << endl << "ERROR: Eroare la deschiderea fisierului utilizatori.txt";
		}
		else {
			for (auto& u : utilizatori) {
				file << u.getType() << " " << u.getUser() << " " << u.getPass() << endl;
			}

		}
		file.close();
	}

	void actualizare_tutoriale(vector<Tutorial>& tutoriale) {
		
		auto numar_tutoriale = tutoriale.size();
		ofstream file("tutoriale.txt", ios::trunc);
		if (!file.is_open()) {
			cout << endl << "ERROR: Eroare la deschiderea fisierului tutoriale.txt!";
		}
		else {
			file << numar_tutoriale;
			for (auto& t : tutoriale) {
				file << endl << t.getId() << endl << t.getTopic() << endl << t.getTitlu() << endl << t.getDescriere() << endl << t.getNrVizualizari();
			}
		}
		file.close();
	}

	void actualizare_istoric(vector<Istoric>& istoric) {
		
		string user, date, time, buffer;
		ofstream file("istoric.txt", ios::trunc);
		if (!file.is_open()) {
			cout << endl << "ERROR: eroare la deschiderea fisierului istoric.txt!";
		}
		else {
			auto numar_accesari = istoric.size();
			file << numar_accesari;
			for(auto& i : istoric) {
				file << endl << i.getUser() << endl << i.getId() << endl << i.getDate() << endl << i.getTime();
			}
		}
		file.close();
	}

public:
	void startProgram(vector<Tutorial>& tutoriale, vector<Utilizator>& utilizatori, vector<Istoric>& istoric, int& numar_accesari, int& numar_tutoriale) {
		incarcare_tutoriale(tutoriale, numar_tutoriale);
		incarcare_istoric(istoric, numar_accesari);
		incarcare_utilizatori(utilizatori);
	}

	void oprireProgram(vector<Tutorial>& tutoriale, vector<Utilizator>& utilizatori, vector<Istoric>& istoric) {
		actualizare_tutoriale(tutoriale);
		actualizare_utilizatori(utilizatori);
		actualizare_istoric(istoric);
	}
};