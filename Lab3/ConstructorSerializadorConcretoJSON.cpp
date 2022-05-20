#include "ConstructorSerializadorConcretoJSON.h"
#include <string>
#include "MapSite.h"

ConstructorSerializadorJSON::ConstructorSerializadorJSON()
{}


ConstructorSerializadorJSON::~ConstructorSerializadorJSON()
{}

void ConstructorSerializadorJSON::inicioObjeto(string nombreObjeto)
{
	serializacion = "{ ";
}

void ConstructorSerializadorJSON::finObjeto()
{
	serializacion += "}";
}

void ConstructorSerializadorJSON::serializarRoom(Room* room)
{
  serializacion += "Room : {";
  serializacion += " \"Type\":" + room->getType() + ", ";
  serializacion += " \"id\":" + room->getType() + "}";
  this->serializarLado(MapSite::Direction::North, room);
  this->serializarLado(MapSite::Direction::South, room);
  this->serializarLado(MapSite::Direction::East, room);
  this->serializarLado(MapSite::Direction::West, room);
}

void ConstructorSerializadorJSON::serializarLado(MapSite::Direction direction, Room* room) {
  MapSite* side = nullptr;

  // verifica si la sala tiene el lado.
  if (side = room->GetSide(direction)) {
    // verifica si es una puerta
    Door* doorPtr = dynamic_cast<Door*>(side);
    if(doorPtr) {
      this->serializarDoor(doorPtr);
    } else {
        Wall* wallPtr = dynamic_cast<Wall*>(side);
        if (wallPtr) {
          this->serializarWall(wallPtr);
      }
    }
  }
}

void ConstructorSerializadorJSON::serializarDoor(Door* door) {

}

void ConstructorSerializadorJSON::serializarWall(Wall* wall) {

}

string ConstructorSerializadorJSON::obtSerializacion() {
	return serializacion;
}