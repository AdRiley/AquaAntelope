#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

class cursesWindow
{
    WINDOW* m_win;

public:
    cursesWindow() : m_win(initscr())
    {
        if (!m_win)
            throw "Error initialising ncurses.";

        noecho();              // Turn off key echoing
        keypad(m_win, TRUE);   // Enable the keypad for non-char keys
        curs_set(0);	       // Hide the cursor
    }

    ~cursesWindow()
    {
        curs_set(1);
        echo();

        delwin(m_win);
        endwin();
        refresh();
    }

    static void DrawPlayer(const int x, const int y)
    {
        mvaddstr(y, x, "@");
        refresh();
    }

    static bool HandleKeyPress(int& nPlayerX, int& nPlayerY)
    {
        int keyPress = getch();

        switch( keyPress )
        {
            // Move down
            case KEY_DOWN:
                nPlayerY++;
                break;
            // Move left
            case KEY_LEFT:
                nPlayerX--;
                break;
            // Move right
            case KEY_RIGHT:
                nPlayerX++;
                break;
            // Move up
            case KEY_UP:
                nPlayerY--;
                break;
            case KEY_BACKSPACE:
                return false;
                break;
            default:
                break;
        }
        return true;
    }

    static void Clear()
    {
        clear();
    }
};

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
