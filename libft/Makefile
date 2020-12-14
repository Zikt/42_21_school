# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgurn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 12:23:18 by pgurn             #+#    #+#              #
#    Updated: 2020/11/24 20:58:18 by pgurn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PART1 = ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strnstr.c	\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_calloc.c		\
			ft_strdup.c
SRC_PART2 = ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c
SRC_BONUS = ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c
                        
NAME = libft.a
HEADER = libft.h
FLAG = -Wall -Wextra -Werror
SRC = $(SRC_PART1) $(SRC_PART2)
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc $(FLAG) -c $< -o ${<:.c=.o} -I.

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS) $(HEADER)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus