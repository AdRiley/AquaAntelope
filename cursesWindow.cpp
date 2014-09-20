#include "cursesWindow.h"

cursesWindow::cursesWindow() :
    m_win(initscr())
{
    if (!m_win)
        throw "Error initialising ncurses.";

    noecho();              // Turn off key echoing
    keypad(m_win, TRUE);   // Enable the keypad for non-char keys
    curs_set(0);	       // Hide the cursor
}

cursesWindow::~cursesWindow()
{
    curs_set(1);
    echo();

    delwin(m_win);
    endwin();
    refresh();
}

/*static*/ void cursesWindow::DrawMap(const std::vector<std::vector<TileType>>& v)
{
    int y = 0;
    for(auto yv : v)
    {
        int x = 0;
        for(auto t : yv)
        {
            mvaddstr(y, x, (t==TileType::Floor ? "." : "#"));
            ++x;
        }
        ++y;
    }
}

/*static*/ void cursesWindow::DrawPlayer(Player player)
{
    mvaddstr(player.m_PosY, player.m_PosX, "@");
    refresh();
}

Command cursesWindow::GetCommand()
{
    while (true)
    {
        int keyPress = getch();

        switch( keyPress )
        {
            case KEY_DOWN:
                return Command::Down;
                break;
            case KEY_LEFT:
                return Command::Left;
                break;
            case KEY_RIGHT:
                return Command::Right;
                break;
            case KEY_UP:
                return Command::Up;
                break;
            case KEY_BACKSPACE:
                return Command::Exit;
                break;
            default:
                break;
        }
    }
}
/*static*/ void cursesWindow::Clear()
{
    clear();
}



