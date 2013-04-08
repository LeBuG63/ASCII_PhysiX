#ifndef __DEF_H__
#define __DEF_H__

#include "keys.h"

#define PHYSIC_MODE

#define CFILL	' '
#define CBORDER 'X'

#define HEIGHT	24
#define WIDHT	79

#define NB_BLOCK	8
#define KEY_ANY		255

#define CLASS_ANY	10
#define CLASS_BLOCK	1
#define CLASS_WATER 2

#define CLASS_DUST	3

int	PAUSE;
int CLASS_OBJ;

#ifdef WIN64
	typedef unsigned long int	__uint;
#else
	typedef unsigned int		__uint;
#endif

typedef unsigned char	__byte;

typedef struct _point_t_
{
	__uint	x,	// X coord
			y;	// Y coord
}point_t;

typedef struct _map_t_
{
	__uint	w,		// Widht
			h;		// Height

	__byte	cfill,	// The char that fills the map
			cborder;// Char of the border

	__byte	**arr;	// Map
}map_t;

typedef struct _player_t_
{
	point_t	pos,
			pback;	// Position

	__byte	ch,		// Char's player
			chback;	// Char back
	__byte	key;	// Key statue
}player_t;

typedef struct _block_t_ block_t;

static struct _block_t_
{
	__uint	familly;
	__byte  name[21],
			explication[101];
	point_t	pos;

	__byte	ch,
			key;

	int		can_fall,
			is_water;
}block_id[NB_BLOCK] = {
	{CLASS_DUST,	"Sand",				"Can pass through the elements." ,		0, 0, 177, 's', 1, 0},		// Light block
	{CLASS_BLOCK,	"Wall",				"Fixed.",								0, 0, 219, ' ', 0, 0},		// Wall
	{CLASS_DUST,	"Reverse Block",	"Block subject instead of gravity.",	0, 0, 176, 'r', 1, 0},		// Reverse block
	{CLASS_BLOCK,	"Block",			"Can not pass through the elements.",	0, 0, 206, 'b', 1, 0},		// Heavy block
	{CLASS_BLOCK,	"Grid",				"Grid.",								0, 0, 45,  'g', 0, 0},		// Grid
	{CLASS_ANY,		"Water's Source",	"In progress...",						0, 0, 'V', 'w', 1, 0},		// Water source
	{CLASS_ANY,		"Water",			"In progress...",						0, 0, '~', K_UNKNOWN, 0, 1},// Water
	{CLASS_ANY,		"Piston",			"In progress...",						0, 0, 197, 'p', 1, 0}		// Piston
};

typedef enum _dir_t_
{
	DIR_N,
	DIR_S,
	DIR_W,
	DIR_E
}dir_t;

enum
{
	SAND,
	WALL,
	REVERSE_BLOCK,
	HEAVY_BLOCK,
	GRID,
	WATER_SOURCE,
	WATER,
	PISTON
};

typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE,
    INTESITY = 0x0008,
    //LIGHTBLUE = BLUE | INTESITY,
    DEFAULT = LIGHTGRAY | WHITE,

    bGRAY   = 0x0070,
    bBLUE   = 0x0010,
    bGREEN  = 0x0020,
    bRED    = 0x0040,
    bINTENSITY = 0x0080,
    bBLACK  = 0x0000
} color_t;


#endif /* __DEF_H__ */