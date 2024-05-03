/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:29:56 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/28 17:19:46 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	if (lst)
	{
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
