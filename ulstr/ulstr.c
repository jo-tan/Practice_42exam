/*
 * Assignment name  : ulstr
 * Expected files   : ulstr.c
 * Allowed functions: write
 * --------------------------------------------------------------------
 *
 * Write a program that takes a string and reverses the case of all its letters.
 * Other characters remain unchanged.
 *
 * You must display the result followed by a '\n'.
 *
 * If the number of arguments is not 1, the program displays '\n'.
 * */

#include <unistd.h>

void	ulstr(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (((s[i] >= 'A' && s[i] <= 'Z')?1:0) == 1)
			s[i] += 32;
		else if (((s[i] >= 'a' && s[i] <= 'z')?1:0) == 1)
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
