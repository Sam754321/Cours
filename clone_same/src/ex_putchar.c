#include "libtam.h"
#include <unistd.h>

void ex_putchar(char c)
{
	write(1,&c,1);
}
