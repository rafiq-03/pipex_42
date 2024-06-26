/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/28 14:34:47 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(char **envp, t_pipex *pipex, t_list *cmd)
{
	if (cmd->flag == 0)
	{
		close_all_pipes(pipex->pfd, pipex->pnb);
		close(pipex->infile_fd);
		close(pipex->outfile_fd);
		cmd_n_found(cmd->c_name);
		exit(EXIT_FAILURE);
	}
	if (cmd->in_fd == -1 || cmd->out_fd == -1)
	{
		close_all_pipes(pipex->pfd, pipex->pnb);
		exit(EXIT_FAILURE);
	}
	dup2(cmd->in_fd, STDIN_FILENO);
	dup2(cmd->out_fd, STDOUT_FILENO);
	close_all_pipes(pipex->pfd, pipex->pnb);
	if (-1 == execve(cmd->command[0], cmd->command, envp))
		perror("bash ");
	clear_all(pipex);
	exit(EXIT_FAILURE);
}
