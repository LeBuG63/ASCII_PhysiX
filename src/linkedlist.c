#include <stdlib.h>

#include "linkedlist.h"

void	ll_create(linkedlist_t *_ll)
{
	_ll->start = _ll->end = NULL;
	_ll->size  = 0;
}

void	ll_destroy(linkedlist_t *_ll)
{
	node_t	*node = _ll->start, *tmp = NULL;

	while(node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}

	_ll->size = 0;
}

void	ll_add(linkedlist_t *_ll, block_t _block, point_t _p)
{
	node_t	*new_elem = NULL;

	if((new_elem = (node_t*)malloc(sizeof(node_t))) == NULL)
		exit(1);

	new_elem->block		= _block;
	new_elem->block.pos = _p;
	new_elem->next		= NULL;

	if(_ll->end)
		_ll->end->next = new_elem;
	else
		_ll->start = new_elem;
	_ll->end = new_elem;

	_ll->size++;
}

void	ll_print(linkedlist_t *_ll)
{
	node_t	*node = _ll->start;
	__uint	i = 0;


	while(i < _ll->size)
	{
		putchar(node->block.ch);
		node = node->next;
		i++;
	}
}

__byte	ll_at(linkedlist_t *_ll, __uint _where, point_t *_p)
{
	node_t	*node = _ll->start;
	__uint	i = 0;

	while(i < _where)
	{
		node = node->next;
		i++;
	}

	*_p = node->block.pos;
	return(node->block.ch);
}

void	ll_modify_pos(linkedlist_t *_ll, __uint where, point_t new_pos)
{
	node_t	*node = _ll->start;
	__uint	i = 0;

	while(i < where)
	{
		node = node->next;
		i++;
	}
	node->block.pos = new_pos;
}
