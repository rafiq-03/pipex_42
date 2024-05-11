/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 22:16:29 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_command_line(int ac, char **av, char **envp)
{
	(void)av;
	(void)envp;
	if (ac != 5)
	{
		ft_putendl_fd("Invalid arguments", 2);
		exit(EXIT_FAILURE);
	}
}

void	search_paths(t_pipex *pipex, char **envp)
{
	int i;
	char *path;

	i = 0;
	while (envp[i])
	{
			if (ft_strnstr(envp[i], "PATH=", 5))
			{
					path = envp[i] + 5;
					break;
			}
			i++;
	}
	if (ft_strlen(path) == 0)
		printf("what the hell this path is ainvalid\n");
	pipex->path = ft_split(path, ':');
	if (!pipex->path)
	{
		printf("we have problem with search path\n");
		exit (1);
	}
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
}
