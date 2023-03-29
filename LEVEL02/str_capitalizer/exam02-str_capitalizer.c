/* This is my exam 02 code record.
 * May want to improve the code later on*/

#include <unistd.h>

/* All the checker functions I need */
int	ft_is_space(char c)
{
	return (c == '\t' || c == ' ');
}

int	ft_is_uc(char c)
{
	return (c >= 'A' && c <= 'Z' );
}

int	ft_is_lc(char c)
{
	return (c >= 'a' && c <= 'z');
}

/* 6 posibilities to check:
 * > if space ; flag = 1 and write(space)
 * > else if flag = 1 && is lc ; char -= 32, flag = 0 and write(char)
 * > else if flag = 1 && is uc ; flag = 0 and write(char)
 * > else if flag = 0 && is lc ; write(char) << This is not doing much, but I write it down so I know I handle this possibility
 * > else if flag = 0 && is uc ; char += 32 and write(char)
 * > else ; flag = 0 and write(char) << handle case like " ?And " 
 *
 * end with \n */

void	ft_str_cap(char *s)
{
	int	i = 0;
	int flag = 1; //flag means its the start of word. The strat of the string is a word, so flag is initialized to 1

	while (s[i])
	{
		if (ft_is_space(s[i]))
		{
			flag = 1;
			write(1, &s[i], 1);
		}
		else if (flag == 1 && ft_is_lc(s[i]))
		{
			flag = 0;
			s[i] -= 32;
			write(1, &s[i], 1);
		}
		else if (flag == 1 && ft_is_uc(s[i]))
		{
			flag = 0;
			write(1, &s[i], 1);
		}
		else if (flag == 0 && ft_is_lc(s[i]))
		{
			write(1, &s[i], 1);
		}
		else if (flag == 0 && ft_is_uc(s[i]))
		{
			s[i] += 32;
			write(1, &s[i], 1);
		}
		else
		{
			flag = 0;
			write(1, &s[i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int i = 1;

	if (ac <= 1)
		write(1, "\n", 1);
	else
	{
		while (ac > 1)
		{
			ft_str_cap(av[i]);
			i++;
			ac--;
		}
	}
	return (0);
}
