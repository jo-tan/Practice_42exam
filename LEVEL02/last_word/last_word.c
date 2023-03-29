/*
 * Assignment name  : last_word
 * Expected files   : last_word.c
 * Allowed functions: write
 * ---------------------------------------------------------
 * Write a program that takes a string and displays its last word followed by a \n.
 * A word is a section of string delimited by spaces/tabs or by the start/end of the string.
 *
 * If the number of parameters is not 1, or there are no words, display a newline.
*/

#include <unistd.h>

int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

void	last_word(char *s)
{
	int	i = 0;
	if (!s)
		write(1, "\n", 1);
	while (s[i++]);

	i -= 2;
	while (i > 0 && is_space_tab(s[i]))
		i--;
	while (i > 0 && !is_space_tab(s[i]))
		i--;
	i++;
	while (s[i] && !is_space_tab(s[i]))
	{
		write(1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}

/*
 * 1. if (ac == 2)
 * 	last_word(av[1])
 *
 * 	else
 * 		write 1 "\n"
 * 
 * void last_word(char *s)
 * 2. if av[1] is NULL
 * 	write 1 "\n"
 * 3. function int is_space_tab(char c) to check for the space/tab from the end index =(i -= 2;)
 * 4. while (i > 0 && is_space_tab(s[i]))
 * 	i--;
 * 5. while (i > 0 && !is_space_tab(s[i]))
 * 	i--;
 * 6. while (s[i] && !is_space_tab(s[i]))
 * 	write 1 &s[i]
 * 	i++;
 * 7. end with write 1 "\n"
 * */
