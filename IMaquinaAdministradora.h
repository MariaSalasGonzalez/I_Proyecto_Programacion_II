#pragma once
#include <sstream>
#include "Producto.h"
using namespace std;

// Principios de Diseño - Explicacion
// - INVERSION DE DEPENDENCIAS : este principio se cumple en esta parte del codigo ya que
// esta clase hereda todos sus metodos a maquina y las clases mas superficiales se conectan
// con esta clase y no con maquina.

class IMaquinaAdministradora {
public:
	virtual int getIdentificador() = 0;
	virtual string getNombre() = 0;
	virtual void setNombre(string) = 0;
	virtual void insertarPerecedero(string, int, int, string, Fecha*) = 0;
	virtual void insertarNoPerecedero(int, int, string, string) = 0;
	virtual void agregarProvisiones(string, int) = 0;
	virtual void ingresarDinero(int) = 0;
	virtual void retirarDinero(int) = 0;
	virtual void mostrarColeccion() = 0;
	virtual void disminuirProvisiones(string, int) = 0;
	virtual void borrar(string) = 0;
	virtual void modificarDatosProducto(string, string, int, string) = 0;
	virtual void validarAdmin(string) = 0;
	virtual void validarAdminDistinto(string) = 0;
	virtual Producto* consultar(string) = 0;
	virtual string toString() = 0;
};


