#include <unistd.h>
#include <stdlib.h>

int	isachar(char *s)
{
	int	i = 0;
	while (s[i++]);
	if (i != 2)
		return (0);
	if (s[0] < 'A' || s[0] > 'z' || (s[0] > 'Z' && s[0] < 'a'))
		return (0);
	return (1);
}

void	search_and_replace(char *s, char *o_char, char *rp_char)
{
	int	i = 0;

	if (!s || !o_char || !rp_char)
	{
		write(1, "\n", 1);
		exit(1);
	}
	if (!isachar(o_char) || !isachar(rp_char))
	{
		write(1, "\n", 1);
		exit(1);
	}
	while (s[i])
	{
		if (s[i] == o_char[0])
			s[i] = rp_char[0];
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		search_and_replace(av[1], av[2], av[3]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}

/*
 * 1. if ac == 4. do search_and_replace() + write 1 "\n"
 * 	else write 1 "\n";
 * 2. if av[1,2,3] are not a valid string (is this nesseccary? can I write an arguement point to NULL in terminal?)
 * 3. have a function to check av[2,3] are one character && a letter (ascii 'A'65-'Z'90 && 'a'97-'z'122)
 * 4. if ag[2 || 3] is not a char && letter, write 1 "\n" and exit(1);
 * 5. while (s[i])
 * 		if s[i] == o_char[0]
 * 			s[i] = rp_char[0]
 * 		write(1, &s[i], 1);
 * 		i++;
 * */
