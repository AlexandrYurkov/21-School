//#include "ft_printf.h"
/*#include <stdio.h>

typedef struct s_flags
{
     char mass[10];
}              t_flags;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_strcat (char *dst, char *src)
{
	int	DST;
	int	count;

	DST = ft_strlen(dst);
	count = 0;
	while (src[count])
	{
		dst[DST] = src[count];
		count++;
		DST++;
	}
	dst[DST] = '\0';
	return (count);
}

int ft_putmass(char *s, char c)
{
    int count;

    count = 0;

    if (t_flags.mass != NULL)
    {
         count += ft_strcat(t_flags.mass, c);
         count++;
    }
    else
    {
        t_flags.mass = c;
        count++;
    }
    return (count);
}

int main ()
{
    char *c = "12345";
    for(int i = 0; c[i]; i++)
    {
        ft_putmass(t_flags.mass, c[i]);
    }
    printf("%s", t_flags.mass);
    return 0;
}*/