# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/05/25 15:49:55 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
BNAME= pipex_bonus


### FLAGS

CC=gcc
CFLAGS= -Wall -Wextra -Werror

### LIBFT

LIBFT = libft.a
LIBFT_DIR = Utils/Libft

### UTILS

UTILS_DIR = Mandatory/
UTILS_S = $(addprefix $(UTILS_DIR), pipex.c \
									utils.c \
									init_struct.c\
									init_command.c\
									ft_close.c \
									ft_child.c \
									ft_split_command.c\
									ft_split_utils.c\
									)

UTILS_O = $(UTILS_S:.c=.o)

LUTILS_DIR = Utils/lists/
LUTILS_S = $(addprefix $(LUTILS_DIR),	ft_lstadd_back.c\
										ft_lstclear.c    \
										ft_lstdelone.c   \
										ft_lstlast.c     \
										ft_lstnew.c     \
										ft_lstsize.c\
									)

LUTILS_O = $(LUTILS_S:.c=.o)

GNLUTILS_DIR = Utils/gnl/
GNLUTILS_S = $(addprefix $(GNLUTILS_DIR),	get_next_line.c\
											get_next_line_utils.c\
									)

GNLUTILS_O = $(GNLUTILS_S:.c=.o)

B_UTILS_DIR = Bonus/
B_UTILS_S = $(addprefix $(B_UTILS_DIR),	pipex_bonus.c\
										utils_bonus.c \
										init_struct_bonus.c \
										init_command_bonus.c \
										ft_close_bonus.c \
										ft_child_bonus.c \
										ft_split_command_bonus.c \
										ft_split_utils_bonus.c \
										here_doc_bonus.c \
										)

B_UTILS_O = $(B_UTILS_S:.c=.o)

#_________________________________________________________

all:$(NAME)

$(NAME):Mandatory/pipex.h $(UTILS_O) $(LUTILS_O)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(UTILS_O) $(LUTILS_O) -L$(LIBFT_DIR) -lft -o $(NAME)


bonus:$(BNAME)

$(BNAME):Bonus/pipex_bonus.h $(B_UTILS_O) $(LUTILS_O) $(GNLUTILS_O)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(B_UTILS_O) $(LUTILS_O) $(GNLUTILS_O) -L$(LIBFT_DIR) -lft -o $(BNAME)

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(RED)Cleanin object files ...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(UTILS_O)
	@rm -f $(B_UTILS_O)
	@rm -f $(LUTILS_O)
	@rm -f $(GNLUTILS_O)
	@echo "DONE .."
	

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNAME)
re: fclean all

.PHONY: clean fclean re all
