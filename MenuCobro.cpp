#include "MenuCobro.h"

MenuCobro::MenuCobro(IMaquinaVendedora* maquinita) : maquinitaVende(maquinita) {}

MenuCobro::MenuCobro(): maquinitaVende(nullptr) {}

void MenuCobro::menuMetodos() {
	int opcion = 0;
	limpiaPantalla();
	do{
		imprimirCadena("            Menu Cobro            ");
		imprimirCadena(" Las opciones del Menu Cobro son: ");
		imprimirCadena(" 1 : Realizar Compra              ");
		imprimirCadena(" 2 : Mostrar los Productos        ");
		imprimirCadena(" 3 : Salir                        ");
		imprimirCadena("\t Seleccione una opcion [1-3]:   ");
		opcion = leerEntero();
		switch (opcion) {
		case 1:
			compra();
			break;
		case 2:
			mostrar();
			break;
		case 3:
			imprimirCadena(" Ha salido del Menu Compra.");
			break;
		default:
			imprimirCadena(" La opcion seleccionada no existe.");
			break;
		}
	} while (opcion != 3);
}

void MenuCobro::mostrar() {
	imprimirCadena(" Mostrando los datos. ");
	cout << maquinitaVende->toString();
}

string MenuCobro::compra() {
	string nombre = "", opcion = "";
	int pos = 0, cant = 0, monto = 0;;
	bool decision = false, decision1 = false;
	Producto* aux = nullptr;
	do {
		imprimirCadena(" Digite la posicion del producto. ");
		pos = leerEntero();
		try {
			maquinitaVende->validarCobro(pos);
			aux = maquinitaVende->devuelveProducto(pos);
				if (aux != nullptr) {
					cout << aux->toString() << endl;
				}else {
					cout << " El puntero esta vacio." << endl;	
				}
			imprimirCadena(" ¿Cuantos productos quiere comprar?.");
			cant = leerEntero();
			imprimirCadena(" ¿Desea continuar con la compra? Digite 1 si desea seguir, 0 si desea abortar. ");
			decision = leerBooleano();
			if (decision == true) {
				imprimirCadena(" Ingrese el dinero. ");
				monto = leerEntero();
				imprimirCadena(" ¿Esta seguro que desea continuar con la compra?.");
				decision = leerBooleano();
				if (decision == true) {
					nombre = aux->getIdProducto();
					cout << aux->toString() << endl;
					cout << maquinitaVende->realizarCompra(nombre, cant, monto);
				}else {
					return " Compra abortada. \n";
				}
			}else {
				return " Compra abortada. \n";
			}
		}
		catch (const char* excepcion) {
			return excepcion;
		}
		imprimirCadena(" ¿Desea realizar otra compra?. \n\n");
		imprimirCadena(" Digite 'si' o 'no'.\n ");
		opcion = leerCadena();
	} while (opcion == "si");
	return " Gracias por ser saludable y comprar aqui. \n";
}

MenuCobro::~MenuCobro() {
	delete maquinitaVende;
}


