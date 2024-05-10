/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/09 18:38:34 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ll()
{

	printf("\n\n\n\n");
	system("leaks pipex");
}

int main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	
	atexit(ll);
	check_command_line(ac, av, envp);
	pipex.path = search_paths(envp);// fill the paths of commands
	if (pipe(pipex.pfd) == -1)
	{
		perror("Error");
		exit(1);
	}
	if (fork() == 0)
		child_1(av, envp, &pipex);
	else
	{
		sleep(2);
		// wait(NULL);
		printf("this is a parent\n");
		if (fork() == 0)
			child_2(av, envp, &pipex);
	}
	
	
	
}

void	print(char **str)
{
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	if (str[i] == NULL)
		printf("NULL------------------------------------------\n");
}
