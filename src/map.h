#ifndef __MAP_H__
#define __MAP_H__

#include "def.h"
#include "linkedlist.h"

map_t	_map;

void	map_create(void);
void	map_alloc(void);
void	map_dealloc(void);

void	map_fill(void);
void	map_border(void);
void	map_print(void);
void	map_refresh(linkedlist_t *);

__byte	get_char_x(point_t, __uint);
__byte	get_char_y(point_t, __uint);
void	map_add_block(block_t, point_t, linkedlist_t *);

int		obstacle(point_t , __uint, dir_t);

#endif /* __MAP_H__ */