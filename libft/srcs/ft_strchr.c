#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while(1)
	{
		if(s[i] == (char)c)
			return((char *)s + i);
		if(s[i] == 0)
			return (NULL);
		i++;
	}
	return (NULL);
}