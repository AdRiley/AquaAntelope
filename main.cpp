#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "cursesWindow.h"
#include "GameEngine.h"


int main(void) {

    cursesWindow mainwin{};
    GameEngine mainEngine{};

    while (true)
    {
        cursesWindow::Clear();
        cursesWindow::DrawMap(mainEngine.firstMap.map);
        cursesWindow::DrawPlayer(mainEngine.nPlayerX, mainEngine.nPlayerY);

        if(!cursesWindow::HandleKeyPress(mainEngine.nPlayerX, mainEngine.nPlayerY))
            break;
    }

    return 0;
}
