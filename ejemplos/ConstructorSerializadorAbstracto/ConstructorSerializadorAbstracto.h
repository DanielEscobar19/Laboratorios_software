#pragma once

#include <string>
#include <utility>
using namespace std;

#include "Entero.h"
#include "Doble.h"

class ConstructorSerializadorAbstracto
{
public:
	ConstructorSerializadorAbstracto() {};
	~ConstructorSerializadorAbstracto() {};

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) = 0;
	virtual void finObjeto() = 0;
	virtual void serializarEntero(const pair< string, Valor* >& pe) = 0;
	virtual void serializarDoble(const pair< string, Valor* >& pd) = 0;
	virtual string obtSerializacion() = 0;
};

