#include "blocks.h"
#include "linkedlist.h"
#include "map.h"
#include "funct.h"

void	piston(linkedlist_t *_ll, point_t *_p, __uint _where, int *_side ,int *_stop)
{
	block_t	block;
	int		where;
	block.pos = *_p;
	if(get_char_x(*_p, 1) != _map.cborder && get_char_x(*_p, 1) != _map.cfill)
	{
		block.pos.x -= 1;
		if((where = get_blockid(block.pos, _ll)) != -1)
		{
			ll_modify_pos(_ll, where, block.pos);
			_map.arr[block.pos.y][block.pos.x] = ' ';
		}
	}
}
