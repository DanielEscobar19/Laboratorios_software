#include <sstream>
using namespace std;

#include "Door.h"

#if !defined(_BOMBEDDOOR_H)
#define _BOMBEDDOOR_H

class BombedDoor : public Door {
public:
	BombedDoor();
	~BombedDoor();

	void enter() override;

private:

};

int BombedDoor::idg = 0;

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

#endif  //_BOMBEDDOOR_H
