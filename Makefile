# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 18:47:15 by mait-si-          #+#    #+#              #
#    Updated: 2020/02/09 14:58:03 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		Cub3D

SRCS		=		*.c */*.c

OBJS		=		*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	gcc $(OBJS) -lmlx -framework OpenGL -framework AppKit -fsanitize=address -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
