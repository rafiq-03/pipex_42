/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:59:11 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/19 12:00:47 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/pipex.h"

void	ft_lstdelone(t_list *lst, void (*del)(char **, char *, int))
{
	if (lst && del)
		del(lst->command, lst->c_name, lst->flag);
	free(lst);
}

void	del(char **command, char *name, int flag)
{
	int	i;

	if (flag == 1)
		i = 0;
	else
		i = 1;	
	if (!command)
		return ;
	while (command[i])
		free(command[i++]);
	free(command);
	command = NULL;
	free(name);
	name = NULL;
}
