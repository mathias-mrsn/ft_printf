#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = 0;
	while (dest[l] && l < size)
		l++;
	i = 0;
	while (src[i] && size && l + i < size - 1)
	{
		dest[l + i] = src[i];
		i++;
	}
	if (l < size)
		dest[l + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (l + i);
}