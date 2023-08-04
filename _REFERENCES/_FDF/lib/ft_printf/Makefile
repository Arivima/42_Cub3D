# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:57:33 by avilla-m          #+#    #+#              #
#    Updated: 2021/04/22 19:29:11 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		$(wildcard *.c) $(wildcard libft/*.c) $(wildcard utils/*.c)
OBJS =		$(SRCS:.c=.o)

BSRCS =		$(wildcard bonus/*.c)
BOBJS =		$(BSRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -I.

%.o:		%.c
	gcc -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(BOBJS)
			ar rcs $(NAME) $(OBJS) $(BOBJS)

all:		$(NAME)

bonus:		$(NAME)

clean:
			rm -f $(OBJS) $(BOBJS) *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
