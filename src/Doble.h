#ifndef DOBLE_H
#define DOBLE_H

#include <string>
#include "Operando.h"
using namespace std;

class Doble: public Operando {
	private:
		double valor;

	public:
		Doble();
		Doble(double d);
		~Doble();
		string toString();
		Doble operator+(const Doble &);
		Doble operator-(const Doble &);
		Doble operator*(const Doble &);
		Doble operator/(const Doble &);
		// Métodos usados por los friend para hacer entrada salida
		virtual istream& cargar(istream &) override;
		virtual ostream& toString(ostream &) override;
};

#endif