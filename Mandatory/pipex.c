/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/14 20:13:58 by rmarzouk         ###   ########.fr       */
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
	// t_list	*prev;   
	int		p_id;

	// atexit(ll);
	check_command_line(ac, av, envp); // check the number of argumments
	init_struct(&pipex, ac, av);      // init_struct with initial values
	search_paths(&pipex, envp);       // fill the paths of commands
	init_commands(ac, av, &pipex);
	// fill list of commands depends on how may args in pipex program
	fill_fd(&pipex); // fill the list with fd of pipes
	// printf("here\n");
	// print_list(&pipex); // print list
	// printf("__________________________\n");
	cmd = pipex.command;
	// int a = 2;
	// close(STDIN_FILENO);
	// close(STDOUT_FILENO);
	while (cmd)
	{
		p_id = fork();
		if (p_id == 0) // child
		{
			child(envp, &pipex, cmd);
		}
		else // parent
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
