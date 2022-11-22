#include "libtam.h"

void ex_div_mod_ptr(int *a, int *b)
{
	int tj;
	int ti;	
	// ti est pas déclaré il faut compiler avec les flags pour etre sur d'eviter ce genre d'erreurs.	 // fix
	if(a && b && *b != 0)
	{	
		ti = *a;
		tj = *b;
		*a = ti / tj;
		*b = ti % tj;
	}
}