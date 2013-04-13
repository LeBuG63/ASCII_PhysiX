#include "addblock.h"
#include "blocks.h"
#include "map.h"
#include "keys.h"
#include "def.h"

void	player_block(player_t _p, linkedlist_t *_ll)
{
	if(!obstacle(_p.pos, 1, DIR_S))
	{
		_p.pos.y++;

		if(_p.key == block_id[SAND].key && block_id[SAND].familly == CLASS_OBJ)
			map_add_block(block_id[SAND], _p.pos, _ll);

		else if(_p.key == block_id[WALL].key && block_id[WALL].familly == CLASS_OBJ)
			map_add_block(block_id[WALL], _p.pos, _ll);

		else if(_p.key == block_id[HEAVY_BLOCK].key && block_id[HEAVY_BLOCK].familly == CLASS_OBJ)
			map_add_block(block_id[HEAVY_BLOCK], _p.pos, _ll);

		else if(_p.key == block_id[GRID].key && block_id[GRID].familly == CLASS_OBJ)
			map_add_block(block_id[GRID], _p.pos, _ll);

		else if(_p.key == block_id[WATER].key && block_id[WATER].familly == CLASS_OBJ)
			map_add_block(block_id[WATER], _p.pos, _ll);

		else if(_p.key == block_id[PISTON].key && block_id[PISTON].familly == CLASS_OBJ)
			map_add_block(block_id[PISTON], _p.pos, _ll);
		else
			;
	}

	if(!obstacle(_p.pos, 1, DIR_N))
		if(_p.key == block_id[REVERSE_BLOCK].key && block_id[REVERSE_BLOCK].familly == CLASS_OBJ)
		{
			_p.pos.y -= 2;
			map_add_block(block_id[REVERSE_BLOCK], _p.pos, _ll);
		}
}
