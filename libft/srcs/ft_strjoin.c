#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t 	i;
	size_t 	j;
	char	*newstr;

	if(!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (i + j + 1));
	if(!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while(s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}