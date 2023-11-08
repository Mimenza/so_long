/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:48:09 by emimenza          #+#    #+#             */
/*   Updated: 2023/09/26 16:16:14 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Counts the number of nodes in a list.

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
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
// 	printf("La lista lst tiene %d nodos", ft_lstsize(lst));
// }