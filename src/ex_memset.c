#include "libtam.h"

void ex_memset(void *p, unsigned long long size, char c)
{
	unsigned long long i;
	char *t;

	i = 0;
	t = (char *)p;
	if (!p || size <= 0)
		return;
	while(i < size)
	{
		t[i] = c;
		i++;
	}
}