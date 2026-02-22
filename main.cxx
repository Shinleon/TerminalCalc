#include <iostream>
#include <ncurses.h>
#include <panel.h>

#define NUM_PANELS (3)

//https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/panels.html#PANELSHOWHIDE

WINDOW* initializeNcurses(){
  WINDOW* standardScreen = initscr();
  if (standardScreen == NULL) {
    std::cerr << "ERROR: Couldn't initialize ncurses" << std::endl;
    exit(1);
  }
  raw();                                // disable line buffering
  keypad(standardScreen, TRUE);         // include function key input
  noecho();
  refresh();
  return standardScreen;
}


int main(void) {
  PANEL* panels[NUM_PANELS];
  WINDOW* win_s[NUM_PANELS];
  int velocities[NUM_PANELS*2]= {1, 1, 2, 3, 6, -1};

  initializeNcurses();

  int lines=10, cols=40, x=4, y=2, i=0;

  for(i = 0; i < NUM_PANELS; i++) {
    win_s[i] = newwin(lines, cols, y+i, x+i*5);
    box(win_s[i], 0, 0);
    panels[i] = new_panel(win_s[i]);
  }
  refresh();
  update_panels();
  doupdate();

  int ch;
  while((ch = getch()) != 'a'){
    for(i = 0; i< NUM_PANELS; i++){
      getbegyx(win_s[i], y, x);
      wclear(win_s[i]);
      wrefresh(win_s[i]);
      mvwin(win_s[i], y+1, x+1);
      box(win_s[i], 0, 0);
      wrefresh(win_s[i]);
      refresh();
      update_panels();
    }
    doupdate();
  }
  getch();

  endwin();
  return 0;
}
