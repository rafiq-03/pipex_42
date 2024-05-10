/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/09 17:42:33 by rmarzouk         ###   ########.fr       */
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

char **search_paths(char **envp)
{
	int i;
	char *path;
	char **r_path;

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
	r_path = ft_split(path, ':');
	return (r_path);
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
