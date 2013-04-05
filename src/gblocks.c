#include <stdio.h>

#include "map.h"
#include "funct.h"
#include "gblocks.h"

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
		_map.arr[_p->y][_p->x] = block_id[LIGHT_BLOCK].ch;
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

void	water(linkedlist_t *_ll, point_t *_p, __uint _where, int *_stop)
{
	static point_t	p_ob_xe,
					p_ob_xw;
	static point_t	tmp;
	static int		ok = 0;

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
