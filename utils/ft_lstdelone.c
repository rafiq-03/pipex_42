/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:59:11 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 21:15:10 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

void	ft_lstdelone(t_list *lst, void (*del) (char **))
{
	if (lst && del)
		del(lst->command); 
	free(lst);
}
// I want to add some features here  //
void	del(char **command) // free command;
{
	int i;

	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
	command = NULL;
}
