#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoNoPerecedero : public Producto {
private:
	float porcentajeDescuento;
public:
	ProductoNoPerecedero(string nombre = "", int precio = 0, int cantidad = 0, string idProducto = "", float = 0);
	ProductoNoPerecedero();
	virtual int getPrecio();
	virtual void setPrecio(int);
	virtual void descuentoProducto();
	virtual string toString();
	friend ostream& operator <<(ostream&, ProductoNoPerecedero&);
	ProductoNoPerecedero& operator = (ProductoNoPerecedero&);
};
