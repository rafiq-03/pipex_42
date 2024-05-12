/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/12 20:00:25 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ll()
{
	system("leaks pipex");
}

int main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int p_id;
	
	// atexit(ll);
	check_command_line(ac, av, envp);// check the number of argumments
	init_struct(&pipex,ac, av);// init_struct with initial values
	search_paths(&pipex, envp); // fill the paths of commands
	init_commands(ac,av, &pipex);// fill list of commands depends on how may args in pipex program
	fill_fd(&pipex); // fill the list with fd of pipes
	printf("here\n");
	print_list(&pipex); // print list
	p_id = fork();
	if (p_id == 0)
	{
		printf("child\n");
		child(envp, pipex.command);
	}
	else
	{
		wait(NULL);
		printf("this is parent\n");
		p_id = fork();
		if (p_id == 0)
		{
			printf("child 2\n");
			child(envp, pipex.command->next);
			printf("done\n");
		}
		wait(NULL);
		// else
		// {
		// 	wait(NULL)
		// }	
	}
	

	clear_all(&pipex);

	
}


void	print_list(t_pipex *pipe)
{
	t_list *tmp;
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
	int i = 0;
	while (str[i])
	{
		printf("[%d] : %s\n",i , str[i]);
		i++;
	}
	if (str[i] == NULL)
		printf("[%d] : NULL\n", i);
}
