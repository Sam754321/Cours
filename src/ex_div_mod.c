#include "libtam.h"

void ex_div_mod(int a, int b, int *div, int *mod)
{
	if(b != 0 && div && mod)
	{
		*div = a / b;
		*mod = a % b;
	}// ligne vide en trop
}