/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 22:47:09 by rmarzouk         ###   ########.fr       */
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
	
	atexit(ll);
	check_command_line(ac, av, envp);// check the number of argumments
	search_paths(&pipex, envp); // fill the paths of commands
	init_commands(ac,av, &pipex);// fill list of commands depends on how may args in pipex program
	
	t_list *tmp;
	tmp = pipex.command;

	print(pipex.path);
	while (tmp)
	{
		printf("-----------------\n");
		print(tmp->command);
		printf("------------|-----\n");
		printf("flag : %d\n", tmp->flag);
		printf("in   : %d\n", tmp->in_fd);
		printf("out  : %d\n", tmp->out_fd);
		printf("-----------------\n");
		tmp = tmp->next;
	}










	clear_all(&pipex);
	
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
