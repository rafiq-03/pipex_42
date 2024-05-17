/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/17 17:32:09 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command_line(int ac, char **av, char **envp)
{
	(void)av;
	(void)envp;
	if (ac < 5)
	{
		ft_putendl_fd("Invalid arguments", 1);
		exit(EXIT_FAILURE);
	}
}

void	search_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = envp[i] + 5;
			pipex->path_falg = 1;
			break ;
		}
		i++;
	}
	pipex->path = ft_split(path, ':');
}

void	fill_fd(t_pipex *pipex)
{
	t_list	*tmp;

	pipex->i = 0;
	tmp = pipex->command;
	tmp->in_fd = pipex->infile_fd;
	tmp->out_fd = pipex->pfd[pipex->i][1];
	tmp = tmp->next;
	while (tmp->next)
	{
		tmp->in_fd = pipex->pfd[pipex->i][0];
		tmp->out_fd = pipex->pfd[pipex->i + 1][1];
		tmp = tmp->next;
		pipex->i++;
	}
	tmp->in_fd = pipex->pfd[pipex->i][0];
	tmp->out_fd = pipex->outfile_fd;
}

void	cmd_n_found(char *cmd)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
}
