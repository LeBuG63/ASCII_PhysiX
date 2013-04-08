#ifndef __FUNCT_H__
#define __FUNCT_H__

#include "def.h"

void	gotoxy(point_t);
void    setcolor(color_t _c);
void    clrscr(void);
void	putstr(const char *);
void    readDirectory(const char *);

#endif /* __FUNCT_H__ */