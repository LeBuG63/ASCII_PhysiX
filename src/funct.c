#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <dirent.h>

#include "funct.h"

void	gotoxy(point_t _p)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD C;

	C.X = _p.x;
	C.Y = _p.y;

	SetConsoleCursorPosition(H, C);
}

void    setcolor(color_t _c)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, _c);
}

void    clrscr(void)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    FillConsoleOutputCharacter(hStdOut, NULL, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
}

void	putstr(const char *_str)
{
	while(*_str)
		write(1, &*_str++, 1);
}

void    readDirectory(const char *name)
{
    DIR *rep = NULL;
    
    struct dirent* fileRead = NULL;
    
    rep = opendir(name);
    
    if (rep == NULL)
    {
        printf("The directory does not exist.");
        getchar();
        exit(1);
    }
    fileRead = readdir(rep);

    printf ("[%s ]\n", name);
    while ((fileRead = readdir(rep)) != NULL)
        printf("\t- %s\n", fileRead->d_name);
    
    closedir(rep);
}
