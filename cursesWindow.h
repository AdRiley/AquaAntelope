#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

class cursesWindow
{
    WINDOW* m_win;

public:
    cursesWindow();
    ~cursesWindow();

    static void DrawPlayer(const int x, const int y);
    static bool HandleKeyPress(int& nPlayerX, int& nPlayerY);
    static void Clear();
};



