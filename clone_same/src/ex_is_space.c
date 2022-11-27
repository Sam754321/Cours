#include "libtam.h"

int ex_is_space(int c)
{
	if((c>=9 && c<=13 )|| c == 32 )
		return 8192; // pk ?
	return 0;
}