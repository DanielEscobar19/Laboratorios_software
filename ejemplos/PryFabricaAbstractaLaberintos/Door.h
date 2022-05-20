#include "Room.h"

#ifndef DOOR_H
#define	DOOR_H

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);
    Door(const Door& orig);
    virtual ~Door();
    
    Room* OtherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

Door::Door(Room* f, Room* s): _room1(f), _room2(f) {
}

Door::Door(const Door& orig) {

}

Door::~Door() {
}

Room* Door::OtherSideFrom(Room* r) {
    Room* rsl = 0;
    if (r == _room1)
        rsl = _room2;
    else rsl = _room1;
    return rsl;
}

#endif	/* DOOR_H */

