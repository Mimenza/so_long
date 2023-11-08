/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:25:18 by emimenza          #+#    #+#             */
/*   Updated: 2023/09/27 12:51:31 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
// 	ft_lstdelone(&(test[0]->next), delete);
// 	printf("La lista lst tiene %d nodos \n", ft_lstsize(lst));
// }
