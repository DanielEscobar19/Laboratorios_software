#ifndef SERIALIZADOR_JSON_H
#define SERIALIZADOR_JSON_H

using namespace std;

#include "ConstructorSerializadorAbstracto.h"
#include <string>
#include "MapSite.h"

class ConstructorSerializadorJSON : public ConstructorSerializadorAbstracto {
public:
	ConstructorSerializadorJSON();
	~ConstructorSerializadorJSON();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarRoom(Room* room) override;
  void serializarLado(MapSite::Direction direction, Room* room);
	virtual void serializarDoor(Door* door ) override;
	virtual void serializarWall(Wall* wall) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // producto del constructor
};
#endif  // SERIALIZADOR_JSON_H