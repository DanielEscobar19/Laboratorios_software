#include "ConstructorSerializadorConcretoXML.h"
#include <string>
#include "MapSite.h"

ConstructorSerializadorXML::ConstructorSerializadorXML() : serializacion("") , nombreObjeto("")
{}

ConstructorSerializadorXML::~ConstructorSerializadorXML()
{}

void ConstructorSerializadorXML::inicioObjeto(string nombreObjeto) {
	serializacion += '<' + nombreObjeto + '>';
  this->nombreObjeto = nombreObjeto;
}

void ConstructorSerializadorXML::finObjeto() {
	serializacion += "\n</" + this->nombreObjeto + '>';
}

void ConstructorSerializadorXML::serializarRoom(Room* room) {
	serializacion += "\n<Room";
	serializacion += " type" + '=' + '\"' + room->getType() + '\"';
	serializacion += " id" + '=' + '\"' + room->getId() + '\"';

	this->serializarLado(MapSite::Direction::North, room);
  this->serializarLado(MapSite::Direction::South, room);
  this->serializarLado(MapSite::Direction::East, room);
  this->serializarLado(MapSite::Direction::West, room);
}

void ConstructorSerializadorXML::serializarLado(MapSite::Direction direction, Room* room) {
	MapSite* side = nullptr;

  // verifica si la sala tiene el lado.
  if (side = room->GetSide(direction)) {
    // verifica si es una puerta
    Door* doorPtr = dynamic_cast<Door*>(side);
    if(doorPtr) {
			// serializa la puerta
      this->serializarDoor(doorPtr);
    } else {
    		// verifica si es una pared
        Wall* wallPtr = dynamic_cast<Wall*>(side);
        if (wallPtr) {
					// serializa la pared
          this->serializarWall(wallPtr);
      }
    }
  }
	side = nullptr;
}

void ConstructorSerializadorXML::serializarDoor(Door* door) {
	
}

void ConstructorSerializadorXML::serializarWall(Wall* wall) {
	
}

string ConstructorSerializadorXML::obtSerializacion() {
	return serializacion;
}

