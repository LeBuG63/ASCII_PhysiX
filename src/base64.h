#ifndef __BASE64_H__
#define __BASE64_H__

#include "def.h"

unsigned char	*base64_decode(const char *, size_t, size_t *); 
void			build_decoding_table(void);
char			*base64_encode(const __byte *, size_t, size_t *);
void			base64_cleanup();

#endif /* __BASE_H__ */