# **************************************************************************** #
#
                                                                            #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 09:26:09 by mait-si-          #+#    #+#              #
#    Updated: 2019/10/22 16:45:06 by mait-si-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

SRCS		=		ft_atoi.c 				\
					ft_isascii.c 			\
					ft_memcmp.c 			\
					ft_strdup.c 			\
					ft_strnstr.c 			\
					ft_bzero.c 				\
					ft_isdigit.c 			\
					ft_memcpy.c 			\
					ft_strlcat.c 			\
					ft_strrchr.c 			\
					ft_calloc.c 			\
					ft_isprint.c 			\
					ft_memmove.c 			\
					ft_strlcpy.c 			\
					ft_tolower.c 			\
					ft_isalnum.c 			\
					ft_memccpy.c 			\
					ft_memset.c 			\
					ft_strlen.c 			\
					ft_toupper.c 			\
					ft_isalpha.c 			\
					ft_memchr.c 			\
					ft_strchr.c 			\
					ft_strncmp.c 			\
					ft_strcat.c 			\
					ft_strcmp.c 			\
					ft_strcpy.c 			\
					ft_strncpy.c 			\
					ft_strncat.c 			\
					ft_strstr.c 			\
					ft_substr.c 			\
					ft_strjoin.c 			\
					ft_isspace.c 			\
					ft_strtrim.c 			\
					ft_split.c 				\
					ft_putendl.c 			\
					ft_putchar.c 			\
					ft_strrev.c 			\
					ft_print_words_tables.c \
					ft_putstr.c 			\
					ft_putnbr.c 			\
					ft_putchar_fd.c 		\
					ft_putstr_fd.c 			\
					ft_putendl_fd.c 		\
					ft_putnbr_fd.c 			\
					ft_itoa.c 				\
					ft_strmapi.c

BSRCS		=		ft_lstnew_bonus.c 		\
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c 		\
					ft_lstlast_bonus.c 		\
					ft_lstadd_back_bonus.c 	\
					ft_lstdelone_bonus.c 	\
					ft_lstclear_bonus.c 	\
					ft_lstiter_bonus.c 		\
					ft_lstmap_bonus.c

BOBJS		=		$(BSRCS:.c=.o)

OBJS		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: 
	gcc -Wall -Wextra -Werror -c $(BSRCS)
	ar -rs $(NAME) $(BOBJS)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all