#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "open.h"
#include "map.h"
#include "funct.h"
#include "blocks.h"
#include "player.h"
#include "screen.h"

void	open(linkedlist_t *_ll, player_t *_p)
{
    __uint	c = 0,
            e = 0,
            i = 0;
    FILE    *file = NULL;
    char    filename[21],
            filepath[27];
    point_t coord   = {0, 0};

	ll_destroy(_ll);
	ll_create(_ll);
	destroy_hud();
	map_dealloc();

    clrscr();
	readDirectory("Saves/");
	putstr("\nFile to open: ");
    scanf("%s", filename);
    sprintf(filepath, "Saves/%s.ascphx", filename);

    if(!(file = fopen(filepath, "r")))
    {
        putstr("Error: -> | The file path doesn't exist\n"\
               "          | Can't open the file. Exit...\n"\
               "          | Press [ENTER] to exit.\n");
        getchar();
        exit(1);
    }

    fscanf(file, "%u %u\n", &_map.h, &_map.w);

    map_create();

    do
    {
        c = fgetc(file);

        if(i == _map.w)
        {
            i = 0;
            coord.y++;
            coord.x = 0;
        }
        else
            coord.x++;
        if(c != _map.cfill && c != _map.cborder && c != 2)
            ll_add(_ll, get_block_char(c), coord);
        if(c != EOF)
            _map.arr[coord.y][coord.x] = c;
        if(c == 2)
            _p->pos = coord;
        i++;

    }while(c != EOF);

    fclose(file);
	clrscr();
	map_print();
	hud(*_ll);
}
