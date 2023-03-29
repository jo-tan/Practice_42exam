/*
 * Assignment name  : ft_strdup
 * Expected files   : ft_strdup.c
 * Allowed functions: malloc
 * --------------------------------------------------
 *
 * Reproduce the behavior of the function strdup (man strdup).
 *
 * Your function must be declared as follows:
 *
 * char    *ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int	s_len = 0;
	int	i = 0;
	
	while (src[s_len++]); // legnth include NULL char in the end

	res = (char *)malloc(s_len * sizeof(char));
	if (!res)
		return (NULL);
	while (i <= s_len)
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}



/*int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("my strdup: %s | string.h strdup: %s\n", ft_strdup(av[1]), strdup(av[1]));
	}
	else
		printf("One input a time, please");
	return (0);
}*/

/*string.h expect user always pass valid string to the function
 * which is why there is no protection for undefined behavior like NULL pointer*/
