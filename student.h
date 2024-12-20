#pragma once
#include "utilizator.h"
#include "tutorial.h"
#include "istoric.h"
#include "platforma.h"
#include <fstream>
#include <vector>

class Student : public Utilizator {
public:
	void Acceseaza_tutorial(vector<Tutorial>& tutoriale, int id_accesat, Utilizator current_user, vector<Istoric>& istoric);
	void afiseazaTutorialeDupaTopic(vector<Tutorial>& tutoriale, string topic);
	void actualizeaza_istoric(Tutorial t, Utilizator curent_user, vector<Istoric>& istoric);
	void dateTime(string& date, string& times);

	bool isAdmin();
};