/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:01:00 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/04 12:05:57 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst);
			*lst = (*lst)->next;
			del(tmp->content);
			free(tmp);
		}
	}
}

// void	delete(void *content)
// {
// 	*(char *)content = 0;
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	**test;

// 	lst = 0;
// 	test = &(lst);
// 	ft_lstadd_back(test, ft_lstnew("lst1"));
// 	ft_lstadd_back(test, ft_lstnew("lst2"));
// 	ft_lstadd_back(test, ft_lstnew("lst3"));
// 	ft_lstadd_back(test, ft_lstnew("lst4"));
// 	printf("La lista lst tiene %d nodos \n", ft_lstsize(lst));
// 	ft_lstclear(test, delete);
// 	printf("La lista lst tiene %d nodos \n", ft_lstsize(lst));
// }
