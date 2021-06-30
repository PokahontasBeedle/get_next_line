#include "get_next_line.h"

static char	*ft_get_line_reminder(char **line, char *conservation, int reader)
{
	char	*leaks;
	size_t	i;

	i = 0;
	while (conservation[i] != '\n' && conservation[i])
		i++;
	if (i < ft_strlen(conservation))
	{
		*line = ft_substr(conservation, 0, i);
		leaks = conservation;
		conservation = ft_substr(conservation, i + 1, ft_strlen(conservation));
		free(leaks);
	}
	else if (!reader)
	{
		*line = conservation;
		conservation = NULL;
	}
	return (conservation);
}

static char	*ft_conservation(char *bytes, char *conservation)
{
	char	*leaks;

	if (conservation)
	{
		leaks = conservation;
		conservation = ft_strjoin(conservation, bytes);
		free(leaks);
	}
	else
		conservation = ft_strdup(bytes);
	return (conservation);
}

int	get_next_line(int fd, char **line)
{
	char			bytes[BUFFER_SIZE + 1];
	static char		*conservation;
	int				reader;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	reader = read(fd, bytes, BUFFER_SIZE);
	while (reader)
	{
		if (reader == -1)
			return (reader);
		bytes[reader] = '\0';
		conservation = ft_conservation(bytes, conservation);
		if (ft_strchr(bytes, '\n'))
			break ;
		reader = read(fd, bytes, BUFFER_SIZE);
	}
	if (!reader && !conservation)
		*line = ft_strdup("");
	else
		conservation = ft_get_line_reminder(line, conservation, reader);
	if (!reader && !conservation)
		return (reader);
	return (1);
}
