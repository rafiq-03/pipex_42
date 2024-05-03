/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:35:28 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/21 15:30:31 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int nb)
{
	t_list		*node;

	node = malloc (sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> nb = nb;
	node -> next = NULL;
	return (node);
}
