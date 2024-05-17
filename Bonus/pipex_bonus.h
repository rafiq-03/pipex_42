/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/17 22:55:31 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*__inlcudes__________________*/

# include "../utils/Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/*__structs___________________*/

typedef struct s_list
{
	char			**command;
	char			*c_name;
	int				in_fd;
	int				out_fd;
	int				flag;
	int				index;
	struct s_list	*next;
}			t_list;

typedef struct s_pipex
{
	t_list		*command;
	char		**path;
	int			path_falg;
	int			**pfd;
	int			infile_fd;
	int			outfile_fd;
	char		*tmp1;
	char		*tmp2;
	int			i;
	int			j;
	int			pnb;
	int			pid;
	int			exit_flag;
}			t_pipex;

/*__prototypes________________*/

void		check_command_line(int ac, char **av, char **envp);
void		init_struct(t_pipex *pipex, int ac, char **av);
void		open_in_outfile(t_pipex *pipex, char *in, char *out);

void		search_paths(t_pipex *pipex, char **envp);
void		first_command(t_pipex *pipex, char *av_2);
void		init_commands(int ac, char **av, t_pipex *pipex);
void		first_command(t_pipex *pipex, char *av_2);
void		other_commands(t_pipex *pipex, char **av, int ac);

void		join_with_path(t_pipex *pipex, t_list *node);
void		fill_fd(t_pipex *pipex);

char		**ft_split_command(const char *s, char c);
size_t		word_len(const char *s, char c);
int			is_quote(char c);
char		*between_q(const char *s, int *i, char c);
void		skip_sapces(const char *s, int *i, char c);
void		count_in_quote(const char *s, int *count, int *i);
int			quote_number(const char *s);
void		child(char **envp, t_pipex *pipex, t_list *cmd);
void		cmd_n_found(char *cmd);

void		_close_in_out(int in, int out);
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
