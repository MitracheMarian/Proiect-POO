#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tutorial {
private:
	int id = 0;
	string topic;
	string titlu;
	string descriere;
	int nr_vizualizari = 0;

public:
	Tutorial() {

	}

	Tutorial(int id, string topic, string titlu, string descriere, int nr_vizualizari) {
		this->id = id;
		this->topic = topic;
		this->titlu = titlu;
		this->descriere = descriere;
		this->nr_vizualizari = nr_vizualizari;
	}

	void incrementeazaVizualizari(Tutorial& t) {
		t.nr_vizualizari++;
	}

	int getId() {
		return id;
	}

	string getTopic() {
		return topic;
	}

	string getTitlu() {
		return titlu;
	}

	string getDescriere() {
		return descriere;
	}

	int getNrVizualizari() {
		return nr_vizualizari;
	}
};