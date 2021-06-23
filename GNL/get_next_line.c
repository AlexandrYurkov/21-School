#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char	*ft_mcpy(void *dst, const void *src)
{
	unsigned char	*d;
	unsigned char	*s;
    int i;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char is_rem(char *rem, char **line)
{
    char *str;

    str = NULL;
    if (rem)
    {
        str = ft_strchr(rem, '\n');
        if (str)
        {
           str = '\0';
           *line = ft_strdup(rem);
           ft_mcpy(rem, ++str);
        }
        else
        {
            *line = ft_strdup(rem);
            ft_strclr(rem);
        }
    }
    else
        *line = ft_strnew(1);
    return (str);
}

int gnl(int fd, char **line)
{
    static char *rem;
    char buff[BUFF_SIZE +1];
    char *point;
    char *tmp;
    int get_read;

    point = is_rem(rem, line);
    get_read = read(fd, buff, BUFF_SIZE);
    while (!point && get_read)
    {
        buff[get_read] = '\0';
        if(point = ft_strchr(buff, '\n'))
        {
            *point = '\0';
            point++;
            rem = ft_strdup(point);
        }
        tmp = *line;
        *line = ft_strjoin(*line, buff);
        if(tmp)
            free (tmp);
    }
    return (0);
}

int main ()
{
    char *line;
    int fd;

    fd = open ("test.txt", O_RDONLY);
    gnl(fd, &line);
    printf("%s\n\n", line);
    return (0);
}