/*Assignment name  : inter
 * Expected files   : inter.c
 * Allowed functions: write
 * ----------------------------------------------------------------------
 *
 * Write a program that takes two strings and displays, without doubles, the
 * characters that appear in both strings, in the order they appear in the first one.
 *
 * The display will be followed by a \n.
 *
 * If the number of arguments is not 2, the program displays \n.
 * */

#include <unistd.h>

char	*rm_double(char *s)
{
	int	i = 0;
	int	j = 0;
	int	s_end = 0;

	while (s[s_end++]); // length include last '\0'

	while (i < s_end)
	{
		j = i + 1;
		while (j < s_end)
		{
			if (s[i] == s[j] && s[i] != '\0')
				s[j] = '\0';
			j++;
		}
		i++;
	}
	return (s);
}

void	inter(char *s1, char *s2)
{
	int	s1_len = 0;
	int	s2_len = 0;
	int	i = 0;
	int	j = 0;

	while (s1[s1_len++]);
	while (s2[s2_len++]);

	s1 = rm_double(s1);
	s2 = rm_double(s2);

	while (i < s1_len)
	{
		j = 0;
		while (j < s2_len)
		{
			if (s1[i] == s2[j] && s1[i] != '\0')
			{
				write(1, &s1[i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	else
		write(1, "\n",1);
	return (0);
}

/*
 	1. takes two strings
		if ac == 3, inter(av[1], av[2]);
		else write \n
	2. remove double char in s1 and s2 (rm_double())
	3. while (i < s1_len)
		j = 0
		while (j < s2_len)
			if (s1[i] == s2[j] && s1[i] != '\0')
				write(1, &s1[i], 1);
				j++;
				break;
			j++;
		i++;
	write(1, "\n", 1); // END of inter()

	check case: 
	./inter aasssssssaa aaaaaaaaas | cat -e
	as$
	./inter aaaa aaaaaaaaas | cat -e
	a$
 */
