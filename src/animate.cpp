#include "animate.h"

#include "printbox.h"

#include <ncurses.h>
#include <unistd.h>

// Microseconds equal to 1/60 of a second
#define fps 16667 

void animate( ) {

  // clear the ncurses window
  erase();
  move( 0, 0 );

  int sc_rows = 0, sc_cols = 0;

  getmaxyx( stdscr, sc_rows, sc_cols );

  printw( "Press x to finish" );

  print_box( sc_cols, sc_rows - 2, 'b' );

  int row = (sc_rows/2),
      col = (sc_cols/2);
  char state = 0;

  // Set ncurses input to be non-blocking,
  // so we can use it to break
  nodelay( stdscr, true );

  // Printing every frame is too fast; let's
  // just use a counter to count to the frame
  // we want to print in
  int count = 0;

  mvaddch( row, (col + state) - 2, 'a' );
  while ( true ) {

    if ( getch() == 'x' ) {
      break;
    }

    // after x frames
    if ( count++ == 30 ) {
      mvaddch( row, (col + state) - 2, ' ' );
      if ( ++state == 4 ) {
        state = 0;
      }
      mvaddch( row, (col + state) - 2, 'a' );
      count = 0;
    }

    usleep( fps );
  }

  mvprintw( row + 1, (col - 7), "Press any key" );

  // Set back to blocking
  nodelay( stdscr, false );
}


