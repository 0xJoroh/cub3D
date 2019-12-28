# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 18:47:15 by mait-si-          #+#    #+#              #
#    Updated: 2019/12/27 18:41:50 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		cub3D.a

LIBFT		=		libft/libft.a

SRCS		=		*.c

OBJS		=		$(SRCS:.c=.o)

LINK		=		-I /usr/local/include $(NAME) -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit -fsanitize=address

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJS) $(LIBFT)
	ranlib $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
