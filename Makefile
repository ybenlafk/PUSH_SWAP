# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 19:07:44 by ybenlafk          #+#    #+#              #
#    Updated: 2022/12/27 15:59:46 by ybenlafk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
BNAME= checker

HEADER= push_swap.h

SRCS=    swap_utile.c parsing.c strjoin.c lst_tools.c\
        swap_utile_2.c swap_utile_3.c swap_utile_4.c swap_utile_5.c swap_utile_6.c\
        swap_utile_7.c r_op.c s_op.c p_op.c \
        five_elements.c\
        algo.c \
        main.c\

SRCS_BONUS=    swap_utile.c parsing.c lst_tools.c strjoin.c\
                swap_utile_2.c swap_utile_3.c swap_utile_4.c swap_utile_5.c swap_utile_6.c\
                swap_utile_7.c r_op.c s_op.c p_op.c algo.c\
                get_next_line.c get_next_line_utils.c\
                checker_utils.c checker_utils_2.c\
                checker.c\

OBGJ= $(SRCS:.c=.o)
BOBGJ= $(SRCS_BONUS:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
FRM = rm -rf

all: $(NAME)

$(NAME): $(OBGJ)
	$(CC) $(CFLAGS) $(OBGJ) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBGJ)
	$(CC) $(CFLAGS) $(BOBGJ) -o $(BNAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(FRM) $(OBGJ) $(BOBGJ)

fclean: clean
	$(FRM) $(NAME) $(BNAME)

re: fclean all
