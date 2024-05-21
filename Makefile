# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/05/19 12:11:16 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
BNAME= pipex_bonus


### FLAGS

CC=gcc
CFLAGS= -Wall -Wextra -Werror

#-fsanitize=address
### LIBFT

LIBFT = libft.a
LIBFT_DIR = utils/Libft

### UTILS

UTILS_DIR = Mandatory/
UTILS_S = $(addprefix $(UTILS_DIR), utils.c \
									init_struct.c\
									init_command.c\
									ft_close.c \
									ft_child.c \
									ft_split_command.c\
									handel_quote.c\
									)

UTILS_O = $(UTILS_S:.c=.o)

LUTILS_DIR = utils/lists/
LUTILS_S = $(addprefix $(LUTILS_DIR),	ft_lstadd_back.c\
										ft_lstclear.c    \
										ft_lstdelone.c   \
										ft_lstlast.c     \
										ft_lstnew.c     \
										ft_lstsize.c\
									)

LUTILS_O = $(LUTILS_S:.c=.o)

GNLUTILS_DIR = utils/gnl/
GNLUTILS_S = $(addprefix $(GNLUTILS_DIR),	get_next_line.c\
										get_next_line_utils.c\
									)

GNLUTILS_O = $(GNLUTILS_S:.c=.o)

B_UTILS_DIR = Bonus/
B_UTILS_S = $(addprefix $(B_UTILS_DIR),	utils_bonus.c \
										init_struct_bonus.c \
										init_command_bonus.c \
										ft_close_bonus.c \
										ft_child_bonus.c \
										ft_split_command_bonus.c \
										handel_quote_bonus.c \
										here_doc_bonus.c \
										)

B_UTILS_O = $(B_UTILS_S:.c=.o)

#_________________________________________________________

all: $(NAME)

$(NAME):Mandatory/$(NAME).c $(LIBFT) $(UTILS_O) $(LUTILS_O)
	@$(CC) $(CFLAGS) $(UTILS_O) $(LUTILS_O) Mandatory/$(NAME).c -L$(LIBFT_DIR) -lft -o $(NAME)


bonus:$(BNAME)

$(BNAME):Bonus/$(BNAME).c $(LIBFT) $(B_UTILS_O) $(LUTILS_O) $(GNLUTILS_O)
	@$(CC) $(CFLAGS) $(B_UTILS_O) $(LUTILS_O) $(GNLUTILS_O) Bonus/$(BNAME).c -L$(LIBFT_DIR) -lft -o $(BNAME)	
	
#_________________________________________________________

$(LIBFT):
	@echo "Libft.."
	@make -C $(LIBFT_DIR)

%.o:%.c pipex.h
	@${CC} ${CFLAGS} -c $< -o $@

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
