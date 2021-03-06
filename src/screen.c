#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "screen.h"
#include "def.h"
#include "map.h"
#include "funct.h"
#include "blocks.h"

void	hud(linkedlist_t _ll)
{
    point_t	p = {0, _map.h};
    int		physic;
	char	class_block[21];

	switch(CLASS_OBJ)
	{
	case 1:
		sprintf(class_block, "Block");
		break;
	case 2:
		sprintf(class_block, "Water");
		break;
	case 3:
		sprintf(class_block, "Dust ");
		break;
	default:
		sprintf(class_block, "Unknow");
		break;
	}

#ifdef PHYSIC_MODE
    physic = 1;
#else
    physic = 0;
#endif

    setcolor(bGRAY | bINTENSITY);

    gotoxy(p);

    if(PAUSE)
        printf(" %c ", 186);
    else
        printf(" %c ", 16);

    p.x += 2;
    gotoxy(p);
    printf(" | Mode: %s | Number of element(s): %d | %s |", ((physic) ? "Physic" : "Game" ), _ll.size, class_block);

    setcolor(LIGHTGRAY);
}

void	destroy_hud(void)
{
	point_t	p = {0, _map.h};

	gotoxy(p);
	setcolor(bBLACK);
	putstr("                                                             ");
	setcolor(LIGHTGRAY);
}

void	help(void)
{
	__uint	i = 0;

	clrscr();
	
	for(i = 0; i < _map.w; i++)
		putchar('-');

	putchar('\n');

	for(i = 0; i < sizeof(block_id) / sizeof(*block_id); i++)
	{
		if(strlen(block_id[i].name) < 7)
			printf("|[%c - %c] %s\t\t| %s\t\n", block_id[i].ch, block_id[i].key, block_id[i].name, block_id[i].explication);
		else
			printf("|[%c - %c] %s\t| %s\t\n", block_id[i].ch, block_id[i].key, block_id[i].name, block_id[i].explication);
	}
	putstr("\nBy PixelCode team !\n\n");
	putstr("\nPress [ENTER] to continue...");
	getchar();
	clrscr();
	map_print();
}
