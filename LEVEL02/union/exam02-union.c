/* This is my exam 02 code record.
 * May want to improve the code later on*/

#include <unistd.h>

/* clean the string from s1 to s2.
 * If same charactor is found, replace with '\0'.
 * Have s1 and s2's len to make sure check everything to the end.*/
void	ft_rm_double(char *s1, char *s2)
{
	char	c;
	int		s1_len = 0;
	int		s2_len = 0;
	int		i = 0;
	int		j = 0;
	int		z = 0;

	while (s1[s1_len++]); //include '\0';
	while (s2[s2_len++]);

	while (i < s1_len)
	{
		c = s1[i];
		j = i + 1;
		while (j < s1_len)
		{
			if (s1[j] == c)
				s1[j] = '\0';
			j++;
		}
		z = 0;
		while (z < s2_len)
		{
			if (s2[z] == c)
				s2[z] = '\0';
			z++;
		}
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		c = s2[i];
		j = i + 1;
		while (j < s2_len)
		{
			if (s2[j] == c)
				s2[j] = '\0';
			j++;
		}
		i++;
	}
}

/* Have s1 and s2's len.
 * Use ft_rm_double() to clean the string.
 * If *(s + i) is not '\0', write()
 * End with a \n */
void	ft_union(char *s1, char *s2)
{
	int	s1_len = 0;
	int	s2_len = 0;
	int	i = 0;

	while (s1[s1_len++]);
	while (s2[s2_len++]);

	ft_rm_double(s1, s2);

	while (i < s1_len)
	{
		if (s1[i] != '\0')
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		if (s2[i] != '\0')
			write(1, &s2[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

/* If ac == 3, do ft_union()
 * else, write \n */
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	else
		write(1, "\n", 1);
	return (0);
}
