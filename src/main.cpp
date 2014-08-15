#include <ncurses.h>
#include <iostream>
#include "printw_ex.h"

int main(int argc, char* argv[]) {

  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  
  printw("Choose an example: \n");
  printw("  printw (p)\n");
  
  ch = getch();
  if (ch == 'p') {
    printw_ex();
  }
  refresh();

  ch = getch();

  endwin();

  return 0;
}
