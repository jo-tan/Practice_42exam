#include <unistd.h>

/*int	ft_isspace(int	c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	else
		return (0);
}*/

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32)
}

void	rev_wstr(char *s)
{
	int	wc = 0;
	int	i = 0;
	int	len;
	int	a;

	while (s[i])
		if (!ft_isspace(s[i++]) && (!wc || ft_isspace(s[i - 2])))
			++wc;
	while (s[--i])
	{
		if (!ft_isspace(s[i]) && wc--)
		{
			a = 0;
			len = 1;
			while (s[i - 1] && !ft_isspace(s[i - 1]) && ++len)
				--i;
			while (len-- && write(1, &s[i + a++], 1));
			(wc) ? write(1, " ", 1) : 0;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rev_wstr(argv[1]);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
