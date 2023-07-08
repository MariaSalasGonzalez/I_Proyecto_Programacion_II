#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Librerias.h"
#include "Producto.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
using namespace std;

// Principios de Diseño - Explicacion
// - ABIERTO / CERRADO : este principio se cumple en esta clase ColeccionProducto del codigo ya que
// la clase coleccion no sirve solo para producto, sino para cualquier otro tipo de aplicacion,
// en cualquier otro programa esto quiere decir que los metodos de esta clase sirven para cualquier
// otro objeto.

class ColeccionProducto {
private:
	Producto** vecProducto;
	int can;
	int tam;
public:
	ColeccionProducto(int = 0);
	int getCan() const;
	int getTam( )const;
	Producto **getVecProducto() const;
	void setCan(int);
	void setTam(int);
	void insertarProducto(Producto*);
	bool buscarProducto(string);
	Producto* buscarPorPosicion(int);
	Producto* buscarPorCodigo(string);
	Producto* buscarPorCodigo2(string);
	void acomodoVector(int);
	string eliminarXCodigo(string);
	bool eliminarXNombre(string);
	string mostrar();
	void mostrarProducto();
	virtual string toString();
	virtual ~ColeccionProducto();
};

