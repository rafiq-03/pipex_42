/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/14 20:12:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **envp, t_pipex *pipex, t_list *cmd)
{
	(void) pipex;
	(void) envp;
	if (cmd->flag == 0)
	{
		cmd_n_found(cmd->c_name);
		exit(EXIT_FAILURE);
	}
	dup2(cmd->in_fd, STDIN_FILENO);
	dup2(cmd->out_fd, STDOUT_FILENO);
	close_all_pipes(pipex->pfd, pipex->pnb);
	if (-1 == execve(cmd->command[0], cmd->command, envp))
		printf("error in executing command \n");
}
