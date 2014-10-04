#include "windowing01.h"

#include <ncurses.h>


WINDOW* create_newwin( int height, int width, 
    int starty, int startx ) {
  WINDOW* local_win;

  local_win = newwin( height, width, starty, startx );
  box( local_win, 0, 0 );   // 0s mean use default chars for y, x

  wrefresh( local_win );    // refresh our new window!

  return local_win;
}


void destroy_win( WINDOW *local_win ) {

  /* we can't just use box; it'll leave the corners */
  // box( local_win, ' ', ' ' );

  wborder( local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' );

  wrefresh( local_win );
  delwin( local_win );
}


void windowing01( ) {

  WINDOW *my_win;
  int width = 10, 
      height = 3,
      startx = (COLS - width) / 2, 
      starty = (LINES - height) / 2; 
  int ch;

  erase( );
  move( 0, 0 );
  printw( "Press x to exit" );
  refresh( );

  my_win = create_newwin( height, width, starty, startx );

  while ( (ch = getch()) != 'x' ) {
    switch ( ch ) {
      case KEY_LEFT:
        if ( startx > 0 ) {
          destroy_win( my_win );
          my_win = create_newwin( height, width, starty, --startx );
        }
        break;
      case KEY_RIGHT:
        destroy_win( my_win );
        my_win = create_newwin( height, width, starty, ++startx );
        break;
      case KEY_UP:
        if ( starty > 0 ) {
          destroy_win( my_win );
          my_win = create_newwin( height, width, --starty, startx );
        }
        break;
      case KEY_DOWN:
        destroy_win( my_win );
        my_win = create_newwin( height, width, ++starty, startx );
        break;
      default:
        break;
    }
  }

  return;
}

