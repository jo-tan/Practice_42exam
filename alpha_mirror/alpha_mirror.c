/*
 * Assignment name  : alpha_mirror
 * Expected files   : alpha_mirror.c
 * Allowed functions: write
 * -------------------------------------------------------------------
 *
 * Write a program called alpha_mirror that takes a string
 * and displays this string after replacing each alphabetical character
 * by the opposite alphabetical character, followed by a newline.
 *
 * 'a' becomes 'z', 'Z' becomes 'A'
 * 'd' becomes 'w', 'M' becomes 'N'
 *
 * and so on.
 *
 * Case is not changed.
 *
 * If the number of arguments is not 1, display only a newline.
 * */

#include <unistd.h>

int	is_ualph(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lalph(char c)
{
	return (c >= 'a' && c <= 'z');
}

void	alpha_mirror(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if(is_ualph(s[i]))
		{
			if (s[i] < 'N')
				s[i] = ('N' + ('N' - s[i] - 1));
			else
				s[i] = ('M' - (s[i] - 'M' -1));	
		}
		if(is_lalph(s[i]))
		{
			if (s[i] < 'n')
				s[i] = ('n' + ('n' - s[i] - 1));
			else
				s[i] = ('m' - (s[i] - 'm' -1));	
		}
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
