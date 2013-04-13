#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include "gblocks.h"
#include "mblocks.h"
#include "def.h"

block_t	get_block_char(__byte);
int		get_block(point_t, linkedlist_t *);
int		get_blockid(point_t, linkedlist_t *);

#endif /* __BLOCKS_H__ */