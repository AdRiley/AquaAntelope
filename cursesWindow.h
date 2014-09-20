#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <vector>
#include "TileType.h"
#include "Player.h"

enum class Command
{
    Up,
    Down,
    Left,
    Right,
    Exit
};

class cursesWindow
{
    WINDOW* m_win;

public:
    cursesWindow();
    ~cursesWindow();

    static void DrawPlayer(Player player);
    static void DrawMap(const std::vector<std::vector<TileType>>& v);
    static void Clear();
    Command GetCommand();
};



