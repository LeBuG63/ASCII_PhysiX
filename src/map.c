#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "map.h"
#include "blocks.h"
#include "funct.h"
#include "debug.h"

void	map_create(void)
{
	map_alloc();
	map_fill();
	map_border();
}

void	map_alloc(void)
{
	__uint i = 0;

	_map.arr = (__byte**)malloc((_map.h + 1) * sizeof(__byte*));

	for(i = 0; i < _map.h; i++)
	{
		_map.arr[i]			= (__byte*)malloc((_map.w + 1) * sizeof(__byte));
		_map.arr[i][_map.w]	= NULL;
	}
	_map.arr[i] = NULL;
}
void	map_dealloc(void)
{
	__uint i = 0;

	for(i = 0; i < _map.h; i++)
		free(_map.arr[i]);
	free(_map.arr);
}
/////////////////////////
void	map_fill(void)
{
	point_t p = {0, 0};

	for(p.y = 0; p.y < _map.h; p.y++)
		for(p.x = 0; p.x < _map.w; p.x++)
			_map.arr[p.y][p.x] = _map.cfill;
}
void	map_border(void)
{
	point_t p = {0, 0};

	for(p.y = 0; p.y < _map.h; p.y++)
		for(p.x = 0; p.x < _map.w; p.x++)
			if(p.x == 0 || p.y == 0 || p.x == _map.w - 1 || p.y == _map.h - 1)
				_map.arr[p.y][p.x] = _map.cborder;
}

void	map_print(void)
{
	point_t p = {0, 0};

	for(p.y = 0; p.y < _map.h; p.y++)
	{
		for(p.x = 0; p.x < _map.w; p.x++)
			putchar(_map.arr[p.y][p.x]);
		putchar('\n');
	}
}

void	map_refresh(linkedlist_t *_ll)
{
	__uint	where = 0;
	__byte	ch;
	point_t	pos;
	int		stop = 0;

	for(where = 0; where < _ll->size; where++)
	{
		ch = ll_at(_ll, where, &pos);
		
		if(!PAUSE)
		{
			if(ch == block_id[LIGHT_BLOCK].ch)
				lightblock(_ll, &pos, where, &stop);
			if(ch == block_id[REVERSE_BLOCK].ch)
				reverseblock(_ll, &pos, where, &stop);
			if(ch == block_id[HEAVY_BLOCK].ch)
				heavyblock(_ll, &pos, where, &stop);
			if(ch == block_id[WATER].ch)
				water(_ll, &pos, where, &stop);
			if(ch == block_id[WALL].ch)
				stop = 1;
		}

		if(stop)
			stop = 0;
		else
		{
			gotoxy(pos);
			putchar(ch);
		}
	}
}

/////////////////////////
__byte	get_char_x(point_t _pos, __uint _add)
{
	return(_map.arr[_pos.y][_pos.x + _add]);
}
__byte	get_char_y(point_t _pos, __uint _add)
{
	return(_map.arr[_pos.y + _add][_pos.x]);
}

void	map_add_block(block_t _block, point_t _p, linkedlist_t *_ll)
{
	ll_add(_ll, _block, _p);

	if(!_block.can_fall)
		_map.arr[_p.y][_p.x] = _block.ch;
}

/////////////////////////

int		obstacle(point_t _p, __uint _add, dir_t _dir)
{
	__byte	ch;

	switch(_dir)
	{
	case DIR_N:
		ch = get_char_y(_p, -_add);
		break;
	case DIR_S:
		ch = get_char_y(_p, _add);
		break;
	case DIR_W:
		ch = get_char_x(_p, -_add);
		break;
	case DIR_E:
		ch = get_char_x(_p, _add);
		break;
	}
	return(ch != _map.cfill);
}
