#pragma once
#include <sstream>
#include "Producto.h"
using namespace std;

class IMaquinaVendedora {
public:
	virtual string getNombre() = 0;
	virtual string realizarCompra(string, int, int) = 0;
	virtual Producto* devuelveProducto(int) = 0;
	virtual void desgloVuelto(int) = 0;
	virtual void validarCobro(int) = 0;
	virtual void validarCobroDistinto(int) = 0;
	virtual void mostrarColeccion() = 0;
	virtual string toString() = 0;
};


