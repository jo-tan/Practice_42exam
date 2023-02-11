/*
 * Assignment name  : ft_strcmp
 * Expected files   : ft_strcmp.c
 * Allowed functions:
 * -----------------------------------------------------------------------
 *  Reproduce the behavior of the function strcmp (man strcmp).
 *  Your function must be declared as follows:
 *
 * int    ft_strcmp(char *s1, char *s2);
 * */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("my ft_strcmp: %i\n", ft_strcmp(argv[1],argv[2]));
		printf("Original strcmp: %i\n", strcmp(argv[1],argv[2]));
	}
	else
		printf("wrong argc number. you need two. ex ./test abc abc");
	return (0);
}*/
