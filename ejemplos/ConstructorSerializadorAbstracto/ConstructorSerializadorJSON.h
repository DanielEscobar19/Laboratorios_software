#pragma once

#include <sstream>
using namespace std;

#include "ConstructorSerializadorAbstracto.h"
#include "Valor.h"
class ConstructorSerializadorJSON : public ConstructorSerializadorAbstracto
{
public:
	ConstructorSerializadorJSON();
	~ConstructorSerializadorJSON();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarEntero(const pair< string, Valor* >& pe) override;
	virtual void serializarDoble(const pair< string, Valor* >& pd) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // producto del constructor
};

ConstructorSerializadorJSON::ConstructorSerializadorJSON()
{
}


ConstructorSerializadorJSON::~ConstructorSerializadorJSON()
{
}

void ConstructorSerializadorJSON::inicioObjeto(string nombreObjeto)
{
	serializacion = "{ ";
}

void ConstructorSerializadorJSON::finObjeto()
{
	serializacion = serializacion + "}";
}

void ConstructorSerializadorJSON::serializarEntero(const pair< string, Valor* >& pe)
{
	serializacion = serializacion + '"' + pe.first + '"' + ':' + pe.second->toString() + ", ";
}

void ConstructorSerializadorJSON::serializarDoble(const pair< string, Valor* >& pd)
{
	serializacion = serializacion + '"' + pd.first + '"' + ':' + pd.second->toString() + ", ";
}

string ConstructorSerializadorJSON::obtSerializacion()
{
	return serializacion;
}