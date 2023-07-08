#pragma once 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <fstream>
#include <time.h>
#include <stdio.h>
using namespace std;

class Producto {
protected:
	string nombre;
	int precio;
	int cantidad;
	string idProducto;
public:
	Producto(string = "", int = 0, int = 0, string = "");
	virtual void setNombre(const string&);
	virtual void setCantidad(int);
	virtual void setPrecio(int);
	virtual void setIdProducto(const string&);
	virtual const string &getNombre() const;
	virtual int getPrecio() = 0;
	virtual int getCantidad() const;
	virtual const string &getIdProducto() const;
	virtual void descuentoProducto() = 0;
	virtual string toString();
	friend ostream& operator << (ostream&, Producto&);
	Producto& operator = (Producto&);
	virtual ~Producto();
};


