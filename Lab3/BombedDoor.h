#include <sstream>
using namespace std;

#include "Door.h"

#if !defined(_BOMBEDDOOR_H)
#define _BOMBEDDOOR_H

class BombedDoor : public Door {
public:
	BombedDoor();
	~BombedDoor();
	void getAtributos(vector< pair< string, string > >& vectorValores) override;

	void enter() override;

private:

};

int MapSite::idg = 0;

BombedDoor::BombedDoor()
{
	MapSite::setType("puerta con bomba");
}

BombedDoor::~BombedDoor()
{
}

void BombedDoor::enter()
{
	cout << "agente pasa por " << MapSite::getType() << endl;
}


void BombedDoor::getAtributos(vector< pair< string, string > >& vectorValores) {

}

#endif  //_BOMBEDDOOR_H
