#include "Herramienta.h"

char leerCaracter() {
	string line;
	char x;
	while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
		cout << "\t Ingrese solo un caracter..." << endl;
	x = line[0];
	while ((isalpha(x) == 0)) {
		cout << "Dato invalido" << endl;
		while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
			cout << "Ingrese solo un caracter..." << endl;
		x = line[0];
	}
	return x;
}

void imprimirCadena(string cadena) {
	cout << cadena << endl;;
}

void imprimirCaracter(char cadena) {
	cout << cadena << endl;;
}

int numeroCodigo(string codigo) {
	string numero = "";
	int n = 0, i;
	char caracter = ' ';
	int limite = (codigo.length()); 
	for (i=2; i <= limite; i++) {
		caracter = codigo[i];
		numero = numero + caracter;
		caracter = ' ';
	}
	n = stoi(numero);
	return n;
}

void limpiaPantalla() {
	system("clear");
}

string menuPrincipalito() {
	stringstream s;
	s << "\t                                                                 " << endl;
	s << "\t           B I E N V E N I D O   A   L A   E M P R E S A         " << endl;
	s << "\t            L A   M A Q U I N A   D E L   T I E M P O            " << endl;
	s << "\t _______________________________________________________________ " << endl;
	s << "\t|                Menu Maquina Expendedora Saludable             |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	s << "\t| 1.Menu Administrador.                                         |" << endl;
	s << "\t| 2.Menu de Cobro.                                              |" << endl;
	s << "\t| 3.Salir.                                                      |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	return s.str();
}

string menuAdministrador() {
	stringstream s;
	s << "\t _______________________________________________________________ " << endl;
	s << "\t|                 Menu Administrador De La Maquina              |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	s << "\t| 1.Insertar.                                                   |" << endl;
	s << "\t| 2.Modificar.                                                  |" << endl;
	s << "\t| 3.Borrar Informacion.                                         |" << endl;
	s << "\t| 4.Ingresar Dinero.                                            |" << endl;
	s << "\t| 5.Retirar Dinero.                                             |" << endl;
	s << "\t| 6.Salir.                                                      |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	return s.str();
}

string menuCobro() {
	stringstream s;
	s << "\t _______________________________________________________________ " << endl;
	s << "\t|                     Menu Cobro De La Maquina                  |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	s << "\t| 1.Mostrar Producto.                                           |" << endl;
	s << "\t| 2.Realizar Compra.                                            |" << endl;
	s << "\t| 3.Salir.                                                      |" << endl;
	s << "\t|_______________________________________________________________|" << endl;
	return s.str();
}

string leerCadena() {
	string x;
	cout << "\t";
	getline(cin, x);
	return x;
}

int leerEntero() {
	int n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

}

bool leerBooleano() {
	bool n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

double leerDecimal() {
	double n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

float leerFlotante() {
	float n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

int leerSeleccion(int mayor) {
	int entrada = 0;
	while (true) {
		cout << "\t";
		if (cin >> entrada) {

			if (entrada <= mayor && entrada != 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				return entrada;
			}else {
				cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}else {
			cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

