#include <iostream>
#include <ncurses.h>
#include <panel.h>

#define NUM_PANELS (3)

#define INITIAL_SIZE (100)

//https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/panels.html#PANELSHOWHIDE

int main(void) {
  WINDOW* standardScreen = initscr();
  std::string building;
  if (standardScreen == NULL) {
    std::cerr << "ERROR: Couldn't initialize ncurses" << std::endl;
    exit(1);
  }
  int row, col;
  raw();                                // disable line buffering
  keypad(standardScreen, TRUE);         // include function key input
  getmaxyx(standardScreen, row, col);
  move(row-1, 0);
  refresh();
  int ch;
  int curr_line = 0;
  while ((ch = getch()) != KEY_F(1)) { // type F1 to exit
    if(ch == '\n'){
      move(curr_line, 0);
      printw(building.c_str());
      move(row-1, 0);
      clrtoeol();
      curr_line++;
      building.clear();
    } else if (ch == KEY_BACKSPACE) {
      building.pop_back();
    } else {
      // add to char array
      building += ch;
    }
  }
  endwin();
  return 0;
}
