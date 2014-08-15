#include <ncurses.h>
#include <iostream>

int main(int argc, char* argv[]) {

  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  printw("Type any character to see it in bold\n");
  ch = getch();

  if (ch == KEY_F(1)) {
    // The magic key I guess ????
    printw("F1 key pressed!");
  } else {
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }
  refresh();

  ch = getch();

  endwin();

  return 0;
}
