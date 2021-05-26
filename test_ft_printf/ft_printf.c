#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct flags
{
	int minus;
	int zero;
	unsigned int star;
	unsigned int dot;
} ;


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

static char	*ft_strcpy(char *dsr, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dsr[i] = src[i];
		i++;
	}
	dsr[i] = '\0';
	return (dsr);
}

static int	ft_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int ft_sp(const char *c, va_list ap, int i, struct flags *flag)
{
	char *p;
	int n;
	char *r;
	int d;
	int s;

	if (c[i] == 'd' || c[i] == 'i')
	{
		n = va_arg(ap, int);
		if(flag->minus == 1 && flag->zero == 0)
		{
			if(flag->dot > 0)
				d = flag->dot - ft_strlen(ft_itoa(n));
			if(flag->star > 0)
			{
				s = flag->star - ft_strlen(ft_itoa(n) + d);
			}



		}
		ft_putnbr_fd(n, 1);
	}
	else if (c[i] == 's')
	{
		char *p;
		p = va_arg(ap, char *);

		ft_putstr_fd(p, 1);
	}
	return (i);
}

void ft_flag (const char *c, va_list ap, int i, struct flags *flag)
{
	if(c[i] == '-')
		flag->minus = 1;
	else 
		flag->minus = 0;
	if(c[i] == '0')
		flag->zero = 1;
	else 
		flag->zero = 0;
	if(c[i] == '*')//ширина
		flag->star = va_arg(ap, int);
	else if(c[i] >= '0' && c[i] <= '9')//ширина
	{
		while (c[i] >= '0' && c[i] <= '9')
		{
			flag->star = ft_atoi (c[i]);
			i++;
		}
	}
	if(c[i] == '.')// точность
	{
		i++;
		if(c[i] == '*')
			flag->dot = va_arg(ap, int);
		else if(c[i] >= '0' && c[i] <= '9')
		{
			while (c[i] >= '0' && c[i] <= '9')
			{
				flag->dot = ft_atoi (c[i]);
				i++;
			}
		}
		else
			flag->dot = 0;
	}
	if(flag->minus == 0 && flag->star == 0 && flag->zero == 0 && flag->dot == 0)
		return;
}

int ft_printf(const char *c, ...)
{
	va_list ap;
	struct flags *flag;

	int i;

	if(!c)
		return 0;

	i = 0;
	va_start(ap, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			i++;
			ft_flag(c, ap, i, flag);
			ft_sp(c, ap, i, flag);
			i++;
			continue;
		}
		else
			write(1, &c[i], 1);
		i++;
	}
	va_end(ap);
	printf("%d", i);
	return (i);
}

int main ()
{
	int i = 987;
	ft_printf("12345 %i %s ", i, "hello");
	printf("\n\n");
	printf("12345 %i %.*s ", i, 10, "hello");
	return 0;
}
