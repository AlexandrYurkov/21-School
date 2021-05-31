#include "ft_printf.h"
#include "libft.h"

int ft_stardot(char *str, va_list ap, t_flags *flags)
{
    char *tmp;
    if (*str == '*')
        return (va_arg(ap, int));
    else
    {
        while (*str >= 0 && *str <= 9)
        {
            *tmp++ = *str++;
        }
        return (ft_atoi(tmp));
    }
}
