#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <vector>
#include "tile.h"

class cursesWindow
{
    WINDOW* m_win;

public:
    cursesWindow();
    ~cursesWindow();

    static void DrawPlayer(const int x, const int y);
    static void DrawMap(const std::vector<std::vector<Tile>>& v);
    static bool HandleKeyPress(int& nPlayerX, int& nPlayerY);
    static void Clear();
};



