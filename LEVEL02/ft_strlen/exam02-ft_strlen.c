/* This is my exam 02 code record.
 * May want to improve the code later on*/

 int	ft_strlen(char *s)
 {
 	int	len = 0;

	while (s[len])
		len++;
	return (len);
 }

/* main for checking the function can be compiled and is functional*/
/*#include <stdio.h>
 int	main(void)
 {
 	char	*s = "test";

	printf("%d\n", ft_strlen(s));

	return (0);
 }*/
