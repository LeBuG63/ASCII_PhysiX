#include <stdio.h>
#include <stdlib.h>

#include "save.h"
#include "def.h"
#include "funct.h"
#include "map.h"

void	save(void)
{
    __uint	y,
			x;
    FILE    *file = NULL;
    char    filename[21],
            filepath[27];

    point_t point = {0, _map.h + 1};

    gotoxy(point);
	printf("File name: ");
    scanf("%s", filename);
    sprintf(filepath, "Saves/%s.ascphx", filename);

    if(!(file = fopen(filepath, "w")))
    {
        printf("Error: -> | The file path doesn't exist\n"\
               "          | Can't open the file. Exit...\n"\
               "          | Press [ENTER] to exit.");
        getchar();
        exit(1);
    }

    fprintf(file, "%u %u\n", _map.h, _map.w);

    for(y = 0; y < _map.h; y++)
        for(x = 0; x < _map.w; x++)
			fputc(_map.arr[y][x], file);

    fclose(file);
	clrscr();
	map_print();
}
