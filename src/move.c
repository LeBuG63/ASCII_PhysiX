#include "move.h"
#include "keys.h"

void	player_move(player_t *_player)
{
	_player->pback  = _player->pos;
	_player->chback = _map.arr[_player->pos.y][_player->pos.x];

	switch(_player->key)
	{
	case K_UP:
		if(_map.arr[_player->pos.y - 1][_player->pos.x] != _map.cborder)
			_player->pos.y--;
		break;
	case K_DOWN:
		if(_map.arr[_player->pos.y + 1][_player->pos.x] != _map.cborder)
			_player->pos.y++;
		break;
	case K_LEFT:
		if(_map.arr[_player->pos.y][_player->pos.x - 1] != _map.cborder)
			_player->pos.x--;
		break;
	case K_RIGHT:
		if(_map.arr[_player->pos.y][_player->pos.x + 1] != _map.cborder)
			_player->pos.x++;
		break;
	default:
		;
	}
}
