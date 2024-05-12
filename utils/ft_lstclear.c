/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:29:56 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/12 16:38:50 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

void	ft_lstclear(t_list **lst, void (*del)(char **, char *))
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	if (lst && del)
	{
		while (current)
		{
			tmp = current;
			current = current->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}
