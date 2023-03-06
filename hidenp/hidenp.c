/*
 * Assignment name  : hidenp
 * Expected files   : hidenp.c
 * Allowed functions: write
 * -------------------------------------------------------------------
 *
 * Write a program named hidenp that takes two strings and displays 1
 * followed by a newline if the first string is hidden in the second one,
 * otherwise displays 0 followed by a newline.
 *
 * Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
 * find each character from s1 in s2, in the same order as they appear in s1.
 * Also, the empty string is hidden in any string.
 *
 * If the number of parameters is not 2, the program displays a newline.
 * */

#include <unistd.h>
#include <stdio.h>

void	hidenp(char *s1, char *s2)
{
	int	niddle = 0;
	int	i = 0;
	int	j = 0;
	int	l = 0;
	int	s1_len = 0;
	int	s2_len = 0;

	while (s1[s1_len++]); // include the last '\0'
	while (s2[s2_len++]);

	while (i < (s1_len - 1))
	{
		j = l;
		while (j < (s2_len - 1))
		{
			if (s1[i] == s2[j])
			{
				niddle++;
				l = j;
				break ;
			}
			j++;
		}
		i++;
	}
	if (s1[niddle] == '\0')
		niddle++;
	if (niddle == s1_len)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int ac, char ** av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	else
		write(1, "\n",1);
	return (0);
}

/*
 * 1. takes 2 strings
 * 	if ac == 3, hidenp(av[1], av[2])
 * 	else, write \n
 * 2. 	int niddle = 0; // record the last location of s1 if codition meets
 * 	int i = 0; // read s1
 * 	int j = 0; // read s2
 * 	int l = 0; // memorized the last location of j
 * 	int s1_len; (if *s1 = "", its always 1)
 * 	int s2_len;
 * 	if niddle moves to the end of s1, write 1
 * 	else, write 0
 *
 * 	end with write \n to exit hidenp()
 *
 * 	Check case: "" "" or "hello" "hello" >> likely to find error right here
 * */
