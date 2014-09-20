#include "GameMap.h"
#include "Player.h"

class GameEngine
{
private:
    Player m_Player;
public:
    GameMap firstMap;

    GameEngine();
    bool TryMove(const int nDeltaX, int nDeltaY);
    const Player& GetPlayer() const;
};
