#include "libft.h"

int ft_len(long nb)
{
	int i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void ft_fill(long *nb, int n, int *neg)
{
	if (n < 0)
		(*neg) = 1;
	else
		(*neg) = 0;
	if (n < 0)
		(*nb) = -(long)n;
	else
		(*nb) = n;
}

char *ft_itoa(int n)
{
	long nb;
	int neg;
	int len;
	char *res;

	ft_fill(&nb, n, &neg);
	len = ft_len(nb) + neg;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (nb / 10)
	{
		res[--len] = nb % 10 + 48;
		nb /= 10;
	}
	res[--len] = nb + 48;
	if (neg)
		res[0] = '-';
	return (res);
}