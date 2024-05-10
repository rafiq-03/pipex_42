# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/05/09 17:58:58 by rmarzouk         ###   ########.fr        #
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
									ft_child_1.c\
									ft_child_2.c\
									)

UTILS_O = $(UTILS_S:.c=.o)

# B_UTILS_DIR = Bonus/
# B_UTILS_S = $(addprefix $(B_UTILS_DIR), pipex_bonus)

# B_UTILS_O = $(B_UTILS_S:.c=.o)

#_________________________________________________________

all: $(NAME)

$(NAME):mandatory/$(NAME).c $(LIBFT) $(UTILS_O)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(UTILS_O) mandatory/$(NAME).c -o $(NAME)


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
