#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char 	*s;
	unsigned char 	*d;
	size_t			i;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = 0;
	while(i < n && s[i] == d[i])
	{
		i++;
	}
	if(i == n)
		return (0);
	return (s[i] - d[i]);
}