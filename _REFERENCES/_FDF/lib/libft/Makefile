# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 16:42:30 by avilla-m          #+#    #+#              #
#    Updated: 2021/03/01 12:00:47 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
SRCS = 		$(wildcard *.c)
OBJS = 		$(SRCS:.c=.o)
RM = 		rm -f
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror

%.o:		%.c 		
			$(CC) -c $(CFLAGS) $< 

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
