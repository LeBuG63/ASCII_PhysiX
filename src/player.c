#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "funct.h"
#include "keys.h"
#include "def.h"
#include "save.h"
#include "open.h"
#include "screen.h"
#include "blocks.h"

void	player_action(player_t _p, linkedlist_t *_ll)
{
	int		i;
	switch(_p.key)
	{
	case K_S:
		save();
		break;
	case K_O:
		open(_ll, &_p);
		break;
	case K_RETURN:
		((PAUSE) ? (PAUSE = 0) : (PAUSE = 1));
		break;
	case K_h:
		help();
		break;
	case K_Q:
		ll_destroy(_ll);
		map_dealloc();
		exit(0);
		break;
	case K_C:
		ll_destroy(_ll);
		ll_create(_ll);
		clrscr();
		map_dealloc();
		map_create();
		map_print();
		break;
	case K_1:
		CLASS_OBJ = CLASS_BLOCK;
		break;
	case K_2:
		CLASS_OBJ = CLASS_WATER;
		break;
	case K_3:
		CLASS_OBJ = CLASS_DUST;
		break;
	case K_a:
		_p.pos.y++;
		i = get_blockid(_p.pos, _ll);

		if(i != -1)
		{
			//ll_print(_ll);
			ll_destroy_at(_ll, i);
			_map.arr[_p.pos.y][_p.pos.x] = _map.cfill;
		}
		break;
	}
}

void	player_print(player_t *_p)
{
	player_move(_p);

	gotoxy(_p->pback);
	putchar(_p->chback);
	gotoxy(_p->pos);
	putchar(_p->ch);
}
