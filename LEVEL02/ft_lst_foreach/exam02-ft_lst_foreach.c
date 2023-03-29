/* This is my exam 02 code record.
 * May want to improve the code later on*/

#include "list.h"

 void	ft_lst_foreach(t_list *begin_lst, void (*f)(void *))
 {
 	t_list	*ptr;

	ptr = begin_lst;

	if (!begin_lst || !f)
		return ;
	while (ptr != NULL)
	{
		(*f)(ptr -> data);
		ptr = ptr -> next;
	}
 }

/* All the functions  which I used to test my ft_lst_foreach() */

t_list	*ft_lst_new(void *value)
{
	t_list	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new -> data = value;
	new -> next = NULL;
	return (new);
}

void	f(void *data)
{
	if (data != NULL)
		printf("hi\n");
}

 int	main(void)
 {
 	int	a = 1;
	int b = 2;
 	t_list	*node1 = ft_lst_new(a);
	t_list	*node2 = ft_lst_new(b);

	t_list	*ptr = node1;
	node1 -> next = node2;

	ft_lst_foreach(node1, f);
	while (ptr)
	{
		printf("%i\n", ptr -> data);
		ptr = ptr -> next;
	}
	return (0);
 }
