# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 22:44:53 by rkhelif           #+#    #+#              #
#    Updated: 2020/05/15 20:03:44 by rkhelif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c


SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)
FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME) : $(OBJ)
	ar rc libft.a $(OBJ)
	ranlib libft.a

.c.o:
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

#$(OBJ): $(SRC)
#	$(CC) -o $@  -c $<


bonus: $(BONUS)
	ar rc libft.a $(BONUS)
	ranlib libft.a

so: 
	$(CC)  -shared -o libft.so $(OBJ) $(BONUS)

clean: 
	rm -rf *.o

fclean: clean
	rm -rf libft.a
	rm -rf libft.so

re: fclean all

