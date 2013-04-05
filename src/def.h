#ifndef __DEF_H__
#define __DEF_H__

#define PHYSIC_MODE

#define CFILL	' '
#define CBORDER 'X'

#define HEIGHT	24
#define WIDHT	79

#define NB_BLOCK	7
#define KEY_ANY		255

int	PAUSE;

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
	__byte  name[21],
			explication[101];
	point_t	pos;

	__byte	ch,
			key;

	int		can_fall,
			is_water;
}block_id[NB_BLOCK] = {
	{"Light Block",		"Can not pass through the elements." ,	0, 0, 177, 'l', 1, 0},	// Light block
	{"Wall",			"Fixed.",								0, 0, 219, ' ', 0, 0},	// Wall
	{"Reverse Block",	"Block subject instead of gravity.",	0, 0, 176, 'r', 1, 0},	// Reverse block
	{"Heavy Block",		"Can pass through the elements.",		0, 0, 206, 'L', 1, 0},	// Heavy block
	{"Water's Source",	"In progress...",						0, 0, 'V', 'w', 1, 0},	// Water source
	{"Water",			"In progress...",						0, 0, '~', KEY_ANY, 0, 1},		// Water
	{"Piston",			"In progress...",						0, 0, 197, KEY_ANY, 1}		// Piston
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
	LIGHT_BLOCK,
	WALL,
	REVERSE_BLOCK,
	HEAVY_BLOCK,
	WATER_SOURCE,
	WATER
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