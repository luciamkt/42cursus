# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 11:40:36 by ltakahas          #+#    #+#              #
#    Updated: 2020/02/02 17:14:23 by ltakahas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
ft_lstsize.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(HEADER) $(SRCS)

$(OBJS_BONUS): $(SRCS_BONUS)
	$(CC) $(FLAGS) -c $(HEADER) $(SRCS_BONUS)

bonus: all $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	/bin/rm -f $(OBJS) $(OBJS_BONUS)
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re bonus