/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:00:28 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/08 09:28:22 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//returns 0 if the file extension is not valid
int	ft_check_ext(char *str, char *ext)
{
	int	size_s;
	int	size_ext;

	size_s = ft_strlen(str);
	size_ext = ft_strlen(ext);
	while (size_ext != 0 && size_s != 0)
	{
		if(str[size_s] != ext[size_ext])
			return (0);
		size_ext--;
		size_s--;
	}
	return (1);
}