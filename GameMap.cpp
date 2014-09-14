#include "GameMap.h"

GameMap::GameMap(std::initializer_list<std::initializer_list<int>> l)
{
    int r = 0;
    for (auto sl : l)
    {
        map.resize(map.size()+1);
        for (auto i :sl)
            map[r].push_back(static_cast<Tile>(i));
        ++r;
    }
}


