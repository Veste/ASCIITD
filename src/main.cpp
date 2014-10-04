#include <ncurses.h>
#include <iostream>
#include "printw_ex.h"
#include "printbox.h"
#include "animate.h"
#include "windowing01.h"
#include "windowing02.h"

int main(int argc, char* argv[]) {

  int ch;

  initscr();
  start_color();
  use_default_colors();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  
  printw("Choose an example: \n");
  printw("  printw      (p)\n");
  printw("  print box   (b)\n");
  printw("  animate     (a)\n");
  printw("  windowing1  (w)\n");
  printw("  windowing2  (e)\n");
  
  ch = getch();
  switch ( ch ) {
    case 'p':
      printw_ex();
      break;
    case 'b':
      print_box( 100, 20, 'b' );
      break;
    case 'a':
      animate( );
      break;
    case 'w':
      windowing01( );
      break;
    case 'e':
      windowing02( );
      break;
    default:
      break;
  }
  refresh();

  ch = getch();

  endwin();

  return 0;
}
