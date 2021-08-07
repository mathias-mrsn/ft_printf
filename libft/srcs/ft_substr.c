#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char	*new;

	i = 0;
	if(!s)
		return (NULL);
	if(ft_strlen(s) <= start)
		len = 0;
	new = malloc(sizeof(char) * (len + 1));
	if(!new || !s)
		return (NULL);
	while(s[i + start] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}