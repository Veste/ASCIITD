#include <ncurses.h>
#include <iostream>
#include "printw_ex.h"
#include "printbox.h"

int main(int argc, char* argv[]) {

  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  
  printw("Choose an example: \n");
  printw("  printw      (p)\n");
  printw("  print box   (b)\n");
  
  ch = getch();
  switch ( ch ) {
    case 'p':
      printw_ex();
      break;
    case 'b':
      print_box( 100, 20, 'b' );
      break;
    default:
      break;
  }
  refresh();

  ch = getch();

  endwin();

  return 0;
}
