#include "libtam.h"

void ex_div_mod_ptr(int *a, int *b)
{
	int tj;
	int ti;
	
	if(a && b && *b != 0)
	{	
		ti = *a;
		tj = *b;
		*a = ti / tj;
		*b = ti % tj;
	}
}