/*
 * Assignment name  : print_hex
 * Expected files   : print_hex.c
 * Allowed functions: write
 * --------------------------------------------------------------
 *
 * Write a program that takes a positive (or zero) number expressed in base 10,
 * and displays it in base 16 (lowercase letters) followed by a newline.
 *
 * If the number of parameters is not 1, the program displays a newline.
 * */

#include <unistd.h>
#include <stdio.h>
#define HEX "0123456789abcdef"

int	ft_is_valid_d(char *s)
{
	int	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	len = 0;
	long long int	i = 0;
	
	/*If string is not a valid positive numerical string, return -1 as error*/
	if (!ft_is_valid_d(s))
		return (-1);
	/*convert valid string to digit*/
	else
	{
		while (s[len])
		{
			i = i*10 + (s[len] - '0');
			len++;
		}
	}
	return (i);
}

void	ft_print_hex(long long int i)
{
	if (i >= 16)
	{
		ft_print_hex(i / 16);
		ft_print_hex(i % 16);
	}
	else
		write(1, &HEX[i], 1);
}

void	print_hex(char *s)
{
	long long int	i;

	i = ft_atoi(s);
	if (i < 0)
		write(1, "\n", 1);
	else
	{
		ft_print_hex(i);
		write(1, "\n", 1);
	}
}


int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}

/*
 * 1. int main(int ac, char **av)
 * 	if (ac == 2), function print_hex(av[1])
 * 	else, write 1 "\n"
 * 2. void print_hex(char *s)
 * 	check the string is a valid number > 0 (< '0' || > '9')
 * 	int ft_atoi(char *s);
 * 	void ft_print_hex(long long int);convert dex digit to hex and print;
 * */
