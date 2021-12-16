# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 14:12:00 by mmeredit          #+#    #+#              #
#    Updated: 2021/11/21 19:17:02 by mmeredit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_printf_with_hex.c ft_printf_with_put.c

OBJS			= $(SRCS:.c=.o)

NAME			= libftprintf.a

HEADER			= ft_printf.h

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			ar rcs $(NAME) $?

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I.$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:			all clean fclean re bonus
