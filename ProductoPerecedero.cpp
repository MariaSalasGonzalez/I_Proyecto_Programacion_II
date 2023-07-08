#include "ProductoPerecedero.h"

ProductoPerecedero::ProductoPerecedero(string nombre, int precio, int can, string idPro, Fecha* FV) :
	fechaDeVencimiento(FV), Producto(nombre, precio, can, idPro) {}

ProductoPerecedero::ProductoPerecedero() : fechaDeVencimiento(nullptr), Producto("", 0, 0, "") {}

int ProductoPerecedero::getPrecio() {
	return precio;
}

void ProductoPerecedero::setPrecio(int pre) {
	ProductoPerecedero::precio = pre;
}

void ProductoPerecedero::descuentoProducto() {
	int contador = 0;
	int dia, mes, anio = 0;
	time_t t = time(nullptr);
	struct tm today = *localtime(&t);
	dia = today.tm_mday;
	mes = today.tm_mon + 1;
	anio = (today.tm_year + 1900);
	if (mes == fechaDeVencimiento->getMes()) {
		if (fechaDeVencimiento->getDia() - dia <= 7) {
			setPrecio(getPrecio() / 2);
		}
	}else {
		int diferenciaDias = 0;
		if (fechaDeVencimiento->getMes() == 2) {
			diferenciaDias = 28 - fechaDeVencimiento->getDia() + dia;
			if (diferenciaDias <= 7) {
				setPrecio(getPrecio() / 2);
			}
		}
		if (fechaDeVencimiento->getMes() == 4 || 6 || 9 || 11) {
			diferenciaDias = 30 - fechaDeVencimiento->getDia() + dia;
			if (diferenciaDias <= 7) {
				setPrecio(getPrecio() / 2);
			}
		}
		if (fechaDeVencimiento->getMes() == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			diferenciaDias = 31 - fechaDeVencimiento->getDia() + dia;
			if (diferenciaDias <= 7) {
				setPrecio(getPrecio() / 2);
			}
		}
	}
}

string ProductoPerecedero::toString() {
	stringstream ss;
	ss << "     Producto Perecedero    " << endl;
	ss << Producto::toString() << endl;
	ss << " Fecha De Vencimiento" << endl;
	ss << fechaDeVencimiento->toString() << endl;
	return ss.str();
}

ostream& operator << (ostream& out, ProductoPerecedero& prope) {
	return out << "Fecha De Vencimiento =" << prope.fechaDeVencimiento << endl;
}

ProductoPerecedero& ProductoPerecedero::operator = (ProductoPerecedero& prope) {
	if (this != &prope) {
		fechaDeVencimiento = prope.fechaDeVencimiento;
		Producto::operator=(prope);
	}
	return *this;
}

ProductoPerecedero::~ProductoPerecedero() {

}

