#ifndef MYTERM_H
#define MYTERM_H

enum colors { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
int mt_clrscr();
int mt_gotoXY(int, int);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(colors);
int mt_setbgcolor( colors);
#endif
