#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *newstr;
	size_t	i;

	i = 0;
	if(!s)
		return (NULL);
	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if(!newstr)
		return (NULL);
	while(s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}