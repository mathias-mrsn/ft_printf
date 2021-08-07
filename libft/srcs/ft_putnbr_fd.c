#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if(n < 0)
		nb = -n;
	else
		nb = n;
	if(n < 0)
		ft_putchar_fd('-', fd);
	if(nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
}