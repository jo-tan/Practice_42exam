/*
 * Assignment name  : epur_str
 * Expected files   : epur_str.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 *
 * Write a program that takes a string, 
 * and displays this string with exactly one space between words,
 * with no spaces or tabs either at the beginning or the end,
 * followed by a \n.
 *
 * A "word" is defined as a part of a string delimited either by spaces/tabs,
 * or by the start/end of the string.
 *
 * If the number of arguments is not 1, 
 * or if there are no words to display, the program displays \n.
 * */

#include <unistd.h>

int	ft_isspace(int	c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	else
		return (0);
}

int	ft_islast(char *s)
{
	unsigned int	i = 0;

	while (s[i])
	{
		if (ft_isspace(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_wd_len(const char *s)
{
	unsigned int	i = 0;

	while(s[i] && ft_isspace(s[i]) != 1)
		i++;
	return (i);
}

void	epur_str(char *s)
{
	unsigned int	i = 0;
	unsigned int	len = 0;
	
	while (s[i])
	{
		if (ft_isspace(s[i]) == 1)
			i++;
		else
		{
			len = ft_wd_len(s+i);
			write(1, &s[i], len);
			i += len;
			if (ft_islast(s+i) == 0)
				write(1, " ", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		epur_str(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
