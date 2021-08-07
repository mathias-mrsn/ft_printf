#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (dst);
	if(s1 > s2)
		while(len--)
			s1[len] = s2[len];
	else
		while (i < len)
		{
			s1[i] = s2[i];
			i++;	
		}
	return (dst);
}