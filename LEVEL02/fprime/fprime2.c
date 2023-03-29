/*
 * Assignment name  : fprime
 * Expected files   : fprime.c
 * Allowed functions: printf, atoi
 * -------------------------------------------------------
 *
 * Write a program that takes a positive int and 
 * displays its prime factors on the standard output,
 * followed by a newline.
 * 
 * Factors must be displayed in ascending order and separated by '*',
 * so that the expression in the output gives the right result.
 *
 * If the number of parameters is not 1, simply display a newline.
 *
 * The input, when there is one, will be valid.
 * */

#include <stdlib.h>
#include <stdio.h>

void	ft_print_prime(long int nbr)
{
	long int	lcf = 2;
	if (nbr >= 2)
	{
  		while (nbr % lcf != 0)
  			lcf++;
  		printf("%li", lcf);
		(lcf < nbr)? printf("*"):0;
		if (lcf < nbr)
			ft_print_prime(nbr/lcf);
	}
	if (nbr < 2)
		printf("%li", nbr);
}

void	fprime(char *s)
{
	long int nbr = atoi(s);
	if (nbr > 0)
		ft_print_prime(nbr);
	printf("\n");
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	else
		printf("\n");
	return (0);
}

/*
 * int	main(int, char **)
 * 	if ac == 2, fprime(av[1]);
 * 	else, printf \n;
 *
 * void	fprime(*s)
 * {
 * 	1. long int nbr = atoi(*s);
 * 	2. if nbr> 0 (0 should be undefined, so just \n)
 * 		ft_print_prime(nbr);
 * 	3. end with \n
 * }
 *
 * void	ft_print_prime(long int	nbr)
 * 	long int lcf = 2;
 * 	if (nbr >= 2)
 * 	{
 * 		while (nbr%lcf != 0)
 * 		{
 * 			lcf++;
 * 		}
 * 		printf lcf;
 * 		if (lcf < nbr), add star
 * 		if lcf < nbr, call ft_print_prime(nbr/lcf) again 
 *
 * 	}
 * 	if (nbr < 2)
 * 		printf(nbr)
 * 	
 * */
