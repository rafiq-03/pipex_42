/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:45:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/14 13:11:12 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_all(t_pipex *pipex)
{
	// ft_lstclear(&pipex->command, del);  // we clear this list
	// check it later
	ft_free(pipex->path); // we free the path
	clear_pipes(pipex);
	// close (pipex->infile_fd);
	// close (pipex->outfile_fd);
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
