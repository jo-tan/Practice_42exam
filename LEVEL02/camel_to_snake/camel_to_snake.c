/*
* Assignment name  : camel_to_snake
* Expected files   : camel_to_snake.c
* Allowed functions: malloc, free, realloc, write
* -----------------------------------------------------------------
* 
* Write a program that takes a single string in lowerCamelCase format
* and converts it into a string in snake_case format.
* 
* A lowerCamelCase string is a string where each word begins with a capital letter
* except for the first one.
* 
* A snake_case string is a string where each word is in lower case, separated by
* an underscore "_".*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_valid_string(char *s)
{
	int	i = 0;

	while(s[i])
	{
		if (s[i] < 'A' || s[i] > 'z' || (s[i] > 'Z' && s[i] < 'a'))
			return (0);
		i++;
	}
	return (1);
}

void	camel_to_snake(char *s)
{
	int	i = 0;
	
	while (s[i])
	{
		write(1, &s[i], 1);
		if (s[i + 1] >= 'A' && s[i + 1] <= 'Z')
		{
			write(1, "_", 1);
			s[i + 1] += 32;
		}
		i += 1;
	}
}

int	main(int ac, char **ag)
{
	if (ac == 2 && check_valid_string(ag[1]) == 1)
	{
		camel_to_snake(ag[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}

/*What is a string is with characters which are not letters? There is no description that explain this case.*/
