/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:51:42 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/16 20:06:59 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex *pipex, int ac, char **av)
{
	pipex->i = 0;
	pipex->j = 0;
	pipex->exit_flag = 0;
	pipex->path_falg = 0;
	pipex->pnb = ac - 4;
	pipex->tmp1 = NULL;
	pipex->tmp2 = NULL;
	open_in_outfile(pipex, av[1], av[ac - 1]);
	pipex->pfd = malloc((ac - 4) * sizeof(int *));
	while (pipex->i < ac - 4)
	{
		pipex->pfd[pipex->i] = malloc(2 * sizeof(int));
		pipex->j = pipe(pipex->pfd[pipex->i]);
		if (pipex->j == -1)
			printf("fail to create a pipe\n");
		pipex->i++;
	}
	pipex->i = 0;
	pipex->j = 0;
}

void	open_in_outfile(t_pipex *pipex, char *in, char *out)
{
	pipex->infile_fd = open(in, O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(in, 2);
		if (access(in, F_OK) == -1)
			ft_putendl_fd(": No such file or  directory", 2);
		else if (access(in, R_OK))
			ft_putendl_fd(": permission denied", 2);
	}
	pipex->outfile_fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
