#include "libft.h"

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