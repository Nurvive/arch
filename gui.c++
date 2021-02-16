#include "MyTerm.h"
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;
const string ESC = "\33[";
const string clear = "\E[H\E[2J";
const string cursor_address = "H";
const string color = "m";
const string invisible = "?25l";
const string visible = "?25h";
int mt_clrscr() {
  std::cout << clear;
  return 0;
}

int mt_gotoXY(int x, int y) {
  cout << ESC + to_string(x) + ':' + to_string(y) + cursor_address;
  return 0;
}

int mt_getscreensize(int *rows, int *cols) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int lines = w.ws_row;
  int ols = w.ws_col;
  *rows = lines;
  *cols = ols;
  return 0;
}

int mt_setfgcolor(colors n) {
  cout << ESC + ';' + to_string(30 + n) + color;
  return 0;
}
int mt_setbgcolor(colors n){
  cout << ESC + ';' + to_string(40 + n) + color;
  return 0;
}
