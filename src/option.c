#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "options.h"
#include "map.h"

void	open_option(void)
{
	__uint	c,
			i = 0;
	char	str[15] = {0};

	FILE	*file = NULL;

	if(!(file = fopen("options.opt", "r")))
		exit(1);
	do
	{
		c = fgetc(file);

		if(c != '\n')
		{
			str[i] = c;
			i++;
		}
		else
		{
			if(strstr(str, SHEIGHT))
				_map.h = get_number(str);
			else if(strstr(str, SWIDHT))
				_map.w = get_number(str);
			else if(strstr(str, SCFILL))
				_map.cfill = get_char(str);
			else if(strstr(str, SCBORDER))
				_map.cborder = get_char(str);
			else
				;
			memset(str, '\0', sizeof(str));
			i = 0;
		}
	}while(c != EOF);
}

__uint	get_number(const char *_str)
{
	__uint	nb,
			i = 0;
	char	str[3] = {0};

	while(!isdigit(*_str))
		_str++;

	while(_str[i] != '\0')
	{
		str[i++] = _str[i];
	}
	nb = atol(str);
	return(nb);
}

__byte	get_char(const char *_str)
{
	__byte	ch;
	int		i = 0;

	while(_str[i] != '=')
		i++;

	ch = _str[i + 1];

	return(ch);
}
