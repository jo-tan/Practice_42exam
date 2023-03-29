/*
 * Assignment name  : rotone
 * Expected files   : rotone.c
 * Allowed functions: write
 * -----------------------------------------------------------------
 *  Write a program that takes a string and displays it, 
 *  replacing each of its letters by the next one in alphabetical order.
 *  'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
 *  The output will be followed by a \n.
 *  If the number of arguments is not 1, the program displays \n.
*/

#include <unistd.h>

void ft_rotone(char *s)
{
	unsigned int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Y')
			s[i] += 1;
		else if (s[i] >= 'a' && s[i] <= 'y')
			s[i] += 1;
		else if (s[i] == 'z' || s[i] == 'Z')
			s[i] -= 25;
		write(1, &s[i++], 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rotone(argv[1]);
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
