/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:20:16 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/18 16:21:59 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_commands(int ac, char **av, t_pipex *pipex)
{
	if (pipex->here_doc_flag)
	{
		first_command(pipex, av[3]);
		pipex->j = 3;
	}
	else
	{
		first_command(pipex, av[2]);
		pipex->j = 2;
	}
	other_commands(pipex, av, ac);
}

void	first_command(t_pipex *pipex, char *av_2)
{
	t_list	*first;

	pipex->i = -1;
	first = ft_lstnew();
	first->command = ft_split_command(av_2, ' ');
	if (!first->command || !first->command[0])
	{
		first->c_name = ft_strdup("");
		pipex->command = first;
		return ;
	}
	first->c_name = ft_strdup(first->command[0]);
	if (ft_strchr(first->c_name, '/') || ft_strchr(first->c_name, '.'))
	{
		if (access(first->c_name, F_OK | X_OK) == 0)
			first->flag = 1;
	}
	else if (pipex->path_falg)
		join_with_path(pipex, first);
	pipex->command = first;
}

void	other_commands(t_pipex *pipex, char **av, int ac)
{
	t_list	*node;

	while (++pipex->j < ac - 1)
	{
		node = ft_lstnew();
		node->command = ft_split_command(av[pipex->j], ' ');
		if (!node->command || !node->command[0])
		{
			node->c_name = ft_strdup("");
			ft_lstadd_back(&pipex->command, node);
			return ;
		}
		node->c_name = ft_strdup(node->command[0]);
		if (ft_strchr(node->c_name, '/') || ft_strchr(node->c_name, '.'))
		{
			if (access(node->c_name, F_OK | X_OK) == 0)
				node->flag = 1;
		}
		else if (pipex->path)
			join_with_path(pipex, node);
		node->index = pipex->j - 2;
		ft_lstadd_back(&pipex->command, node);
	}
}

void	join_with_path(t_pipex *pipex, t_list *node)
{
	pipex->i = -1;
	free(node->command[0]);
	node->command[0] = ft_strjoin("/", node->c_name);
	pipex->tmp1 = node->command[0];
	while (pipex->path[++pipex->i])
	{
		node->command[0] = ft_strjoin(pipex->path[pipex->i], pipex->tmp1);
		if (access(node->command[0], F_OK | X_OK) == 0)
		{
			node->flag = 1;
			break ;
		}
		if (!node->flag && pipex->path[pipex->i + 1])
			free(node->command[0]);
	}
	free(pipex->tmp1);
}
