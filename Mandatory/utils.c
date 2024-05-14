/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/13 19:07:12 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command_line(int ac, char **av, char **envp)
{
	(void)av;
	(void)envp;
	if (ac < 5)
	{
		ft_putendl_fd("Invalid arguments", 2);
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
	// if (!path || ft_strlen(path) == 0)
	// 	pipex->path_falg = 0;
	pipex->path = ft_split(path, ':');
	if (!pipex->path)
	{
		printf("we have problem with search path\n");
	}
}

void	init_struct(t_pipex *pipex, int ac, char **av)
{
	pipex->i = 0;
	pipex->j = 0;
	pipex->path_falg = 0; // check in path is valid or not
	pipex->pnb = ac - 4;
	pipex->tmp1 = NULL;
	pipex->tmp2 = NULL;
	if (-1 == (pipex->infile_fd = open(av[1], O_RDONLY)))
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": No such file or  directory", 2);
	}
	pipex->pfd = malloc((ac - 4) * sizeof(int *));
	while (pipex->i < ac - 4)
	{
		pipex->pfd[pipex->i] = malloc(2 * sizeof(int));
		pipex->j = pipe(pipex->pfd[pipex->i]); // init pipes here after
		if (pipex->j == -1)
			printf("fail to create a pipe\n");
		printf("pipe[%d][> %d == %d <]\n", pipex->i, pipex->pfd[pipex->i][0],
				pipex->pfd[pipex->i][1]);
		pipex->i++;
	}
	if (-1 == (pipex->outfile_fd = open(av[ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0666)))
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(av[ac - 1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	printf("in_file:%d|out_file:%d\n", pipex->infile_fd, pipex->outfile_fd);
	pipex->i = 0;
	pipex->j = 0;
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
	ft_putendl_fd(": Command not found", 2);
}
