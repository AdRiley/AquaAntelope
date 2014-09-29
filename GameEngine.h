#include "GameMap.h"
#include "Player.h"
#include "TileType.h"
#include <map>

class GameEngine
{
private:
    Player m_Player;
public:
    GameMap firstMap;
private:
    std::map<TileType, bool> isPassable;
public:
    GameEngine();
    bool TryMove(const int nDeltaX, int nDeltaY);
    const Player& GetPlayer() const;
};
