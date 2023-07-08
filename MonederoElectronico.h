#include <iostream>
#include <sstream>
#include <string>
#include "Librerias.h"
using namespace std;

class MonederoElectronico {
private:
	int dinero;
public:
	MonederoElectronico(int = 0);
	void setDinero(int);
	int getDinero();
	string desgloceVuelto(int vuelto);
	string toString();
	~MonederoElectronico();
};


