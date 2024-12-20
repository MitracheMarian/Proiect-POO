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
	Tutorial();
	Tutorial(int id, string topic, string titlu, string descriere, int nr_vizualizari);

	void incrementeazaVizualizari(Tutorial& t);

	int getId();
	string getTopic();
	string getTitlu();
	string getDescriere();
	int getNrVizualizari();
};