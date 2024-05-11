# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/05/11 22:47:59 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
# BNAME= pipex_bonus


### FLAGS

CC=gcc
CFLAGS= -Wall -Wextra -Werror

### LIBFT

LIBFT = libft.a
LIBFT_DIR = libft

### UTILS

UTILS_DIR = Mandatory/
UTILS_S = $(addprefix $(UTILS_DIR), utils.c \
									init_command.c\
									ft_close.c \
									)

UTILS_O = $(UTILS_S:.c=.o)

LUTILS_DIR = utils/
LUTILS_S = $(addprefix $(LUTILS_DIR),	ft_lstadd_back.c\
										ft_lstclear.c    \
										ft_lstdelone.c   \
										ft_lstlast.c     \
										ft_lstnew.c     \
										ft_lstsize.c\
									)

LUTILS_O = $(LUTILS_S:.c=.o)

# B_UTILS_DIR = Bonus/
# B_UTILS_S = $(addprefix $(B_UTILS_DIR), pipex_bonus)

# B_UTILS_O = $(B_UTILS_S:.c=.o)

#_________________________________________________________

all: $(NAME)

$(NAME):mandatory/$(NAME).c $(LIBFT) $(UTILS_O) $(LUTILS_O)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(UTILS_O) $(LUTILS_O) mandatory/$(NAME).c -o $(NAME)


# bonus:$(BNAME)
# $(BNAME):Bonus/$(BNAME).c $(LIBFT) $(B_UTILS_O)
# 	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(B_UTILS_O) Bonus/$(BNAME).c -o $(BNAME)	
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
	@echo "DONE .."
	

fclean: clean
	@rm $(NAME)
	@rm $(BNAME)
re: fclean all

.PHONY: clean fclean re all
