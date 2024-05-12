/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:20:16 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/12 16:34:08 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_commands(int ac, char **av, t_pipex *pipex)
{
	first_command(pipex, av[2]);
	other_commands(pipex, av, ac);
}

void	first_command(t_pipex *pipex, char *av_2)
{
	t_list *first;
	char *tmp;

	pipex->i = -1;
	first = ft_lstnew();
	if (ft_strlen(av_2) == 0)
		return;
	first->command = ft_split(av_2, ' '); // I want to make a split function for this shit 		
	first->c_name = first->command[0];
	first->command[0] = ft_strjoin("/", first->c_name);
	tmp = first->command[0];
	while (pipex->path[++pipex->i])
	{
		first->command[0] = ft_strjoin(pipex->path[pipex->i], tmp);
		if (access(first->command[0], F_OK | X_OK) == 0)
		{
			first->flag = 1;
			break;
		}
		if (!first->flag && pipex->path[pipex->i + 1])
			free(first->command[0]);
	}
	pipex->command = first;
	free(tmp);
}
void	other_commands(t_pipex *pipex, char **av, int ac)
{
	t_list	*node;

	pipex->j = 2; // iteration in arguments
	while (++pipex->j < ac - 1)
	{
		pipex->i = -1; // iteration in path
		node = ft_lstnew();
		node->command = ft_split(av[pipex->j], ' '); // I want to make a split function for this shit 		
		node->c_name = node->command[0];
		node->command[0] = ft_strjoin("/", node->c_name);
		pipex->tmp1 = node->command[0];
		while (pipex->path[++pipex->i])
		{
			node->command[0] = ft_strjoin(pipex->path[pipex->i], pipex->tmp1);
			if (access(node->command[0], F_OK | X_OK) == 0)
			{
				node->flag = 1;
				break;
			}
			if (!node->flag && pipex->path[pipex->i + 1])
				free(node->command[0]);
		}
		ft_lstadd_back(&pipex->command, node);
		free(pipex->tmp1);
	}
}
