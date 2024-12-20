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
	void incarcare_utilizatori(vector<Utilizator>& utilizatori);
	void incarcare_tutoriale(vector<Tutorial>& tutoriale, int& numar_tutoriale);
	void incarcare_istoric(vector<Istoric>& istoric, int& numar_accesari);

	void actualizare_utilizatori(vector<Utilizator>& utilizatori);
	void actualizare_tutoriale(vector<Tutorial>& tutoriale);
	void actualizare_istoric(vector<Istoric>& istoric);

public:
	void startProgram(vector<Tutorial>& tutoriale, vector<Utilizator>& utilizatori, vector<Istoric>& istoric, int& numar_accesari, int& numar_tutoriale);
	void oprireProgram(vector<Tutorial>& tutoriale, vector<Utilizator>& utilizatori, vector<Istoric>& istoric);
};