#include <sstream>
using namespace std;

#include "Wall.h"

#if !defined(_BOMBEDWALL_H)
#define _BOMBEDWALL_H

class BombedWall : public Wall {
public:
	BombedWall();
	~BombedWall();

	void enter() override;
};

BombedWall::BombedWall() {
	MapSite::setType("pared con bomba");
}

BombedWall::~BombedWall() {

}

void BombedWall::enter()
{
	cout << "agente choca con " << MapSite::getType() << endl;
}

#endif  //_BOMBEDWALL_H
