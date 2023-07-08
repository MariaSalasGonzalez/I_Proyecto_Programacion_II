#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal() : maquinitita(new Maquina(12345, " Maquina de productos saludables. ")),
               menucitoAd(new MenuAdministrador(maquinitita)), menucitoCo(new MenuCobro(maquinitita)) {
}

void MenuPrincipal::inicio() {
	limpiaPantalla();
	int opcion = 0;
	do {
		imprimirCadena(menuPrincipalito());
		imprimirCadena("\t Seleccione una opcion [1-3]: ");
		opcion = leerSeleccion(3);
		switch (opcion) {
		case 1:
			menucitoAd->menuMetodos();
			break;
		case 2:
			menucitoCo->menuMetodos();
			break;
		case 3:
			exit(0);
			break;
		}
	} while (true);
}

MenuPrincipal::~MenuPrincipal() {
	delete menucitoAd;
	delete menucitoCo;
}



