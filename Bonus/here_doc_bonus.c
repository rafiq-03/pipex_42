/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:44:01 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/19 14:56:54 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_doc_fd(t_pipex *pipex, char *here_doc)
{
	if (pipex->infile_fd == -1)
	{
		ft_putstr_fd("bash : ", 2);
		ft_putstr_fd(here_doc, 2);
		if (access(here_doc, F_OK) == -1)
			ft_putendl_fd(": No such file or  directory", 2);
		else if (access(here_doc, R_OK))
			ft_putendl_fd(": permission denied", 2);
	}
}

void	hande_here_doc(t_pipex *pipex)
{
	char	*line;

	if (!pipex->here_doc_flag)
		return ;
	ft_putstr_fd("> ", 1);
	line = get_next_line(0);
	while (1)
	{
		if (!ft_strncmp(pipex->lim, line, ft_strlen(line)))
			break ;
		write(pipex->infile_fd, line, ft_strlen(line));
		free(line);
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
	}
	free(pipex->lim);
	free(line);
	close(pipex->infile_fd);
	pipex->infile_fd = open("/tmp/here_doc", O_RDWR | O_CREAT, 0666);
	check_here_doc_fd(pipex, "/tmp/here_doc");
}
