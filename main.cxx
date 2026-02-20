#include <iostream>
#include <ncurses.h>

// so what do I want to do
// bottom line like vim, 
// - zoom
// - add new equation
// - delete equation
// - regraph/update view
// - point following a specific function

int main(void) {
  initscr();
  raw(); // disable line buffering;
  keypad(stdscr, TRUE); // include function key inputs
  noecho();
  refresh();
  printw("Type a char:\n");
  int ch = getch();
  printw("The pressed key in bold is: ");
  attron(A_BOLD);
  printw("%c", ch);
  attroff(A_BOLD);
  printw("\nHit <f1> to finish.\n");
  while((ch = getch()) != KEY_F(1)){
    //infinite loop to close on F1 press
  }
  endwin();
  return 0;
}
