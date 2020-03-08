# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 18:47:15 by mait-si-          #+#    #+#              #
#    Updated: 2020/03/08 22:28:59 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		Cub3D

SRCS		=		*/*.c */*/*.c

OBJS		=		*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	gcc $(OBJS) -g3 -fsanitize=address -lmlx -framework OpenGL -framework AppKit -Ofast -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
