/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/09 17:57:43 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX
# define PIPEX

/*__inlcudes__________________*/
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../Libft/libft.h"

/*__structs___________________*/

typedef struct s_pipex
{
	char **path;
	char **command;
	int pfd[2];
	int in_fd;
	int	out_fd;
	
	
}	t_pipex;


/*__Macros____________________*/




/*__prototypes________________*/

void    check_command_line(int ac, char **av, char **envp);
char	**search_paths(char **envp);
void	child_1(char **av, char **envp, t_pipex *pipex);
void	child_2(char **av, char **envp, t_pipex *pipex);

void	ft_free(char **s);


void	print(char **str); //just for testing
#endif

