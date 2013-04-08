#include "blocks.h"
#include "linkedlist.h"
#include "map.h"
#include "funct.h"

void	piston(linkedlist_t *_ll, point_t *_p, __uint _where, int *_side ,int *_stop)
{
	block_t	block;

	if(get_char_x(*_p, 1) != _map.cborder)
	{
		block = get_block_char(get_char_x(*_p, -1));
		block.pos.x -= 1;
		ll_modify_pos(_ll, get_id_block(block.pos, _ll), block.pos);
	}
}
