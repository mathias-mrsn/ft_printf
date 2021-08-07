#include "libft.h"

int	is_c(char s, char c)
{
	if (s == c)
			return (1);
	return (0);
}

int	ft_count_word(const char *str, char c)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] && !is_c(str[i], c))
			++len;
		while (str[i] && !is_c(str[i], c))
			++i;
	}
	return (len);
}

int	ft_word_len(const char *str, char c)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (str[++i] && !is_c(str[i], c))
		++len;
	return (len);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		len;
	int		i;
	int		j;

	if(!str)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < ft_count_word(str, c))
	{
		while (str[i] && is_c(str[i], c))
			++i;
		len = ft_word_len(str + i, c);
		strs[j] = (char *)malloc(sizeof(char) * len + 1);
		if (!strs[j])
			return (NULL);
		ft_strlcpy(strs[j++], str + i, len + 1);
		i += len;
	}
	strs[j] = NULL;
	return (strs);
}