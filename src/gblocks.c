#include <stdio.h>

#include "map.h"
#include "funct.h"
#include "blocks.h"

void	lightblock(linkedlist_t *_ll, point_t *_p, __uint _where, int *_stop)
{
	if(!obstacle(*_p, 1, DIR_S))
	{
		
		gotoxy(*_p);
		putchar(_map.cfill);
		_p->y++;
		ll_modify_pos(_ll, _where, *_p);
	}
	else
	{
		_map.arr[_p->y][_p->x] = block_id[SAND].ch;
		*_stop = 1;
	}
}

void reverseblock(linkedlist_t *_ll, point_t *_p, __uint _where, int *_stop)
{
	if(!obstacle(*_p, 1, DIR_N))
	{
		gotoxy(*_p);
		putchar(_map.cfill);
		_p->y--;
		ll_modify_pos(_ll, _where, *_p);
	}
	else
	{
		_map.arr[_p->y][_p->x] = block_id[REVERSE_BLOCK].ch;
		*_stop = 1;
	}
}

void	heavyblock(linkedlist_t *_ll, point_t *_p, __uint _where, int *_stop)
{
	if(!obstacle(*_p, 1, DIR_S))
	{
		gotoxy(*_p);
		putchar(_map.cfill);
		_p->y++;
		ll_modify_pos(_ll, _where, *_p);
	}
	else
	{
		_map.arr[_p->y][_p->x] = block_id[HEAVY_BLOCK].ch;
		*_stop = 1;
	}
}

void	grid(linkedlist_t *_ll, point_t *_p, __uint where)
{
	int		i;
	point_t	cpy = *_p;

	cpy.y--;
	i = get_id_block(cpy, _ll);

	if(i != -1)
	{
		if(block_id[i].familly == CLASS_DUST)
		{
			_map.arr[_p->y][_p->x]		= _map.cfill;
			_map.arr[_p->y - 1][_p->x]	= _map.cfill;
		}
		else
			_map.arr[_p->y][_p->x] = block_id[GRID].ch;
	}
	else
		_map.arr[_p->y][_p->x] = block_id[GRID].ch;
}

void	water(linkedlist_t *_ll, point_t *_p, __uint _where, int *_stop)
{
	point_t	p_ob_xe,
			p_ob_xw;
	point_t	tmp;
	int		ok = 0;

	if(!obstacle(*_p, 1, DIR_S))
	{
		gotoxy(*_p);
		putchar(block_id[WATER_SOURCE].ch);

		_p->y++;
		ll_modify_pos(_ll, _where, *_p);
	}
	else	
	{
		if(!ok)
		{
			p_ob_xe = p_ob_xw = *_p;
			ok	= 1;
		}	

		if(!obstacle(p_ob_xe, 1, DIR_E))
		{
			p_ob_xe.x++;
		}
		if(!obstacle(p_ob_xw, 1, DIR_W))
		{
			p_ob_xw.x--;

		}
	}
}
