/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:20:16 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 22:51:14 by rmarzouk         ###   ########.fr       */
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
	int		i;

	i = 0;
	first = ft_lstnew();
	first->command = ft_split(av_2, ' '); // I want to make a split function for this shit 		
	tmp = first->command[0];
	first->command[0] = ft_strjoin("/", tmp);
	free(tmp);
	tmp = first->command[0];
	printf("%s\n", tmp + 1);
	while (pipex->path[i])
	{
		first->command[0] = ft_strjoin(pipex->path[i], tmp);
		if (access(first->command[0], F_OK | X_OK) == 0)
		{
			first->flag = 1; // command found
			pipex->command = first;
			free(tmp);
			return;
		}
		free(first->command[0]);
		// ft_free(first->command);
		i++;
	}
}
void	other_commands(t_pipex *pipex, char **av, int ac)
{
	t_list	*node;
	char	*tmp;
	int		a;
	int		i;

	a = 2; // iteration in arguments
	while (++a < ac - 1)
	{
		i = 0; // iteration in path
		node = ft_lstnew();
		node->command = ft_split(av[a], ' '); // I want to make a split function for this shit 		
		tmp = node->command[0];
		node->command[0] = ft_strjoin("/", tmp);
		free(tmp);
		tmp = node->command[0];
		printf("%s\n", tmp + 1);
		while (pipex->path[i])
		{
			node->command[0] = ft_strjoin(pipex->path[i], tmp);
			if (access(node->command[0], F_OK | X_OK) == 0)
			{
				node->flag = 1;// command found
				ft_lstadd_back(&pipex->command, node);
				free(tmp);
				return;
			}
			free(node->command[0]);
			i++;
		}
		// ft_free(node->command);
	}
}
