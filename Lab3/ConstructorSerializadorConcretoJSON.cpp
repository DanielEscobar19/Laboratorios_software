#include "ConstructorSerializadorConcretoJSON.h"
#include <string>
#include "MapSite.h"

ConstructorSerializadorJSON::ConstructorSerializadorJSON()
{}


ConstructorSerializadorJSON::~ConstructorSerializadorJSON()
{}

void ConstructorSerializadorJSON::inicioObjeto(string nombreObjeto) {
	serializacion = '{';
}

void ConstructorSerializadorJSON::finObjeto() {
	serializacion = serializacion + "\n}";
}

void ConstructorSerializadorJSON::serializarRoom(Room* room) {
  serializacion = serializacion + "\"Room\" : {";
  serializacion = serializacion + " \"Type\" : \"" + room->getType() + "\",";
  serializacion = serializacion + " \"id\" :" + to_string(room->getId()) + '}';
  this->serializarLado(MapSite::Direction::North, room);
  this->serializarLado(MapSite::Direction::South, room);
  this->serializarLado(MapSite::Direction::East, room);
  this->serializarLado(MapSite::Direction::West, room);
}

void ConstructorSerializadorJSON::serializarLado(MapSite::Direction direction, Room* room) {
  MapSite* side = room->GetSide(direction);

  // verifica si la sala tiene el lado.
  if (side) {
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

void ConstructorSerializadorJSON::serializarDoor(Door* door) {

}

void ConstructorSerializadorJSON::serializarWall(Wall* wall) {

}

string ConstructorSerializadorJSON::obtSerializacion() {
	return serializacion;
}