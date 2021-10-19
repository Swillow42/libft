# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swillow <swillow@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 12:57:55 by swillow           #+#    #+#              #
#    Updated: 2021/05/15 13:13:36 by swillow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_atoi.c 			\
			ft_bzero.c 			\
			ft_calloc.c 		\
			ft_isalnum.c 		\
			ft_isalpha.c 		\
			ft_isascii.c 		\
			ft_isdigit.c 		\
			ft_isprint.c 		\
			ft_memccpy.c 		\
			ft_memchr.c 		\
			ft_memcmp.c 		\
			ft_memcpy.c 		\
			ft_memmove.c 		\
			ft_memset.c 		\
			ft_strchr.c 		\
			ft_strdup.c 		\
			ft_strlcat.c 		\
			ft_strlcpy.c 		\
			ft_strlen.c 		\
			ft_strncmp.c 		\
			ft_strnstr.c 		\
			ft_strrchr.c 		\
			ft_tolower.c 		\
			ft_toupper.c 		\
			ft_substr.c 		\
			ft_strjoin.c 		\
			ft_strtrim.c		\
		    ft_split.c			\
			ft_itoa.c 			\
			ft_strmapi.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\

BONUSES =	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			
OBJ		=	$(SRC:.c=.o)

BONUS_OBJ	=	$(BONUSES:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $? 

%.o: %.c libft.h
	gcc  $(FLAGS) -c $< -o $@

bonus:  $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ) 

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: clean fclean re bonus 
