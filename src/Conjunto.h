#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>
#include "Operando.h"
#include <set>
#include <algorithm>

using namespace std;

class Conjunto : public Operando{
	private:
		set<int> valor;

	public:
		Conjunto();
		Conjunto(double d);
		~Conjunto();
		string toString();
		Conjunto& operator+(Operando &);
		Conjunto& operator-(Operando &);
		Conjunto& operator*(Operando &);
		Conjunto& operator/(Operando &);
};

#endif