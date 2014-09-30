#include <ncurses.h>
#include <string>

#include "printbox.h"

#define BOX_WIDTH 100
#define BOX_HEIGHT 20

/**
 *  Draws a box of the given width and height in the
 *  center of the screen
 *
 *  pre:    ncurses initscr has been called
 *
 *  args:
 *    int width   -   width of the box to draw
 *    int height  -   height of the box to draw
 *    char ch     -   the character to use to draw the box
 *
 *  returns:
 *    bool        -   whether or not the box was created
 *
 *  post:
 *    call ncurses' refresh() method
 */
bool print_box( int width, int height, char ch ) {

  if ( width <= 0 || height <= 0 ) {
    return false;
  }

  int av_rows = 0, av_cols = 0;

  getmaxyx( stdscr, av_rows, av_cols );

  if ( width > av_cols || height > av_rows ) {
    return false;
  }

  int top_row = (av_rows - height)/2;
  int bot_row = (av_rows + height)/2;
  int left_col = (av_cols - width)/2;
  int right_col = (av_cols + width)/2 - 1;

  std::string row_text( width, ch );
  mvprintw( top_row, left_col, row_text.c_str() );
  mvprintw( bot_row, left_col, row_text.c_str() );
  mvaddch( top_row + (height/2), left_col + (width/2), 'c' );

  for ( int i = top_row+1; i < bot_row; i++ ) {
    mvaddch( i, left_col, ch );
    mvaddch( i, right_col, ch );
  }

  mvprintw( bot_row+1, 0, "\n" );

  return true;
}

