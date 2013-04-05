#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "move.h"
#include "def.h"
#include "addblock.h"
#include "linkedlist.h"

void	player_print(player_t *);
void	player_action(player_t, linkedlist_t *);

#endif /* __PLAYER_H__ */