#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*dstr;
	size_t	i;

	i = 0;
	dstr = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1));
	if (dstr)
	{
		while (str[i])
		{
			dstr[i] = str[i];
			i++;
		}
		dstr[i] = '\0';
	}
	return (dstr);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	c;
	size_t			i;
	char			*temp;

	i = 0;
	temp = (char *)str;
	c = (char)ch;
	while (temp[i])
	{
		if (temp[i] == c)
			return (&temp[i]);
		i++;
	}
	if (c == '\0')
		return (&temp[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		if (ft_strlen(s + start) < len)
			len = ft_strlen(s + start);
		substr = malloc((len + 1) * sizeof(char));
		if (!substr)
			return (NULL);
		i = 0;
		while (s[i] && i < len)
			substr[i++] = s[start++];
		substr[i] = '\0';
		return (substr);
	}
}
