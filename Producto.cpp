#include "Producto.h"

Producto::Producto(string nombre, int precio, int cantidad, string idProducto) : nombre(nombre), precio(precio),
cantidad(cantidad), idProducto(idProducto) {}

void Producto::setNombre(const string& nombre) {
	Producto::nombre = nombre;
}

void Producto::setCantidad(int cantidad) {
	Producto::cantidad = cantidad;
}

void Producto::setPrecio(int precio) {
	Producto::precio = precio;
}

void Producto::setIdProducto(const string &idProducto) {
	Producto::idProducto = idProducto;
}

const string& Producto::getNombre() const {
	return nombre;
}

int Producto::getCantidad() const {
	return cantidad;
}

int Producto::getPrecio() {
	return precio;
}

const string &Producto::getIdProducto() const {
	return idProducto;
}

string Producto::toString() {
	stringstream ss;
	ss << " Datos Generales de Producto" << endl;
	ss << "                            " << endl;
	ss << " Nombre: " << getNombre() << endl;
	ss << " Precio: " << getPrecio() << endl;
	ss << " Cantidad: " << getCantidad() << endl;
	ss << " Id del Producto: " << getIdProducto() << endl;
	return ss.str();
}

ostream& operator << (ostream& out, Producto& pro) {
	return out << "Nombre =" << pro.nombre << "Cantidad =" << pro.cantidad
		       << "Precio =" << pro.precio << endl;
}

Producto& Producto::operator = (Producto& pro) {
	if (this != &pro) {
		nombre = pro.nombre;
		cantidad = pro.cantidad;
		precio = pro.precio;
	}
	return *this;
}

Producto::~Producto() {
}

