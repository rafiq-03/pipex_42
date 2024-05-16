/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/16 17:48:38 by rmarzouk         ###   ########.fr       */
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

	// atexit(ll);
	check_command_line(ac, av, envp); // check the number of argumments
	init_struct(&pipex, ac, av);      // init_struct with initial values
	search_paths(&pipex, envp);       // fill the paths of commands
	init_commands(&pipex, av, ac);
	fill_fd(&pipex); // fill the list with fd of pipes
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
		{
			close(cmd->out_fd);
			close(cmd->in_fd);
		}
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
	clear_all(&pipex);
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
