#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Librerias.h"
#include "ColeccionProducto.h"
#include "MonederoElectronico.h"
#include "IMaquinaVendedora.h"
#include "IMaquinaAdministradora.h"
using namespace std;

class Maquina : public IMaquinaAdministradora, public IMaquinaVendedora {
private:
	int identificador;
	string nombre;
	ColeccionProducto* colecPro;
	MonederoElectronico* mone;
public:
	Maquina(int = 0, string = "");
	virtual int getIdentificador();
	virtual string getNombre();
	virtual MonederoElectronico* getMonedero();
	virtual void validarAdmin(string);
	virtual void validarAdminDistinto(string);
	virtual void validarCobro(int);
	virtual void validarCobroDistinto(int);
	virtual void setIdentificador(int);
	virtual void setNombre(string);
	virtual void setMonedero(MonederoElectronico*);
	virtual void insertarPerecedero(string, int, int, string, Fecha*);
	virtual void insertarNoPerecedero(int, int, string, string);
	virtual void ingresarDinero(int);
	virtual string realizarCompra(string, int, int); //PrincipioResponsabilidadUnica (*)
	virtual void agregarProvisiones(string, int);
	virtual void disminuirProvisiones(string, int);
	virtual void borrar(string);
	virtual void retirarDinero(int);
	virtual void desgloVuelto(int);
	virtual void modificarDatosProducto(string, string, int, string);
	virtual Producto* consultar(string);
	virtual Producto* devuelveProducto(int);
	virtual void mostrarColeccion();
	virtual string toString();
	virtual ~Maquina();
};



