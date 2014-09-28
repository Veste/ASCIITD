#include <ncurses.h> 
#include <cstring>

#include "printw_ex.h"

/**
 * pre:   ncurses initscr has been called
 */
void printw_ex() {

  char msg[] = "Here's a message!";
  int row = 0, col = 0;

  getmaxyx(stdscr, row, col);

  mvprintw(row/2, (col - strlen(msg))/2, "%s", msg);

  mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);

}

