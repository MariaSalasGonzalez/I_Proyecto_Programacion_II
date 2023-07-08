#include "Maquina.h"

Maquina::Maquina(int ide, string nom) : identificador(ide), nombre(nom), colecPro(new ColeccionProducto[100]),
mone(new MonederoElectronico(10000)) {}

int Maquina::getIdentificador() {
	return identificador;
}

string Maquina::getNombre() {
	return nombre;
}

MonederoElectronico* Maquina::getMonedero() {
	return mone;
}

void Maquina::setIdentificador(int ide) {
	this->identificador = ide;
}

void Maquina::setNombre(string nom) {
	this->nombre = nom;
}

void Maquina::setMonedero(MonederoElectronico* mon) {
	this->mone = mon;
}

void Maquina::mostrarColeccion() {
	cout << toString();
}

// Principios de Diseño - Explicacion (*)
// RESPONSABILIDAD UNICA : este principio se cumple aca ya que la unica responsabilidad
// de esto es trabajar con la coleccion, usar, modificar y retornar alguno de los datos
// que maneja la coleccion

string Maquina::realizarCompra(string idProducto, int cantidad, int montoPago) {
	stringstream s;
	Producto* aux = nullptr;
	int dineroAPagar = 0;
	aux = colecPro->buscarPorCodigo2(idProducto);
	dineroAPagar = aux->getPrecio() * cantidad;
	if (montoPago < dineroAPagar || cantidad > aux->getCantidad()) {
		s << " Su compra ha fracasado, no tiene suficiente dinero" << endl;
	}else {
		int vuelto = 0;
		ingresarDinero(montoPago);
		disminuirProvisiones(idProducto, cantidad);
		vuelto = montoPago - dineroAPagar;
		retirarDinero(vuelto);
		s << mone->desgloceVuelto(vuelto) << endl;
		s << " La compra fue exitosa" << endl;
		s << " Provisiones del producto restante: " << aux->getCantidad() << endl;
	}
	return s.str();
}

void Maquina::insertarPerecedero(string nom, int pre, int cant, string idProducto, Fecha* FV) {
	Producto* pro = new ProductoPerecedero(nom, pre, cant, idProducto, FV);
	colecPro->insertarProducto(pro);

}

void Maquina::insertarNoPerecedero(int pre, int cant, string nom, string idProducto) {
	Producto* pro = new ProductoNoPerecedero(nom, pre, cant, idProducto);
	colecPro->insertarProducto(pro);
}

void Maquina::agregarProvisiones(string idProducto, int can) {
	Producto* aux = nullptr;
	aux = colecPro->buscarPorCodigo(idProducto);
	aux->setCantidad(aux->getCantidad() + can);
}

void Maquina::disminuirProvisiones(string idProducto, int can) {
	Producto* aux = nullptr;
	aux = colecPro->buscarPorCodigo(idProducto);
	if (can > aux->getCantidad()) {
		aux->setCantidad(aux->getCantidad() - can);
	}
}

void Maquina::modificarDatosProducto(string nom, string idProduc, int pre, string idmodificar) {
	Producto* aux = nullptr;
	aux = consultar(idProduc);
	aux->setNombre(nom);
	aux->setPrecio(pre);
	aux->setIdProducto(idmodificar);
}

void Maquina::borrar(string idProducto) {
	colecPro->eliminarXCodigo(idProducto);
}

void Maquina::validarAdmin(string cod) {
	Producto* aux;
	aux = colecPro->buscarPorCodigo(cod);
	if (aux == nullptr) {
		throw " No se encontro el producto con ese codigo.\n";
	}
}

void Maquina::validarAdminDistinto(string cod) {
	Producto* aux;
	aux = colecPro->buscarPorCodigo(cod);
	if (aux != nullptr) {
		throw " Ya hay un producto con ese codigo.\n";
	}
}

void Maquina::validarCobro(int pos) {
	if (pos >= colecPro->getCan()) {
		throw " No se encontro el producto en esa posicion.\n";
	}
}

void Maquina::validarCobroDistinto(int pos) {
	Producto* aux;
	aux = colecPro->buscarPorPosicion(pos);
	if (aux != nullptr) {
		throw " Ya hay un producto con esa posicion.\n";
	}
}

Producto* Maquina::consultar(string idProducto) {
	return colecPro->buscarPorCodigo(idProducto);
}

void Maquina::ingresarDinero(int dineroNuevo) {
	mone->setDinero(mone->getDinero() + dineroNuevo);
}

void Maquina::retirarDinero(int vuelto) {
	mone->setDinero(mone->getDinero() - vuelto);
}

void Maquina::desgloVuelto(int vuelto) {
	cout << mone->desgloceVuelto(vuelto);
}

Producto* Maquina::devuelveProducto(int pos) {
	return colecPro->buscarPorPosicion(pos);
}

string Maquina::toString() {
	stringstream ss;
	ss << endl << endl;
	ss << "                   Datos de Maquina              " << endl;
	ss << " Identificador: " << getIdentificador() << endl;
	ss << " Nombre: " << getNombre() << endl;
	ss << " Monedero: " << getMonedero()->getDinero() << endl;
	ss << colecPro->mostrar() << endl;
	ss << endl << endl;
	return ss.str();
}

Maquina::~Maquina() {
	if (colecPro != nullptr) {
		delete[]colecPro;
		if (mone != nullptr) {
			delete mone;
		}
	}
}


