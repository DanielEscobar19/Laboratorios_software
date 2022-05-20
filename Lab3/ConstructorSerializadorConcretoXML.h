#ifndef SERIALIZADOR_XML_H
#define SERIALIZADOR_XML_H

using namespace std;

#include "ConstructorSerializadorAbstracto.h"

class ConstructorSerializadorXML : public ConstructorSerializadorAbstracto {
public:
	ConstructorSerializadorXML();
	~ConstructorSerializadorXML();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;

	virtual void serializarRoom(Room* room) override;
  void serializarLado(MapSite::Direction direction, Room* room);
	virtual void serializarDoor(Door* door ) override;
	virtual void serializarWall(Wall* wall) override;

	virtual string obtSerializacion() override;

private:
	string serializacion; // el producto del Constructor
	string nombreObjeto;
};

#endif  // SERIALIZADOR_XML_H
