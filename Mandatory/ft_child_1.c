/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/14 13:23:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **envp, t_pipex *pipex, t_list *cmd)
{
	(void) pipex;
	if (cmd->flag == 0)
	{
		cmd_n_found(cmd->c_name);
		exit(EXIT_FAILURE);
	}
	// printf("index : %d\n", cmd->index);
	dup2(cmd->in_fd, 0);
	dup2(cmd->out_fd, 1);
	close(cmd->in_fd);
	close(cmd->out_fd);
	execve(cmd->command[0], cmd->command, envp);
}
