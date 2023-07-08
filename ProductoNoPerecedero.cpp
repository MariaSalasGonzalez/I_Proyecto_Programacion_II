#include "ProductoNoPerecedero.h"

ProductoNoPerecedero::ProductoNoPerecedero(string nombre, int precio, int cantidad, string idProducto, float porDes) :
	porcentajeDescuento(porDes), Producto(nombre, precio, cantidad, idProducto) {}

ProductoNoPerecedero::ProductoNoPerecedero() : porcentajeDescuento(0), Producto("", 0, 0, "") {}

int ProductoNoPerecedero::getPrecio() {
	return precio;
}

void ProductoNoPerecedero::setPrecio(int precio) {
	this->precio = precio;
}

void ProductoNoPerecedero::descuentoProducto() {
}

string ProductoNoPerecedero::toString() {
	stringstream ss;
	ss << "             Producto No Perecedero             " << endl;
	ss << Producto::toString() << endl;
	ss << " Porcentaje de Descuento: " << porcentajeDescuento<< endl;
	return ss.str();
}

ostream& operator <<(ostream& out, ProductoNoPerecedero& proNoPe) {
	return out << " Porcentaje de Descuento=" << proNoPe.porcentajeDescuento << endl;
}

ProductoNoPerecedero& ProductoNoPerecedero::operator = (ProductoNoPerecedero& proNoPe) {
	if (this != &proNoPe) {
		porcentajeDescuento = proNoPe.porcentajeDescuento;
	}
	return *this;
}


