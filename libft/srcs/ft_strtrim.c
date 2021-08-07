#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	if(!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while(s1[i] && ft_is_charset(s1[i], (char *)set))
		i++;
	while(--j > i && ft_is_charset(s1[j], (char *)set));
	trim = malloc(sizeof(char) * (j - i + 1));
	if(!trim)
		return (NULL);
	j -= i - 1;
	index = 0;
	while(index < j)
	{
		trim[index] = s1[i];
		i++;
		index++;
	}
	trim[index] = '\0';
	return (trim);
}
