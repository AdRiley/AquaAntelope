#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "cursesWindow.h"
#include "GameEngine.h"
//#include "GameView.h"

int main(void) {

    cursesWindow mainwin{};
    GameEngine mainEngine{};

    while (true)
    {
        cursesWindow::Clear();
        cursesWindow::DrawMap(mainEngine.firstMap.map);
        cursesWindow::DrawPlayer(mainEngine.GetPlayer());

        switch (mainwin.GetCommand())
        {
            case Command::Up:
                mainEngine.TryMove(0, -1);
                break;
            case Command::Down:
                mainEngine.TryMove(0, 1);
                break;
            case Command::Left:
                mainEngine.TryMove(-1, 0);
                break;
            case Command::Right:
                mainEngine.TryMove(1, 0);
                break;
            case Command::Exit:
                return 0;
                break;
        }
    }
    return 0;
}
