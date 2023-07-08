#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(int dine) : dinero(dine) {
}

void MonederoElectronico::setDinero(int dine) {
	dinero = dine;
}

int MonederoElectronico::getDinero() {
	return dinero;
}

//Algoritmo de Kruskal
//string MonederoElectronico::desgloceVuelto(int &vuelto) {
//	int bill2 = 0, bill1 = 0, coin500 = 0, coin100 = 0;
//	stringstream ss;
//	while (vuelto > 0){
//		while (vuelto >= 2000) {
//			if (vuelto >= 2000) {
//				vuelto = vuelto - 2000;
//				bill2++;
//				ss << "Su vuelto contiene\t" << bill2 << "\tbillete(s) de 2000 colones" << endl;
//			}
//		}//fin 2_while
//		while (vuelto >= 1000) {
//			if (vuelto >= 1000) {
//				vuelto = vuelto - 1000;
//				bill1++;
//				ss << "Su vuelto contiene\t" << bill1 << "\tbillete(s) de 1000 colones" << endl;
//			}
//		}//fin 3_while
//		while (vuelto >= 500) {
//			if (vuelto >= 500) {
//				vuelto = vuelto - 500;
//				coin500++;
//				ss << "Su vuelto contiene\t" << coin500 << "\tmoneda(s) de 500 colones" << endl;
//			}
//		}//fin 4_while
//		while (vuelto >= 100) {
//			if (vuelto >= 100) {
//				vuelto = vuelto - 100;
//				if (coin100++) {
//					ss << "Su vuelto contiene\t" << coin100 << "\tmoneda(s) de 100 colones" << endl;
//				}
//			}
//		}//fin 5_while
//	}//fin 1_while
//	return ss.str();
//}

//Algoritmo de Primm
string MonederoElectronico::desgloceVuelto(int vuelto) {
	int bill1 = 0, bill2 = 0, coin100 = 0, coin500 = 0;
	stringstream s;
	while (vuelto > 0) {
		while (vuelto >= 2000) {
			if (vuelto >= 2000) {
				vuelto = vuelto - 2000;
				bill2++;
			}
		}//fin 2_while
		s << "Su vuelto contiene\t " << bill2 << "\tbilletes de 2000 colones" << endl;
		while (vuelto >= 1000) {
			if (vuelto >= 1000) {
				vuelto = vuelto - 1000;
				bill1++;
			}
		}//fin 3_while
		s << "Su vuelto contiene\t " << bill1 << "\tbilletes de 1000 colones" << endl;
		while (vuelto >= 500) {
			if (vuelto >= 500) {
				vuelto = vuelto - 500;
				coin500++;
			}
		}//fin 4_while
		s << "Su vuelto contiene\t " << coin500 << "\tmonedas de 500 colones" << endl;
		while (vuelto >= 100) {
			if (vuelto >= 100) {
				vuelto = vuelto - 100;
				coin100++;	
			}
		}//fin 5_while
		s << "Su vuelto contiene\t " << coin100 << "\tmoneda(s) de 100 colones" << endl;
	}//fin 1_while
	return s.str();
}

string MonederoElectronico::toString() {
	stringstream ss;
	ss << endl;
	ss << " Datos de Monedero Electronico " << endl;
	ss << " Dinero: " << getDinero() << endl;
	ss << endl;
	return ss.str();
}

MonederoElectronico::~MonederoElectronico() {
}

