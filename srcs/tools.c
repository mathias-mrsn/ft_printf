#include "ft_printf.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str, int nb, t_options *options)
{
	if (nb == 0)
		return;
	while (*str && nb--)
		ft_putchar(*str++, 1, options);
}

int ft_is_charset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int ft_nbrlen_base(long long n, char *base)
{
	int i;
	int base_len;

	base_len = ft_strlen(base);
	i = 1;
	if (base_len <= 1)
		return (0);
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}
