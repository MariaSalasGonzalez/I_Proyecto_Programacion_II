#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "IMaquinaVendedora.h"
#include "Producto.h"
#include "Herramienta.h"
using namespace std;

// Principios de Diseño - Explicacion
// - SEGREGACION DE INTERFACES : este principio se cumple en esta parte del codigo ya que
// los usuarios solo interactuan con los metodos de los menus y solo ven lo que los 
// metodos de menu muestran sin conocer codigo mas profundo, como los de producto
// o como los metodos de maquina

class MenuCobro {
private:
	IMaquinaVendedora* maquinitaVende;
public:
	MenuCobro(IMaquinaVendedora*);
	MenuCobro();
	void menuMetodos();
	void mostrar();
	string compra();
	virtual ~MenuCobro();
};


