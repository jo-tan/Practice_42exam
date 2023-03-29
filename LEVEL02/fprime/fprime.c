/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.*/

#include <stdlib.h>
#include <stdio.h>

void	add_star(int int1, int int2)
{
	if (int1 != int2 && int1 > int2)
		printf("*");
}

void	ft_find_print_prime(int i)
{
	long long int n = i;
	int	dem = 2;

	if (n >= 2)
	{
		while (n % dem != 0)
		{
			dem++;
		}
		printf("%i", dem);
		add_star(n, dem);
		if (dem < n)
			ft_find_print_prime(n / dem);
	}
	if (n < 2)
		printf("%lli", n);
}

void	fprime(int i)
{
	if (i > 0)
		ft_find_print_prime(i);
	printf("\n");
}

int	main(int ac, char ** ag)
{
	if (ac == 2)
		fprime(atoi(ag[1]));
	else
		printf("\n");
	return (0);
}
