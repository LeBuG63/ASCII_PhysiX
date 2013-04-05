#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
# define debug(M, ...) fprintf(stderr, "[DEBUG] - %d: " M, __LINE__, ##__VA_ARGS__)
#else
# define debug(msg, ...)
#endif


#endif /* __DEBUG_H__ */