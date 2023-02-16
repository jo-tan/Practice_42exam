#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*rm_same_char(char *s)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;
	while (s[len++]);

	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] == s[j])
				s[j] = '\0';
			j++;
		}
		i++;
	}
	return (s);
}

void	inter(char *s1, char *s2)
{
	int	s1_len = ft_strlen(s1);
	int	s2_len = ft_strlen(s2);

	int	i = 0;
	int	j = 0;

	s1 = rm_same_char(s1);
	s2 = rm_same_char(s2);

	while (i < s1_len)
	{
		j = 0;
		while (j < s2_len)
		{
			if (s1[i] == s2[j] && s1[i] != '\0')
				write(1, &s1[i], 1);
			j++;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
