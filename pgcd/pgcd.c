/*
 * Assignment name  : pgcd
 * Expected files   : pgcd.c
 * Allowed functions: printf, atoi, malloc, free
 * ------------------------------------------------------------------
 *
 * Write a program that takes two strings representing two strictly positive
 * integers that fit in an int.
 *
 * Display their highest common denominator followed by a newline (It's always a
 * strictly positive integer).
 *
 * If the number of parameters is not 2, display a newline.
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_find_denominator(unsigned int a, unsigned int b)
{
	int	res;

	res = (a > b)?(b/2 + 3):(a/2 + 3);
	while (res != 0)
	{
		if ((a%res == 0) && (b%res == 0))
			break ;
		res--;
	}
	return (res);
}

void	pgcd(char *str1, char *str2)
{
	long long int	s1;
	long long int	s2;

	s1 = atoi(str1);
	s2 = atoi(str2);

	if (s1 < 0 || s2 < 0)
	       printf("\n");
	if (s1 == s2)
		printf("%lli\n", s1);
	else if (s2%s1 == 0)
		printf("%lli\n", s1);
	else if (s1%s2 == 0)
		printf("%lli\n", s2);
	else
		printf("%i\n", ft_find_denominator(s1, s2));
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(av[1], av[2]);
	else
		printf("\n");
	return (0);
}
