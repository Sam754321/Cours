#include "libtam.h"
#include <stdlib.h>

void ex_memdel(void **p)
{
	if(p)
	{
		free(*p);
		*p = NULL;
	}
}