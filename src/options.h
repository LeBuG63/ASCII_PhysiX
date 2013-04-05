#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include "def.h"

#define SWIDHT	"widht="
#define SHEIGHT	"height="
#define SCBORDER "char_border="
#define SCFILL	"char_fill="

void	open_option(void);
__uint	get_number(const char *);
__byte	get_char(const char *);

#endif /* __OPTIONS_H__ */