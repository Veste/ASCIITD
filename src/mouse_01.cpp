#include "mouse_01.h"

#include <ncurses.h>


typedef struct _WIN_struct {
  int startx, starty;
  int height, width;
  WIN_BORDER border;
} WIN;


void init_win_params( WIN *p_win ) {

  p_win->height = 1;
  p_win->width = 1;
  p_win->starty = (LINES - p_win->height)/2;
  p_win->startx = (COLS - p_win->width)/2;

  p_win->border.ls = p_win->border.rs = '|';
  p_win->border.bs = p_win->border.ts = '-';
  p_win->border.tl = p_win->border.tr = '+';
  p_win->border.bl = p_win->border.br = '+';
}


void mouse01( ) {

  WIN win;
  int ch;
  MEVENT m_event;

  // Set up mouse events
  mousemask( REPORT_MOUSE_POSITION | BUTTON1_CLICKED, NULL );

  erase( );
  move( 0, 0 );

  while( (ch = getch()) != 'x' ) {
    if ( ch == KEY_MOUSE && getmouse(&m_event) == OK ) {
      
    }
  }


  return;
}


