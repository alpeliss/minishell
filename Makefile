# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 13:11:31 by ancoulon          #+#    #+#              #
#    Updated: 2021/03/02 11:09:19 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

LIBDIR		= libcarbon
LIBNAME		= libcarbon.a
LIBMAKE		= make -C $(LIBDIR)

CC			= clang
\RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror \
				-I./include -I./$(LIBDIR)/include \

SRCS		= $(wildcard source/*.c) \
				$(wildcard source/*/*.c)
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIBMAKE) all
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBDIR)/$(LIBNAME)

clean:
			$(LIBMAKE) clean
			$(RM) $(OBJS)

fclean:		clean
			$(LIBMAKE) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
