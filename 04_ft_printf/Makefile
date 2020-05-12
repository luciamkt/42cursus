# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 16:46:50 by ltakahas          #+#    #+#              #
#    Updated: 2020/05/09 21:48:34 by ltakahas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

CC =	gcc

SRCS =	ft_printf.c \
		srcs/ft_flags.c \
		srcs/ft_helpers_diux.c \
		srcs/ft_helpers_p.c \
		srcs/ft_print_c.c \
		srcs/ft_print_di.c \
		srcs/ft_print_p.c \
		srcs/ft_print_percent.c \
		srcs/ft_print_s.c \
		srcs/ft_print_u.c \
		srcs/ft_print_x.c \
		utils/ft_count_digit.c \
		utils/ft_isdigit.c \
		utils/ft_putchar.c \
		utils/ft_putnbr_p.c \
		utils/ft_putnbr.c \
		utils/ft_putstr.c \
		utils/ft_strchr.c \
		utils/ft_strlen.c

OBJS =	ft_printf.o \
		ft_flags.o \
		ft_helpers_diux.o \
		ft_helpers_p.o \
		ft_print_c.o \
		ft_print_di.o \
		ft_print_p.o \
		ft_print_percent.o \
		ft_print_s.o \
		ft_print_u.o \
		ft_print_x.o \
		ft_count_digit.o \
		ft_isdigit.o \
		ft_putchar.o \
		ft_putnbr_p.o \
		ft_putnbr.o \
		ft_putstr.o \
		ft_strchr.o \
		ft_strlen.o

FLAGS =	-Wall -Wextra -Werror

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(HEADER) $(SRCS)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re