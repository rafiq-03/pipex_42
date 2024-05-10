/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/09 18:23:11 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **av, char **envp, t_pipex *pipex)
{
	char	*tmp;
	int		i;
	
	if ((pipex->in_fd = open(av[1], O_RDONLY)) == -1)
		perror("Error");
	dup2(pipex->in_fd, 0);
	close (pipex->in_fd);
	dup2(pipex->pfd[1], 1);
	close (pipex->pfd[1]);
	pipex->command = ft_split(av[2], ' '); // all command  with all its options
	tmp = pipex->command[0];
	pipex->command[0] = ft_strjoin("/", pipex->command[0]);
	free(tmp);
	i = 0;
	tmp = pipex->command[0];
	while (pipex->path[i])
	{
		pipex->command[0] = ft_strjoin(pipex->path[i], tmp);
		if (access(pipex->command[0], F_OK | X_OK) == 0)
		{
			// exit(1);
			execve(pipex->command[0], pipex->command, envp);
		}
		free(pipex->command[0]);
		i++;	
	}
	ft_putendl_fd("Command not found", 2);
	exit(EXIT_FAILURE);
}


