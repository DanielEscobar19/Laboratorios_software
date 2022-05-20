#include <iostream>
#include <sstream>
using namespace std;

#ifndef MAPSITE_H
#define	MAPSITE_H

class MapSite {
public:
    enum Direction {North, South, East, West};
    static int idg;
    
    MapSite();
    virtual ~MapSite();
    MapSite(const MapSite& orig);

    int getId();
    virtual void enter() = 0;
    virtual string toString();
    void setType(string nt);
    string getType();

private:
    int id;
    string type;
};

MapSite::MapSite(): id(idg) {
    idg++;
}

MapSite::MapSite(const MapSite& orig) {
}

MapSite::~MapSite() {
}

int MapSite::getId() {
    return id;
}

void MapSite::setType(string nt)
{
    type = nt;
}

string MapSite::getType() {
    return type;
}

string MapSite::toString()
{
    ostringstream s;
    s << MapSite::getType() << " # " << MapSite::getId() << endl;
    return s.str();
}
#endif	/* MAPSITE_H */

