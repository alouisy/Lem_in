# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 14:12:24 by alouisy-          #+#    #+#              #
#    Updated: 2017/03/20 14:12:26 by alouisy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = main.c\
ft_parse.c\
ft_list.c\
ft_presolve.c\
ft_solution.c\
ft_bonus.c\
gfx1.c\
gfx2.c

OBJS = $(SRCS:.c=.o)

LIBS = -L minilibx_macos/ -lmlx -L libft/ -lft -lm

INCLUDES = -I. -I libft/includes/. -I minilibx_macos/.

FRAMEWORKS = -framework OpenGL -framework AppKit

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(CFLAGS) -c $(SRCS) $(INCLUDES)
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) $(FRAMEWORKS)
	@echo "\"lem-in\" has been succefully created !"

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@/bin/rm -f $(OBJS)
	@echo "LEM-IN Object files deleted."

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean
	@/bin/rm -f $(NAME)
	@echo "LEM-IN Executable deleted."

re: fclean all

.PHONY: clean
