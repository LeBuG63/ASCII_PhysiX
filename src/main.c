#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "linkedlist.h"
#include "def.h"
#include "map.h"
#include "player.h"
#include "funct.h"
#include "debug.h"
#include "screen.h"
#include "options.h"

#define VERSION	L"ALPHA - 0.9.3"

int main(void)
{
	linkedlist_t	*ll = (linkedlist_t*)malloc(sizeof(linkedlist_t));
	player_t		player;
	struct tm		tm_now;
	wchar_t			ws_now[sizeof("JJ/MM/AAAA HH:MM:SS") + 1];
	char			s_now[sizeof("JJ/MM/AAAA HH:MM:SS") + 1];
	wchar_t			title[39];
	time_t			now = time(NULL);

	open_option();

	CLASS_OBJ	 = CLASS_BLOCK;

	player.ch	 = 2;
	player.pos.x = (__uint)_map.w/2;
	player.pos.y = (__uint)_map.h/2;
	player.chback= _map.cfill;

	ll_create(ll);
	map_create();
	map_print();

	for(;;)	// START !
	{
		time(&now);
		tm_now = *localtime(&now);
		strftime(s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
		mbstowcs(ws_now, s_now, sizeof("JJ/MM/AAAA HH:MM:SS"));

		wsprintf(title, L"ASCII_PhysiX (%s)   [%s]", VERSION, ws_now);
		SetConsoleTitle(title);

		Sleep(44);
		hud(*ll);

		if(_kbhit())
		{
			player.key = _getch();
			player_print(&player);
			player_action(player, ll);
			player_block(player, ll);
		}
		map_refresh(ll);
	}

	ll_destroy(ll);
	map_dealloc();

	getchar();

	return 0;
}
