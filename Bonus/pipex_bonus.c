/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/28 15:02:51 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	t_list	*cmd;

	init_list(&pipex, ac, av, envp);
	cmd = pipex.command;
	while (cmd)
	{
		pipex.pid = fork();
		if (pipex.pid == -1)
		{
			pipex.exit_flag = 1;
			clear_all(&pipex);
		}
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
	close(in);
	close(out);
}

void	init_list(t_pipex *pipex, int ac, char **av, char **envp)
{
	check_command_line(ac, av, pipex);
	init_struct(pipex, ac, av);
	search_paths(pipex, envp);
	init_commands(ac, av, pipex);
	fill_fd(pipex);
	hande_here_doc(pipex);
}
