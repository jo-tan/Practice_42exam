/*
 * Assignment name  : rev_print
 * Expected files   : rev_print.c
 * Allowed functions: write
 * -----------------------------------------------------
 *
 * Write a program that takes a string, 
 * and displays the string in reverse followed by a newline.
 *
 * If the number of parameters is not 1, the program displays a newline.
*/

#include <unistd.h>

void	rev_print(char *s)
{
	int	len = 0;

	while (s[len++]); //include '\0' in the end
	len -= 2; // move to index before NULL char
	while (len >= 0)
	{
		write(1, &s[len], 1);
		len--;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}

/*
 * 1. take one string
 * 	if ac == 2, rev_print(av[1])
 * 	else, write \n
 *
 * 2. void rev_print(char *s)
 * 	int	len = while (s[len++]);
 * 	write from len - 2 (difference between # of length & # of index) to len == 0
 * 	end with write \n
 * 	*/
