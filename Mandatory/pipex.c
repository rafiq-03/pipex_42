/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/18 17:50:49 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	t_list	*cmd;

	check_command_line(ac);
	init_struct(&pipex, ac, av);
	search_paths(&pipex, envp);
	init_commands(ac, av, &pipex);
	fill_fd(&pipex);
	cmd = pipex.command;
	while (cmd)
	{
		if (cmd->flag == 0)
			pipex.exit_flag++;
		pipex.pid = fork();
		if (pipex.pid == -1)
			clear_all(&pipex);
		if (pipex.pid == 0)
			child(envp, &pipex, cmd);
		else
			_close_in_out(cmd->out_fd, cmd->in_fd);
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
	clear_all(&pipex);
}

void	_close_in_out(int in, int out)
{
	close (in);
	close (out);
}
