#include "blocks.h"

block_t	get_block_char(__byte _c)
{
	__uint	i = 0;

	for(i = 0; _c != block_id[i].ch; i++)
		;
	return (block_id[i]);
}
