/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/17 19:12:07 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ll(void)
{
	system("leaks pipex");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	t_list	*cmd;

	check_command_line(ac, av, envp);
	init_struct(&pipex, ac, av);
	search_paths(&pipex, envp);
	init_commands(ac, av, &pipex);
	fill_fd(&pipex);
	print_list(&pipex);
	cmd = pipex.command;
	while (cmd)
	{
		if (cmd->flag == 0)
			pipex.exit_flag++;
		pipex.pid = fork();
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

void	print_list(t_pipex *pipe)
{
	t_list	*tmp;

	tmp = pipe->command;
	while (tmp != NULL)
	{
		printf("----------------------------\n");
		printf("COMMAND:%s              \n", tmp->c_name);
		printf("index: %d                   \n", tmp->index);
		printf("--------------------\n");
		print(tmp->command);
		printf("--------------------\n");
		printf("flag : %d                   \n", tmp->flag);
		printf("in   : %d                   \n", tmp->in_fd);
		printf("out  : %d                   \n", tmp->out_fd);
		printf("---------------------------\n");
		printf("         | |      \n");
		tmp = tmp->next;
	}
}

void	print(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("[%d] : %s\n", i, str[i]);
		i++;
	}
	if (str[i] == NULL)
		printf("[%d] : NULL\n", i);
}
