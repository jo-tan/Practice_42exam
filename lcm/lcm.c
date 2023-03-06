/* Assignment name  : lcm
 * Expected files   : lcm.c
 * Allowed functions:
 * ---------------------------------------------------
 * 
 * Write a function who takes two unsigned int as parameters
 * and returns the computed LCM of those parameters.
 *
 * LCM (Lowest Common Multiple) of two non-zero integers is
 * the smallest postive integer divisible by the both integers.
 *
 * A LCM can be calculated in two ways:
 *
 * - You can calculate every multiples of each integers
 *   until you have a common multiple other than 0
 *
 * - You can use the HCF (Highest Common Factor) of these two integers
 *   and calculate as follows:
 *
 * LCM(x, y) = | x * y | / HCF(x, y)
 *
 * | x * y | means "Absolute value of the product of x by y"
 *
 * If at least one integer is null, LCM is equal to 0.
 * 
 * Your function must be prototyped as follows:
 *
 * unsigned int    lcm(unsigned int a, unsigned int b);
 * */

#include <stdio.h>

unsigned int	ft_hcf(const unsigned int a, const unsigned int b)
{
	unsigned int	hcf;

	if (a <= 0 || b <= 0)
		return (0);
	else if (a%b == 0)
		return (b);
	else if (b%a == 0)
		return (a);
	else
		(a > b) ? (hcf = b/2) : (hcf = a/2);
	while (hcf != 0)
	{
		if (a%hcf == 0 && b%hcf == 0)
			break ;
		hcf--;
	}
	return (hcf);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	s_a = a;
	int	s_b = b;
	unsigned int	lcm;
	unsigned int	hcf;
	
	if (s_a <= 0 || s_b <= 0)
		return (0);
	else
	{
		hcf = ft_hcf(a,b);
		lcm = (a/hcf) * (b/hcf) * hcf;
	}
	return (lcm);
}

/*int	main(void)
{
	int a = 80000;
	int b = -220;

	//printf("hcf: %u\n", hcf(a, b));
	printf("lcm: %u\n", lcm(a, b));

	return (0);
}*/

/*
 * a = 30
 * b = 24
 * HCF = 6
 * LCM = 24 * 30 / 6 -> 720/6 = 120
 * 
 * a, b will be an integer value (the largest value is about 2 million)
 * if will be safer to do the math as (a/HCF) * (b/HCF) * hcf to prevent int overflow
 *
 * NEED to handle of a, b is negative number.
 * how the numbers are convert between int and unsigned int.
 * */
