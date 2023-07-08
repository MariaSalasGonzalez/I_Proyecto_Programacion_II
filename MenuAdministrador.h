#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Librerias.h"
#include "Fecha.h"
#include "Maquina.h"
#include "Producto.h"
#include "ProductoNoPerecedero.h"
#include "ProductoPerecedero.h"
#include "Herramienta.h" 
using namespace std;

// Principios de Diseño - Explicacion
// - SEGREGACION DE INTERFACES : este principio se cumple en esta parte del codigo ya que
// los usuarios solo interactuan con los metodos de los menus y solo ven lo que los 
// metodos de menu muestran sin conocer codigo mas profundo, como los de producto
// o como los metodos de maquina

class MenuAdministrador {
private:
	int opc;
	IMaquinaAdministradora* maquinitaAdmi;
public:
	MenuAdministrador(IMaquinaAdministradora*);
	IMaquinaAdministradora* getMaquinaAdministradora();
	void insertarProductoPerecedero();
	void insertarProductoNoPerecedero();
	void ingresarDinero();
	void retirarDinero();
	void eliminarInfo();
	void modificar();
	void menuMetodos();
	virtual ~MenuAdministrador();
};
