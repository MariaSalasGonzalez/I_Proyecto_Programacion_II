#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(IMaquinaAdministradora* maquinita) : maquinitaAdmi(maquinita) {}

void MenuAdministrador::insertarProductoPerecedero() {
	int cont = 0, precio = 0, cantidad = 0, dia = 0, mes = 0, anio = 0;
	string resp = "", nombre = "", idProducto = "", tipo = "";
	Fecha* fec = nullptr;
	bool bandera28 = true, bandera30 = true, bandera31 = true;
	limpiaPantalla();
	do {
		limpiaPantalla();
		imprimirCadena("                                                            ");
		imprimirCadena("\t Bienvenido Al Sistema De Ingreso De Producto Perecedero\n");
		imprimirCadena("                                                            ");
		imprimirCadena("\t Digite el Id del Producto.");
		idProducto = leerCadena();
		try {
			maquinitaAdmi->validarAdminDistinto(idProducto);
			imprimirCadena("\t Digite el Nombre Del Producto.");
			nombre = leerCadena();
			imprimirCadena("\t Digite el Precio del Producto.");
			precio = leerEntero();
			imprimirCadena("\t Digite la Cantidad de Producto a ingresar.");
			cantidad = leerEntero();
			while (bandera28 == true || bandera30 == true || bandera31 == true || mes > 12) {
				imprimirCadena("\t Digite el dia de vencimiento.");
				dia = leerEntero();
				imprimirCadena("\t Digite el Mes de vencimiento.");
				mes = leerEntero();
				imprimirCadena("\t Digite el Anno de vencimiento");
				anio = leerEntero();
				if (mes == 2 && dia > 28) {
					imprimirCadena(" Febrero no tiene mas de 28 dias. \n");
					bandera28 = true;
				}else {
					bandera28 = false;
				}
				if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30)) {
					imprimirCadena(" Este mes no tiene mas de 30 dias. \n");
					bandera30 = true;
				}else {
					bandera30 = false;
				}
				if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia > 31)) {
					imprimirCadena(" Este mes no tiene mas de 31 dias. \n");
					bandera31 = true;
				}else {
					bandera31 = false;
				}
				if (bandera28 == true || bandera30 == true || bandera31 == true) {
					imprimirCadena(" Digite otra vez la fecha, gran estupido que pregunta, cual pandemia.");
				}
			}
			fec = new Fecha(dia, mes, anio);
			maquinitaAdmi->insertarPerecedero(nombre, precio, cantidad, idProducto, fec);
			imprimirCadena(" Desea insertar otro Producto Perecedero");
			resp = leerCadena();
			cont++;
		}
		catch (string excepcion) {
			cout << excepcion << endl;
		}
	} while (resp == "si" && cont < 2);
		
}

IMaquinaAdministradora* MenuAdministrador::getMaquinaAdministradora() {
	return maquinitaAdmi;
}

void MenuAdministrador::insertarProductoNoPerecedero() {
	int cont = 0, precio = 0, cantidad = 0;
	string resp = "", nombre = "", idProducto = "";
	float porcentajeDescuento = 0;
	Producto* pro = nullptr;
	limpiaPantalla();
	do {
		limpiaPantalla();
		imprimirCadena("                                                               ");
		imprimirCadena("\t Bienvenido Al Sistema De Ingreso De Producto No Perecedero\n");
		imprimirCadena("                                                               ");
		imprimirCadena("\t Digite el Id del Producto");
		idProducto = leerCadena();
		try {
			maquinitaAdmi->validarAdminDistinto(idProducto);
			imprimirCadena("\t Digite el Nombre Del Producto");
			nombre = leerCadena();
			imprimirCadena("\t Digite el Precio del Producto");
			precio = leerEntero();
			imprimirCadena("\t Digite la Cantidad de Producto a ingresar");
			cantidad = leerEntero();
			maquinitaAdmi->insertarNoPerecedero(precio, cantidad, nombre, idProducto);
			imprimirCadena(" Desea insertar otro Producto No Perecedero");
			imprimirCadena(" Responda 'si'.");
			resp = leerCadena();
			cont++;
		}
		catch (string excepcion) {
			cout << excepcion << endl;
		}
	} while (resp == "si" && cont < 2);
}

