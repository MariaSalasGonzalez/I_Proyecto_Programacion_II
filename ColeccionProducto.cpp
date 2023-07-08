#include "ColeccionProducto.h"

ColeccionProducto::ColeccionProducto(int tam) : can(0), tam(tam), vecProducto(new Producto*[tam]) {
	for (int i = 0; i < tam; i++) {
		vecProducto[i] = nullptr;
	}
}

int ColeccionProducto::getCan() const{
	return can;
}

int ColeccionProducto::getTam() const{
	return tam;
}

Producto** ColeccionProducto::getVecProducto() const{
	return vecProducto;
}

void ColeccionProducto::setCan(int can) {
	ColeccionProducto::can = can;
}

void ColeccionProducto::setTam(int tam) {
	ColeccionProducto::tam = tam;
}

void ColeccionProducto::insertarProducto(Producto *pro) {
	if (getCan() <= getTam()) {
		vecProducto[can] = pro;
		setCan(getCan() + 1);
	}
}

string ColeccionProducto::eliminarXCodigo(string idProducto) {
	for (int i = 0; i < getCan(); i++) {
		if (vecProducto[i]->getIdProducto() == idProducto) {
			delete vecProducto[i];
			acomodoVector(i);
			setCan(getCan() - 1);
			return "Producto Eliminado";
		}
	}
	return "Producto No Encontrada";
}

bool ColeccionProducto::eliminarXNombre(string nombre) {
	for (int i = 0; i < getCan(); i++) {
		if (vecProducto[i]->getNombre() == nombre) {
			vecProducto[i] = nullptr;
			delete vecProducto[i];
			return true;
		}
	}
	return false;
}

void ColeccionProducto::acomodoVector(int posicion) {
	for (int i = 0; i < getCan(); i++) {
		vecProducto[i] = vecProducto[i + 1];
	}
	vecProducto[getCan() - 1] = nullptr;
}

bool ColeccionProducto::buscarProducto(string idProducto) {
	for (int i = 0; i < getCan(); i++) {
		if (vecProducto[i]->getIdProducto() == idProducto) {
			return true;
		}
	}
	return false;
}

Producto* ColeccionProducto::buscarPorPosicion(int pos) {
	if (pos <= getCan()) {
				return vecProducto[pos];
	}else{
		return nullptr;
	}
}

Producto* ColeccionProducto::buscarPorCodigo(string id) {
		for (int i = 0; i < getCan(); i++) {
			if (vecProducto[i]->getIdProducto() == id) {
				return vecProducto[i];
			}
		}
	return nullptr;
}

Producto* ColeccionProducto::buscarPorCodigo2(string id) {
	for (int i = 0; i <= getCan(); i++) {
		if (vecProducto[i]->getIdProducto() == id) {
			return vecProducto[i];
		}
	}
	return nullptr;
}

string ColeccionProducto::mostrar() {
	stringstream ss;
	try {
		int i = 0;
		if (can > 0) {
			ss << "Los productos son los siguientes: " << endl << endl;
			for (int i = 0; i < getCan(); i++) {
				ss << vecProducto[i]->toString() << endl;
			}
		}else {
			throw "No hay productos en la maquina. \n";
		}
	}
	catch (const char* error) {
		ss << error << endl;
	}
	return ss.str();
}

void ColeccionProducto::mostrarProducto() {
	for (int i = 0; i < getCan(); i++) {
			cout << vecProducto[i];
		}
}

// - RESPONSABILIDAD UNICA : este principio se cumple aca en el toString de la clase
// coleccionProducto ya que este metodo unicamente tiene una una sola
// funcionalidad y es retornar los datos de las posiciones de la coleccion.
string ColeccionProducto::toString() {
	stringstream ss;
	for (int i = 0; i < can; i++) {
		ss << vecProducto[i]->toString() << endl;
	}
	return ss.str();
}

ColeccionProducto::~ColeccionProducto() {
	if (vecProducto != nullptr) {
		delete vecProducto;
	}
}


