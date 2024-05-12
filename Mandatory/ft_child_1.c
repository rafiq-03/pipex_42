/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/12 16:43:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **envp, t_list *cmd)
{
	if (cmd->flag == 0)
	{
		ft_putstr_fd(cmd->c_name, 2);
		ft_putendl_fd("Command not found", 2);
		exit(EXIT_FAILURE);
	}
	execve(cmd->command[0], cmd->command, envp);
}


