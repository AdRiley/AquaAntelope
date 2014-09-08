#include <stdlib.h>
#include <stdio.h>
#include "cursesWindow.h"

int main(void) {

    cursesWindow mainwin{};

    int nPlayerX{40}, nPlayerY{12};

    while (true)
    {
        cursesWindow::Clear();
        cursesWindow::DrawPlayer(nPlayerX, nPlayerY);

        if(!cursesWindow::HandleKeyPress(nPlayerX, nPlayerY))
            break;
    }

    return 0;
}
