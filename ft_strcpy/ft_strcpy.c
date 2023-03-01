#include <unistd.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	src_len = 0;
	int	i = 0;

	while (s2[src_len++]);
	if (s1 == s2)
		return (s1);
	if (s2 > s1)
	{
		while (i != src_len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	if (s2 < s1)
	{
		while (src_len != 0)
		{
			s1[src_len] = s2[src_len];
			src_len--;
		}
	}
	return (s1);
}

/*int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 3)
	{
		while(av[2][i++]);
		write(1, ft_strcpy(av[1], av[2]), i);
		write (1, "\n", 1);

		write(1, strcpy(av[1], av[2]), i);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}

result as below:
e2r2p22% gcc -Wall -Werror -Wextra ft_strcpy.c -o ft_strcpy
e2r2p22% ./ft_strcpy

e2r2p22% ./ft_strcpy "" "hello"
hello
ello
e2r2p22% ./ft_strcpy "weeee" "hello"
hello
hello
e2r2p22% ./ft_strcpy "we" "hello"
hello
lolo
e2r2p22% ./ft_strcpy "test string" "hello"
hello
hello
e2r2p22% ./ft_strcpy "?" "hello"
hello
lloo
e2r2p22% ./ft_strcpy "?" "hello" | cat -e
hello^@$
llo^@o^@$
e2r2p22% ./ft_strcpy "weeee" "hello" | cat -e
hello^@$
hello^@$


something is overlap. Need to think how to fix this problem
*/
