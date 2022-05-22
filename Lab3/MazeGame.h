#include <sstream>
using namespace std;

#include "Maze.h"
#include "MazeFactory.h"
#include "EnchantedMazeFactory.h"
#ifndef MAZEGAME_H
#define	MAZEGAME_H

class MazeGame {
public:
    MazeGame();
    MazeGame(const MazeGame& orig);
    virtual ~MazeGame();
    
    Maze* createMaze(MazeFactory*);
    string toString();
    const Maze * getAtributtes();
private:
    Maze* aMaze;
};


MazeGame::MazeGame(): aMaze(0) {
}

MazeGame::MazeGame(const MazeGame& orig) {
}

MazeGame::~MazeGame() {
}

Maze* MazeGame::createMaze(MazeFactory* f) {
    aMaze = f->createMaze();

    Room* r1 = f->createRoom(); //new Room(1);
    Room* r2 = f->createRoom(); //new Room(2);
    Door* theDoor = f->createDoor(); //new Door(r1,r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);


    //r1->SetSide(MapSite::North, new Wall());
    r1->SetSide(MapSite::North, f->createWall());

    r1->SetSide(MapSite::East, theDoor);

    //r1->SetSide(MapSite::South, new Wall());
    r1->SetSide(MapSite::South, f->createWall());

    //r1->SetSide(MapSite::West, new Wall());
    r1->SetSide(MapSite::West, f->createWall());

    r2->SetSide(MapSite::North, f->createWall());
    r2->SetSide(MapSite::East, f->createWall());
    r2->SetSide(MapSite::South, f->createWall());
    r2->SetSide(MapSite::West, theDoor);

    return aMaze;
}

string MazeGame::toString()
{
    ostringstream s;
    s << aMaze->toString();
    return s.str();
}

const Maze * MazeGame::getAtributtes() {
    return aMaze;
}
#endif	/* MAZEGAME_H */

