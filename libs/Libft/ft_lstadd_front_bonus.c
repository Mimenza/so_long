/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:49:00 by emimenza          #+#    #+#             */
/*   Updated: 2023/09/27 12:28:29 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the node ’new’ at the beginning of the list.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

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
// 	printf("El ultimo nodo de la lista es %s \n", (ft_lstlast(lst))->content);
// }