#include "blocks.h"
#include "map.h"

#include <string.h>

block_t	get_block_char(__byte _c)
{
	__uint	i = 0;

	for(i = 0; _c != block_id[i].ch; i++)
		;
	return (block_id[i]);
}

int	 get_block(point_t _p, linkedlist_t *_ll)
{
	node_t	*node = _ll->start;
	int		i = 0,
			j = 0;
	__byte	ch;
	while(node != NULL)
	{		
		i++;
		if(memcmp(&_p, &(node->block.pos), sizeof(point_t)) == 0)
		{
			ch = get_char_y(_p, 0);
			while(block_id[j].ch != ch)
				j++;
			return (j);
		}
		else
			node = node->next;
	}
	return (-1);
}

int get_blockid(point_t _p, linkedlist_t *_ll)
{
	node_t	*node = _ll->start;
	int		i = 0,
			j = 0;

	__byte	ch;
	while(node != NULL)
	{		
		i++;
		if(memcmp(&_p, &(node->block.pos), sizeof(point_t)) == 0)
			return (i);
		else
			node = node->next;
	}
	return (-1);
}