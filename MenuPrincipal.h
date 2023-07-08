#include <iostream>
#include <sstream>
#include <string>
#include "Librerias.h"
#include "Herramienta.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
using namespace std;

class MenuPrincipal {
private:
	Maquina* maquinitita;
	MenuAdministrador* menucitoAd;
	MenuCobro* menucitoCo;
	int opcion;
public:
	MenuPrincipal();
	void inicio();
	virtual ~MenuPrincipal();
};

