/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:51:14 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/05 16:05:54 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// static char	*custom_toupper(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			str[i] = str[i] - 32;
// 		i++;
// 	}
// 	return (str);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	**test;

// 	lst = 0;
// 	test = &(lst);
// 	ft_lstadd_front(test, ft_lstnew("lst1"));
// 	ft_lstadd_front(test, ft_lstnew("lst2"));
// 	ft_lstadd_front(test, ft_lstnew("lst3"));
// 	ft_lstadd_front(test, ft_lstnew("lst4"));
// 	printf("contenido de la lista es: %s", ft_lstiter(lst, custom_toupper));
// }