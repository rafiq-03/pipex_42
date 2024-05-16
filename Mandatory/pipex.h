/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/16 17:21:16 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*__inlcudes__________________*/

# include "../Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/*__structs___________________*/

typedef struct s_list
{
	char			**command;// command extracted frome av[i]
	char			*c_name;
	int				in_fd;// input fd
	int				out_fd;// output fd
	int				flag;// command found or not (1=found)  (0=not found)
	int				index;
	struct s_list	*next;// next node of list
}			t_list;

typedef struct s_pipex
{
	t_list		*command;// store the command in a node
	char		**path;// when I want to store path var
	int			path_falg;// check in path is valid or not
	int			**pfd;// store pipes of commands
	int			infile_fd;// file discriptor of inputfile
	int			outfile_fd;// file discriptor of outputfile
	char		*tmp1;// for saving tmp values
	char		*tmp2;//same
	int			i;// this variables for iteration
	int			j;//same
	int			pnb;// number of pipes
	int			pid;
	int			exit_flag;
}			t_pipex;

/*__Macros____________________*/

/*__prototypes________________*/

void		check_command_line(int ac, char **av, char **envp);
void		init_struct(t_pipex *pipex, int ac, char **av);
void		search_paths(t_pipex *pipex, char **envp);
// void		init_commands(int ac, char **av, t_pipex *pipex);
// void		first_command(t_pipex *pipex, char *av_2);
void		init_commands(t_pipex *pipex, char **av, int ac);
void		fill_fd(t_pipex *pipex);

char		**ft_split_command(const char *s, char c);
int			is_quote(char c);
void		count_in_quote(const char *s, int *count, int *i);
int			quote_number(const char *s);
void		child(char **envp, t_pipex *pipex, t_list *cmd);
void		cmd_n_found(char *cmd);

void		clear_all(t_pipex *pipex);
void		clear_pipes(t_pipex *pipex);
void		close_all_pipes(int **pfd, int pnb);
void		ft_free(char **s);

/*linked lists____________________________*/

t_list		*ft_lstnew(void);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(char **, char *));
void		del(char **command, char *name); // delete function
void		ft_lstclear(t_list **lst, void (*del)(char **, char *));
void		ft_lstadd_back(t_list **lst, t_list *new);

/*_______________________________________*/

void		print(char **str);
void		print_list(t_pipex *pipe);
#endif
