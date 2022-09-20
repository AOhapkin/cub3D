# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: gmyriah <marvin@42.fr>                     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/19 12:37:11 by gmyriah           #+#    #+#             #
#   Updated: 202#   Updated: 2021/10/19 13:02:20 by gmyriah          ###   ########.fr       #                                              #
# ************************************************************************** #

NAME = libft.a

# dirs
DIR_S = sources
DIR_O = objects

INCLUDES = ./includes

C_FILES		= ft_isalpha.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isnegative.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_memalloc.c \
		ft_newstr.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

HEADER = $(INCLUDES)/libft.h
SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))\

.PHONY: all clean fclean re reclean force

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O):
	echo $(DIR_O)
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	gcc -Wall -Wextra -Werror -g -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all