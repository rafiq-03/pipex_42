/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:45:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/16 20:08:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_all(t_pipex *pipex)
{
	// ft_lstclear(&pipex->command, del);  // we clear this list
	ft_free(pipex->path);
	clear_pipes(pipex);
	if (pipex->exit_flag == pipex->pnb + 1)
		exit(1);
	exit(0);
}

void	clear_pipes(t_pipex *pipex)
{
	pipex->i = 0;
	while (pipex->i < pipex->pnb)
	{
		free(pipex->pfd[pipex->i]);
		pipex->i++;
	}
	free(pipex->pfd);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	s = NULL;
}

void	close_all_pipes(int **pfd, int pnb)
{
	int	i;

	i = 0;
	while (i < pnb)
	{
		close(pfd[i][0]);
		close(pfd[i][1]);
		i++;
	}
}
