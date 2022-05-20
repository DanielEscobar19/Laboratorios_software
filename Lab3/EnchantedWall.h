#include "Wall.h"

#if !defined(_ENCHANTEDWALL_H)
#define _ENCHANTEDWALL_H

class EnchantedWall : public Wall {
    public:
    EnchantedWall();
	~EnchantedWall();

    void enter() override;
};

EnchantedWall::EnchantedWall() {
    MapSite::setType("pared encantada");
}

EnchantedWall::~EnchantedWall() {
}

void EnchantedWall::enter()
{
    cout << "agente choca con " << MapSite::getType() << endl;
}
#endif  //_ENCHANTEDWALL_H
