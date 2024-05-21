/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:51:42 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/21 11:59:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_struct(t_pipex *pipex, int ac, char **av)
{
	pipex->i = 0;
	pipex->j = 0;
	pipex->exit_flag = 0;
	pipex->path_falg = 0;
	if (pipex->here_doc_flag)
		pipex->pnb = ac - 5;
	else
		pipex->pnb = ac - 4;
	pipex->tmp1 = NULL;
	pipex->tmp2 = NULL;
	open_in_outfile(pipex, av[1], av[ac - 1]);
	pipex->pfd = malloc(pipex->pnb * sizeof(int *));
	while (pipex->i < pipex->pnb)
	{
		pipex->pfd[pipex->i] = malloc(2 * sizeof(int));
		pipex->j = pipe(pipex->pfd[pipex->i]);
		if (pipex->j == -1)
		{
			ft_putendl_fd("fail to create a pipe", 2);
			close_pipes(pipex, pipex->i);
			exit(EXIT_FAILURE);
		}
		pipex->i++;
	}
	pipex->i = 0;
	pipex->j = 0;
}

void	open_in_outfile(t_pipex *pipex, char *in, char *out)
{
	if (pipex->here_doc_flag)
	{
		pipex->infile_fd = open("/tmp/here_doc", O_RDWR | O_CREAT, 0666);
		pipex->outfile_fd = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->infile_fd = open(in, O_RDONLY);
		pipex->outfile_fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	check_open(pipex, in, out);
}

void	check_open(t_pipex *pipex, char *in, char *out)
{
	if (pipex->infile_fd == -1)
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(in, 2);
		if (access(in, F_OK) == -1)
			ft_putendl_fd(": No such file or  directory", 2);
		else if (access(in, R_OK))
			ft_putendl_fd(": permission denied", 2);
	}
	if (pipex->outfile_fd == -1)
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(out, 2);
		if (access(out, W_OK) == -1)
			ft_putendl_fd(": permission denied", 2);
		else
			ft_putendl_fd(": No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
}

void	close_pipes(t_pipex *pipex, int i)
{
	int a;

	a = 0;
	while (a < i)
		free(pipex->pfd[a++]);
	free(pipex->pfd);
}
