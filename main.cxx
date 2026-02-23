#include <ncurses.h>
#include <string>

void redraw(int rows, int columns, std::string input);

int main(void) {
  initscr();
  start_color();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  

  attron(COLOR_PAIR(1));
  printw("Press F1 to exit");
  refresh();
  attroff(COLOR_PAIR(1));

  std::string input;
  int ch, y, x, old_y, old_x;
  while((ch = getch()) != KEY_F(1)) {
    getmaxyx(stdscr, y, x);
    if(old_y != y || old_x != x) { // check for resize and redraw if true
      old_y = y;
      old_x = x;
      clear();
    }
    if(ch == '\n') {
      input.clear();
      // clearing input for now, but could process it instead
    } else if (ch == KEY_BACKSPACE) {
      input.pop_back();
    } else if (isascii(ch)) {
      if(isprint(ch)) {
        input += ch;
      } else {
        // non-printable control character like backspace or something
      }
    } else {
      // not an ascii character as input
    }
    redraw(y, x, input);
  }
  endwin();
  return 0;
}

void redraw(int rows, int columns, std::string input){
  attron(COLOR_PAIR(1));
  move(rows-2, 0);
  printw(input.c_str());
  for(int i = input.length(); i < columns-1; i++){
    printw(" ");
  }
  attroff(COLOR_PAIR(1));
}
