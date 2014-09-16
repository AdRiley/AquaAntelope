#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "TileType.h"

class GameMap
{
public:
    std::vector<std::vector<TileType>> map;

    GameMap(std::initializer_list<std::initializer_list<int>> l);
};

#endif

