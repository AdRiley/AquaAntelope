#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "tile.h"

class GameMap
{
public:
    std::vector<std::vector<Tile>> map;

    GameMap(std::initializer_list<std::initializer_list<int>> l);
};

#endif

