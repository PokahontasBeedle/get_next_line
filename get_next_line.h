#ifndef  GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>
# include   <stddef.h>

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 4000
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int ch);
#endif