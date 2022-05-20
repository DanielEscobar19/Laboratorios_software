#pragma once

#include <sstream>
using namespace std;

#include "Valor.h"
#include "ConstructorSerializadorAbstracto.h"

class ConstructorSerializadorXML : public ConstructorSerializadorAbstracto
{
public:
	ConstructorSerializadorXML();
	~ConstructorSerializadorXML();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarEntero(const pair< string, Valor* >& pe) override;
	virtual void serializarDoble(const pair< string, Valor* >& pd) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // el producto del Constructor
};

ConstructorSerializadorXML::ConstructorSerializadorXML() : serializacion("")
{
}

ConstructorSerializadorXML::~ConstructorSerializadorXML()
{
}

void ConstructorSerializadorXML::inicioObjeto(string nombreObjeto)
{
	serializacion = serializacion + "< " + nombreObjeto + ' ';
}

void ConstructorSerializadorXML::finObjeto()
{
	serializacion = serializacion + ">";
}

void ConstructorSerializadorXML::serializarEntero(const pair< string, Valor* >& pe)
{
	serializacion = serializacion + pe.first + '=' + '"' + pe.second->toString() + '"' + ' ';
}

void ConstructorSerializadorXML::serializarDoble(const pair< string, Valor* >& pd)
{
	serializacion = serializacion + pd.first + '=' + '"' + pd.second->toString() + '"' + ' ';
}

string ConstructorSerializadorXML::obtSerializacion()
{
	return serializacion;
}