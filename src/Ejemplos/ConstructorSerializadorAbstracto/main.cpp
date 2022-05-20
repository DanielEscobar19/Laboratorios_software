#include <iostream>
#include <map>
#include <utility>
using namespace std;

#include "tipo.h"
#include "Criatura.h"
#include "ConstructorSerializadorXML.h"
#include "ConstructorSerializadorJSON.h"

string director(ConstructorSerializadorAbstracto& cs, const Criatura c);

int main()
{
	Criatura c0;
	cout << "atributos de la criatura 0: " << endl;
	cout << c0.obtEdad() << endl;
	cout << c0.obtEnergia() << endl;

	Criatura c1(7, 4.5);
	cout << "atributos de la criatura 1: " << endl;
	cout << c1.obtEdad() << endl;
	cout << c1.obtEnergia() << endl;

	c1.asgEdad(6);
	c1.asgEnergia(3.5);
	cout << "atributos de la criatura 1 modificada: " << endl;
	cout << c1.obtEdad() << endl;
	cout << c1.obtEnergia() << endl;

	cout << "Ahora usando el serializador XML: " << endl;
	ConstructorSerializadorAbstracto* cs_xml = new ConstructorSerializadorXML(); // se crea el serializador
	cout << director(*cs_xml,c0) << endl;

	cout << "Ahora usando el serializador JSON: " << endl;
	ConstructorSerializadorAbstracto* cs_json = new ConstructorSerializadorJSON(); // se crea el serializador
	cout << director(*cs_json, c1) << endl;
	cin.ignore();
}

string director(ConstructorSerializadorAbstracto& cs, const Criatura c)
{
	vector< pair< string, Valor* > >  vv;
	c.obtAtributos(vv); // se obtiene el vector de atributos
	cs.inicioObjeto(string("Criatura"));
	for (auto v : vv)
		switch (v.second->obtTipo())
		{
		case tipo::Entero: cs.serializarEntero(v);
			break;
		case tipo::Doble: cs.serializarDoble(v);
			break;
		}
	cs.finObjeto();
	return cs.obtSerializacion();
}