void MenuAdministrador::eliminarInfo() {
	string  idProducto = "", resp = "";
	int cont = 0;
	do {
		imprimirCadena("                                                   ");
		imprimirCadena("\t Bienvenido al Sistema de Eliminacion de Producto");
		imprimirCadena("                                                   ");
		imprimirCadena("\t Estos son los productos disponibles");
		maquinitaAdmi->mostrarColeccion();
		imprimirCadena("\t Digite el id del producto que desea eliminar.");
		idProducto = leerCadena();
		try {
			maquinitaAdmi->validarAdmin(idProducto);
			maquinitaAdmi->borrar(idProducto);
			imprimirCadena(" ¿Desea eliminar otro producto?.");
			resp = leerCadena();
			cont++;
		}
		catch (string excepcion) {
			cout << excepcion << endl;
		}
	} while (resp == "si" && cont < 2);
}

void MenuAdministrador::ingresarDinero() {
	int dinero = 0, cont = 0;
	string resp = "";
	limpiaPantalla();
	do {
		imprimirCadena("                                                  ");
		imprimirCadena("\tBienvenido al Sistema de Ingreso de Dinero      ");
		imprimirCadena("                                                  ");
		imprimirCadena(" Digite la cantidad de dinero que desea depositar.");
		dinero = leerEntero();
		maquinitaAdmi->ingresarDinero(dinero);
		imprimirCadena(" ¿Desea insertar mas dinero?");
		resp = leerCadena();
		cont++;
	} while (resp == "si" && cont < 2);
}

void MenuAdministrador::retirarDinero() {
	int dinero = 0, cont = 0;
	string resp = "";
	limpiaPantalla();
	do {
		imprimirCadena("                                                ");
		imprimirCadena("\t Bienvenido al Sistema de Retiro de Dinero    ");
		imprimirCadena("                                                ");
		imprimirCadena(" Digite la cantidad de dinero que desea retirar.");
		dinero = leerEntero();
		maquinitaAdmi->retirarDinero(dinero);
		imprimirCadena(" ¿Desea retirar mas dinero?.");
		resp = leerCadena();
		cont++;
	} while (resp == "si" && cont < 2);
}

void MenuAdministrador::modificar() {
	string idProducto = "", nombre = "", idmodificar = "";
	int precio = 0;
	maquinitaAdmi->mostrarColeccion(); 
	imprimirCadena(" Escriba el id del producto que desea modificar.\n");
	idProducto = leerCadena();
	try {
		imprimirCadena(" Escriba el nuevo nombre del producto.\n");
		nombre = leerCadena();
		imprimirCadena(" Escriba el nuevo precio del producto.\n");
		precio = leerEntero();
		imprimirCadena(" Escriba el nuevo id del producto.\n");
		idmodificar = leerEntero();
		maquinitaAdmi->modificarDatosProducto(nombre, idProducto, precio, idmodificar);
	}
	catch (string excepcion) {
		cout << excepcion << endl;
	}
}

void MenuAdministrador::menuMetodos() {
	int opcion = 0;
	while (opcion != 7) {
		imprimirCadena("            Menu Administrador            ");
		imprimirCadena(" Las opciones del Menu Administrador son: ");
		imprimirCadena(" 1 : Insertar Producto Perecedero         ");
		imprimirCadena(" 2 : Insertar Producto No Perecedero      ");
		imprimirCadena(" 3 : Eliminar Info                        ");
		imprimirCadena(" 4 : Ingresar Dinero                      ");
		imprimirCadena(" 5 : Retirar Dinero                       ");
		imprimirCadena(" 6 : Modificar                            ");
		imprimirCadena(" 7 : Salir                                ");
		imprimirCadena("\t Seleccione una opcion [1-7]: ");
		opcion = leerEntero();
		switch (opcion) {
		case 1:
			insertarProductoPerecedero();
			break;
		case 2:
			insertarProductoNoPerecedero();
			break;
		case 3:
			eliminarInfo();
			break;
		case 4:
			ingresarDinero();
			break;
		case 5:
			retirarDinero();
			break;
		case 6:
			modificar();
			break;
		case 7:
			imprimirCadena(" Ha salido del Menu Administrador.");
			break;
		default:
			imprimirCadena(" La opcion seleccionada no existe.");
			break;
		}
	}
}

MenuAdministrador::~MenuAdministrador() {
}

