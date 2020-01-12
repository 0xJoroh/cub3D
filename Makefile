# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 18:47:15 by mait-si-          #+#    #+#              #
#    Updated: 2020/01/12 09:05:41 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		cub3D.a

SRCS		=		*.c */*.c

OBJS		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
