# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 18:33:50 by ade-blas          #+#    #+#              #
#    Updated: 2022/01/18 18:02:56 by ade-blas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= push_swap.a

INCLUDE	= push_swap.h
SRCS	= push_swap.c ft_instructions.c ft_algorithms.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)
			$(CC) $(CFLAGS) $(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus rebonus