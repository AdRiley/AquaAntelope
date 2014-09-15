#include "GameMap.h"

class GameEngine
{
public:
    int nPlayerX, nPlayerY;
    GameMap firstMap;

    GameEngine();
    bool TryMove(const int nDeltaX, int nDeltaY);
};
