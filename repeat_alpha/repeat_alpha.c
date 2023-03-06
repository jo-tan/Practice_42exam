#include <unistd.h>

/*
 * Assignment name  : repeat_alpha
 * Expected files   : repeat_alpha.c
 * Allowed functions: write
 * -------------------------------------------------------------------
 *
 * Write a program called repeat_alpha that takes a string and display it
 * repeating each alphabetical character as many times as its alphabetical index,
 * followed by a newline.
 *
 * 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
 *
 * Case remains unchanged.
 *
 * If the number of arguments is not 1, just display a newline.
*/

void	alpha_print(const char c)
{
	int	print_time;

	if ((int)c < 97)
	{
		print_time = c - 'A';
		while (print_time >= 0)
		{
			write(1, &c, 1);
			print_time--;
		}
	}
	else
	{
		print_time = c - 'a';
		while (print_time >= 0)
		{
			write(1, &c, 1);
			print_time--;
		}
	}
}

void	repeat_alpha(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if ((((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))? 1:0) == 1)
			alpha_print(s[i]);
		else
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}

/*
 * 1. takes a string and display it -> 1 string
 	if (ac == 2), do repeat_alpha with av[1]
	else, \n and exit
   2. if the char in *s is alpha, have an int represent is number in aphlabet
   -> is_alpha?1:0 (in repeat_alpha())
   --> int = 'a' - 97  or 'A' - 65 (in alpha_print())
   --> repeat write() according to the int (in alpha_print())
   3. read the string and print
  	if is_aplha, print accoring to step 2 (alpha_print)
	if char is not alpha, write the char
	i++;
   write \n at the end to finish the task.
 * */
