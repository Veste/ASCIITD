#include "windowing02.h"

#include <ncurses.h>

typedef struct _win_border_struct {
  chtype ls, rs, ts, bs,
         tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {
  int startx, starty;
  int height, width;
  WIN_BORDER border;
} WIN;


void init_win_params( WIN *p_win ) {
  p_win->height = 3;
  p_win->width = 10;
  p_win->starty = (LINES - p_win->height)/2;
  p_win->startx = (COLS - p_win->width)/2;

  p_win->border.ls = '|';
  p_win->border.rs = '|';
  p_win->border.ts = '-';
  p_win->border.bs = '-';
  p_win->border.tl = p_win->border.tr = '+';
  p_win->border.bl = p_win->border.br = '+';
}


void print_win_params( WIN *p_win ) {
#ifdef _DEBUG
  mvprintw( 25, 0, "%d %d %d %d", p_win->startx, p_win->starty,
    p_win->width, p_win->height );
  refresh( );
#endif
}


void destroy_box( WIN *p_win ) {

  int i, j,
    x = p_win->startx,
    y = p_win->starty,
    w = p_win->width,
    h = p_win->height;

  for ( j = y; j <= (y + h); j++ ) {
    for ( i = x; i <= (x + w); i++ ) {
      mvaddch( j, i, ' ' );
    }
  }
  
  refresh( );
}


void create_box( WIN *p_win ) {
  int x = p_win->startx, 
      y = p_win->starty, 
      w = p_win->width, 
      h = p_win->height;

  WIN_BORDER b = p_win->border;

  // Draw the 4 corners
  mvaddch( y, x, b.tl );
  mvaddch( y, (x + w), b.tr );
  mvaddch( (y + h), x, b.bl );
  mvaddch( (y + h), (x + w), b.br );

  // Draw the top side and bottom side
  mvhline( y, (x + 1), b.ts, (w - 1) );
  mvhline( (y + h), (x + 1), b.bs, (w - 1) );

  // Draw the left side and right side
  mvvline( (y + 1), x, b.ls, (h - 1) );
  mvvline( (y + 1), (x + w), b.rs, (h - 1) );

  // Push to the screen
  refresh( );
}


void windowing02( ) {

  WIN win;
  int ch;

  init_pair( 5, COLOR_CYAN, COLOR_BLACK );

  // erase the text on the window
  erase( );
  move( 0, 0 );

  // Assign border characters and starting width/height/position
  init_win_params( &win );
  print_win_params( &win );

  // Draw bold backgrounded text at the top of the screen
  attron( COLOR_PAIR(5) | A_BOLD );
  printw( "Press X to exit" );
  refresh( );
  attroff( COLOR_PAIR(5) | A_BOLD );
  attrset( A_NORMAL );

  // Draw the box onto the screen
  create_box( &win );
  // While the input character isn't an x, perform some actions
  while( (ch = getch()) != 'x' ) {
    // Use the keyboard keys to "move" the box (destroy and recreate it)
    switch ( ch ) {
      case KEY_LEFT:
        destroy_box( &win );
        win.startx--;
        create_box( &win );
        break;
      case KEY_RIGHT:
        destroy_box( &win );
        win.startx++;
        create_box( &win );
        break;
      case KEY_UP:
        destroy_box( &win );
        win.starty--;
        create_box( &win );
        break;
      case KEY_DOWN:
        destroy_box( &win );
        win.starty++;
        create_box( &win );
        break;
      default:
        break;
    }
  }

  return;
}


