#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
#include "Fecha.h"
using namespace std;

class ProductoPerecedero : public Producto {
private:
	Fecha* fechaDeVencimiento;
public:
	ProductoPerecedero(string = "", int = 0, int = 0, string = "", Fecha* = NULL);
	ProductoPerecedero();
	virtual int getPrecio();
	virtual void setPrecio(int);
	virtual string toString();
	virtual void descuentoProducto();
	virtual ~ProductoPerecedero();
	friend ostream& operator <<(ostream&, ProductoPerecedero&);
	ProductoPerecedero& operator = (ProductoPerecedero&);
};

