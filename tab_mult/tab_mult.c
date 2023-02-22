/*
* Assignment name  : tab_mult
* Expected files   : tab_mult.c
* Allowed functions: write
* -----------------------------------------------------------------
* 
* Write a program that displays a number's multiplication table.
* 
* The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.
* 
* If there are no parameters, the program displays \n.*/

#include <unistd.h>

int     is_valid_n(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void    ft_putnbr(int i)
{
	char	c;

	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		c = i + '0';
		write(1, &c, 1);
	}
}

int     ft_atoi(char *s)
{
	int	n = 0;
	int	i = 0;

	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

void    tab_mult(int i)
{
	int	res = 0;
	while (res++ < 9)
	{
		ft_putnbr(res);
		write(1, " x ", 3);
		ft_putnbr(i);
		write(1, " = ", 3);
		ft_putnbr(i * res);
		write(1, "\n", 1);
	}
}

int	main(int ac, char ** av)
{
	if (ac == 2 && is_valid_n(av[1]))
		tab_mult(ft_atoi(av[1]));
	else
		write(1, "\n", 1);
	return (0);
}

/*
1. only takes 1 parameter, and no need to handle interger overflow
	parameter must be a valid positive number fits in int
	if no parameters, display \n
	=> guess if more than 1 parameters also display \n

2. need functions:
	void	tab_mult(int i);
	int	is_valid_n(char *s);
	void	ft_putnbr(int i);
	int	ft_atoi(char *s);
*/
