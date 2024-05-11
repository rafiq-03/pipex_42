/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:35:28 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 21:23:34 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list		*node;

// 	node = malloc (sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

t_list *ft_lstnew(void)
{
	t_list *node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->flag = 0;
	node->next = NULL;
	node->command = NULL;
	node->in_fd = -1;
	node->out_fd = -1;
	return (node);
}
