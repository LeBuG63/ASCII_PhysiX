#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>

#include "def.h"

typedef struct _node_t
{
	block_t			block;
	struct _node_t	*next;
}node_t;

typedef struct _linkedlist_t_
{
	node_t	*start,
			*end;

	size_t	size;
}linkedlist_t;

void	ll_create(linkedlist_t *);
void	ll_destroy(linkedlist_t *);

void	ll_add(linkedlist_t *, block_t, point_t);

void	ll_print(linkedlist_t *);
__byte	ll_at(linkedlist_t *, __uint , point_t *);
void	ll_modify_pos(linkedlist_t *, __uint, point_t);

#endif /* __LINKEDLIST_H__ */