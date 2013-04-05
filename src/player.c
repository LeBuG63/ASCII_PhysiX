#include <stdio.h>

#include "player.h"
#include "funct.h"
#include "keys.h"
#include "def.h"
#include "save.h"
#include "open.h"
#include "screen.h"

void	player_action(player_t _p, linkedlist_t *_ll)
{
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