/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/11 22:47:35 by rmarzouk         ###   ########.fr       */
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

typedef struct s_list
{
	char **command; // command extracted frome av[i]
	int in_fd; // input fd
	int out_fd; // output fd
	int	flag; // command found or not (1=found)  (0=not found)
	struct s_list	*next; // next node of list
}	t_list;

typedef struct s_pipex
{
	t_list	*command;// store the command in a node 
	char 	**path; // when I want to store path var
	int		**pfd; // store pipes of commands
}	t_pipex;


/*__Macros____________________*/




/*__prototypes________________*/

void    check_command_line(int ac, char **av, char **envp);
void	search_paths(t_pipex *pipex, char **envp);
void	init_commands(int ac, char **av, t_pipex *pipex);
void	first_command(t_pipex *pipex, char *av_2);
void	other_commands(t_pipex *pipex, char **av, int ac);




void	clear_all(t_pipex *pipex);
void	ft_free(char **s);
/*linked lists____________________________*/

t_list 		*ft_lstnew(void);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del) (char **));
void		del(char **command);// delete function
void		ft_lstclear(t_list **lst, void (*del)(char **));
void		ft_lstadd_back(t_list **lst, t_list *new);


/*_______________________________________*/

void	print(char **str); //just for testing
#endif

