#include "tutorial.h"

Tutorial::Tutorial() {

}
Tutorial::Tutorial(int id, string topic, string titlu, string descriere, int nr_vizualizari) {
	this->id = id;
	this->topic = topic;
	this->titlu = titlu;
	this->descriere = descriere;
	this->nr_vizualizari = nr_vizualizari;
}

void Tutorial::incrementeazaVizualizari(Tutorial& t) {
	t.nr_vizualizari++;
}

int Tutorial::getId() {
	return id;
}
string Tutorial::getTopic() {
	return topic;
}
string Tutorial::getTitlu() {
	return titlu;
}
string Tutorial::getDescriere() {
	return descriere;
}
int Tutorial::getNrVizualizari() {
	return nr_vizualizari;
}
