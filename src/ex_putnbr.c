#include "libtam.h"


void ex_putnbr(int nb)
{
	if(nb < 0)
	{
		ex_putchar('-');
		if(nb == -2147483648)
		{
			nb = -147483648;
		ex_putchar('2');
		}
		nb *= -1;
	}
	if(nb < 10)
	{
		ex_putchar(nb + 48);
	}
	else{
		ex_putnbr(nb / 10);
		ex_putnbr(nb % 10);
	}
}