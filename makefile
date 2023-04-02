# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 18:37:08 by hhaddouc          #+#    #+#              #
#    Updated: 2022/06/25 07:28:46 by hhaddouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BONUS	=	checker
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
PUSH_SWAP = push_swap.c utils/utils.c \
			utils/big_sorting.c \
			utils/_big_sorting.c \
			utils/_utils.c \
			utils/small_sorting.c \
			utils/operations.c \
			utils/_operations.c \
			
LIBFT =  libft/ft_atoi.c \
		libft/ft_strcmp.c \
		libft/ft_isdigit.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_strlen.c \

BLBFT = bonus/libft/ft_atoi.c \
	bonus/libft/ft_isdigit.c \
	bonus/libft/ft_lstadd_back_bonus.c \
	bonus/libft/ft_lstadd_front_bonus.c  \
	bonus/libft/ft_lstlast_bonus.c  \
	bonus/libft/ft_lstnew_bonus.c \
	bonus/libft/ft_lstsize_bonus.c \
	bonus/libft/ft_strcmp.c \
	bonus/get_next_line/get_next_line.c	\
	bonus/get_next_line/get_next_line_utils.c \

CHECKER = bonus/checker.c	\
		bonus/utils/operations.c \
		bonus/utils/_operations.c \
		bonus/utils/utils.c \

OBJ_PS = $(PUSH_SWAP:.c=.o)
LIBOOBS = $(LIBFT:.c=.o)
BOBJ_PS = $(CHECKER:.c=.o)
O_BLBFT = $(BLBFT:.c=.o)

all : $(NAME)

$(NAME): $(OBJ_PS) $(LIBOOBS)
	$(CC) $(CFLAGS) $(OBJ_PS) $(LIBOOBS) -o push_swap

clean	:
		rm -rf $(OBJ_PS) $(LIBOOBS) $(O_BLBFT) $(BOBJ_PS)
		
fclean	:	clean
		rm -rf $(NAME) $(BONUS)
bonus	:	$(BONUS)

$(BONUS) : $(BOBJ_PS) $(O_BLBFT)
	$(CC) $(CFLAGS) $(BOBJ_PS) $(O_BLBFT) -o checker

re		: clean all