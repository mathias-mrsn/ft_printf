#include "../../includes/ft_printf.h"

int	ft_is_charset(char c, char *set)
{
	while(*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

int			ft_nbrlen_base(long long n, char *base)
{
	int			i;
	int			base_len;

	base_len = ft_strlen(base);
	i = 1;
	if(base_len <= 1)
		return (0);
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

void	ft_putchar(char c, int fd, t_options *options)
{
	write(fd, &c, 1);
	options->printed_length++;
}