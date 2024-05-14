/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:59:11 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/12 18:47:58 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

void	ft_lstdelone(t_list *lst, void (*del)(char **, char *))
{
	if (lst && del)
		del(lst->command, lst->c_name);
	free(lst);
}
// I want to add some features here  //
void	del(char **command, char *name) // free command;
{
	int i;

	i = 0;
	if (!command)
		return ;
	while (command[i])
		free(command[i++]);
	free(command);
	command = NULL;
	if (name)
	{
		free(name);
		name = NULL; // free command name
	}
}
