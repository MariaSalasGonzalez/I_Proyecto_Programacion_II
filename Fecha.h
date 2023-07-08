#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int = 0, int = 0, int = 0);
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	int getDia();
	int getMes();
	int getAnio();
	string toString();
	friend ostream& operator <<(ostream&, Fecha&);
	Fecha& operator = (Fecha&);
	~Fecha();
};
