#include "libtam.h"

void ex_memdel_arr(void ***arr)
{
	int i;

	i = 0;
	if(arr && *arr)
	{
		while(arr[0][i] != NULL)
		{
			free(arr[0][i]);
			arr[0][i] = NULL;
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}