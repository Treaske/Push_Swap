# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 18:33:50 by ade-blas          #+#    #+#              #
#    Updated: 2022/02/19 16:38:50 by ade-blas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra  -fsanitize=address -g3
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= push_swap

INCLUDE	= push_swap.h
SRCS	= push_swap.c ft_make_c.c ft_make_a.c ft_get_number.c ft_instructions.c \
			ft_instructions2.c ft_instructions3.c ft_algorithms_fivehun.c \
			ft_algorithms_hundred.c ft_algorithms_three.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus rebonus