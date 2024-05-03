/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_prev_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:19:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/28 17:19:32 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_prev_last(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->next->next == NULL)
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}
