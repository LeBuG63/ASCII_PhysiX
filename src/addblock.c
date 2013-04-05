#include "addblock.h"
#include "blocks.h"
#include "map.h"
#include "keys.h"

void	player_block(player_t _p, linkedlist_t *_ll)
{
	_p.pos.y++;

	if(_p.key == block_id[LIGHT_BLOCK].key)
		map_add_block(block_id[LIGHT_BLOCK], _p.pos, _ll);

	else if(_p.key == block_id[WALL].key)
		map_add_block(block_id[WALL], _p.pos, _ll);

	else if(_p.key == block_id[REVERSE_BLOCK].key)
	{
		_p.pos.y -= 2;
		map_add_block(block_id[REVERSE_BLOCK], _p.pos, _ll);
	}

	else if(_p.key == block_id[HEAVY_BLOCK].key)
		map_add_block(block_id[HEAVY_BLOCK], _p.pos, _ll);

	else if(_p.key == block_id[WATER].key)
		map_add_block(block_id[WATER], _p.pos, _ll);
	else
		;

}
