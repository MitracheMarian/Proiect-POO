#pragma once
#include "utilizator.h"
#include "tutorial.h"
#include "istoric.h"
#include "platforma.h"
#include <fstream>
#include <vector>

class Student : public Utilizator {
public:
	void Acceseaza_tutorial(vector<Tutorial>& tutoriale, int id_accesat, Utilizator current_user, vector<Istoric>& istoric) {
		
		bool gasit = false;
		for (auto& t : tutoriale) {
			if (t.getId() == id_accesat) {
				t.incrementeazaVizualizari(t);
				gasit = true;
				actualizeaza_istoric(t, current_user, istoric);
			}
		}
		if (gasit == true) {
			cout << endl << "Actualizarea numarului de vizualizari a avut loc cu succes!\n";
		}
		else {
			cout << endl << "ERROR: Actualizarea numarului de vizualizari a esuat!";
		}
	}

	void afiseazaTutorialeDupaTopic(vector<Tutorial>& tutoriale, string topic) {
		for (auto& t : tutoriale) {
			if (t.getTopic() == topic) {
				cout << "--------------------------------------------------------------";
				int id = t.getId();
				cout << endl << "ID: " << id;
				string top = t.getTopic();
				cout << endl << "TOPIC: " << top;
				string titlu = t.getTitlu();
				cout << endl << "TITLU: " << titlu;
				string descriere = t.getDescriere();
				cout << endl << "DESCRIERE: " << descriere;
				int nr_viz = t.getNrVizualizari();
				cout << endl << "NUMAR VIZUALIZARI: " << nr_viz << endl;
				cout << "--------------------------------------------------------------" << endl;
			}
		}
	}

	void actualizeaza_istoric(Tutorial t, Utilizator curent_user, vector<Istoric>& istoric) {

		string date, time, user;
		user = curent_user.getUser();
		dateTime(date, time);

		istoric.push_back(Istoric(user, t.getId(), date, time));
	}

	void dateTime(string& date, string& times) {

		std::time_t z = time(nullptr);
		std::tm* now = localtime(&z);

		ofstream fileO("dataTimp.txt", ios::trunc);

		fileO << (now->tm_year + 1900) << "-" << 
			(now->tm_mon + 1) << "-" <<
			now->tm_mday << endl << now->tm_hour
			<< ":" << now->tm_min << ":"
			<< now->tm_sec;
		fileO << endl;

		ifstream fileT("dataTimp.txt");
		getline(fileT, date);
		getline(fileT, times);
		fileT.close();
	}

	bool isAdmin() {
		return false;
	}
};