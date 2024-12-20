#pragma once
#include "utilizator.h"
#include "tutorial.h"
#include <vector>
#include <conio.h>

class Admin : public Utilizator {
public:

	void adauga_student(vector<Utilizator>& utilizatori, string user, string pass);

	void sterge_student(vector<Utilizator>& utilizatori, string user);

	void adauga_tutorial(vector<Tutorial>& tutoriale, int id, string topic, string titlu, string descriere);

	void sterge_tutorial(vector<Tutorial>& tutoriale, int id);

	void lista_utilizatori(vector<Utilizator>& utilizatori);

	bool isAdmin();
};