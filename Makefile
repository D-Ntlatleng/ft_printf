# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 11:30:07 by dntlatle          #+#    #+#              #
#    Updated: 2018/08/28 13:06:19 by dntlatle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra -I.

CC = gcc

SRCS = ft_strchr.c \
	   hex.c \
	   octal.c \
	   hex_check.c \
	   dec_check.c \
	   octal_check.c\
	   str_check.c\
	   pointer.c\
	   char_check.c\
	   move.c\
	   precision.c\
			percent.c\
			width.c\
			ft_putnbr.c\
			ft_length.c\
			ft_flags.c\
			char_con.c\
			decimal.c\
			charector.c\
			pristr.c\
			ft_putchar.c\
			ft_base.c\
			ft_putstr.c\
			ft_wstrlen.c\
			ft_strlen.c\
			fsize.c\
			ft_printf.c\
			ft_atoi.c\
			ft_bzero.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_islower.c\
			ft_isspace.c\
			ft_isupper.c\
			ft_strrev.c\
			ft_putcstr.c\
			ft_putwstr.c

OBJ = 	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRCS)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

.PHONY : clean fclean re all

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
re: fclean all
