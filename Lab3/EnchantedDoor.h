//
//
#include "Door.h"

#include <sstream>
using namespace std;

#if !defined(_ENCHANTEDDOOR_H)
#define _ENCHANTEDDOOR_H



class EnchantedDoor : public Door {
public:
	EnchantedDoor();
	~EnchantedDoor();
	void getAtributos(vector< pair< string, string > >& vectorValores) override;

	void enter() override;
};

EnchantedDoor::EnchantedDoor() {
	MapSite::setType("puerta encantada");
}

EnchantedDoor::~EnchantedDoor() {
}

void EnchantedDoor::enter()
{
	cout << "agente pasa por " << MapSite::getType() << endl;
}

void EnchantedDoor::getAtributos(vector< pair< string, string > >& vectorValores) {
	
}

#endif  //_ENCHANTEDDOOR_H
