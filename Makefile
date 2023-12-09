# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:46:48 by rhsu              #+#    #+#              #
#    Updated: 2023/12/08 03:19:43 by rhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
INC = push_swap.h
BONUS_INC = checker_bonus.h

LIB = libftprintf.a
LIB_DIR = pf/
LIBFT_DIR = pf/libft/
FT_LIB = libft.a
OBJS = *.o

CFILES = push_swap.c \
		push_swap_2.c \
		push_swap_3.c \
		push_swap_4.c \
		push_swap_5.c \
		push_swap_6.c \
		push_swap_7.c \
		push_swap_8.c \
		push_swap_9.c \
		push_swap_10.c \
		push_swap_11.c \
		push_swap_12.c \
		push_swap_13.c \
		push_swap_14.c \
		push_swap_15.c \
		push_swap_16.c \
		push_swap_17.c

OFILES = $(CFILES:.c=.o)

BONUS_CFILES = 	checker_bonus.c \
		checker2_bonus.c \
		checker3_bonus.c \
		checker4_bonus.c \
		checker5_bonus.c \
		checker6_bonus.c \
		checker7_bonus.c \
		checker8_bonus.c \
		checker9_bonus.c \
		checker10_bonus.c

BONUS_OFILES = $(BONUS_CFILES:.c=.o)

.PHONY: all bonus clean fclean re runpf

all: $(NAME)

$(NAME): $(OFILES) runpf
	@cc $(OFILES) -lftprintf -Lpf $(FLAGS) -o $(NAME)
	@echo "$(NAME) program created"

runpf:
	@make -C $(LIB_DIR)


bonus: $(BONUS_OFILES) runpf 
	@cc $(BONUS_OFILES) -lftprintf -Lpf $(FLAGS) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) program created"

$(OFILES): %.o: %.c $(INC)
	cc $(FLAGS) -c $< -o $@

$(BONUS_OFILES): %.o: %.c $(BONUS_INC)
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(LIB_DIR)$(OBJS) $(LIBFT_DIR)$(OBJS)
	@echo "$(OBJS) $(LIB_DIR)$(OBJS), $(LIBFT_DIR)$(OBJS) files removed"

fclean:	clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f $(LIB_DIR)$(LIB)
	@rm -f $(LIBFT_DIR)$(FT_LIB)
	@echo "$(NAME), $(BONUS_NAME), $(LIB_DIR)$(LIB), $(LIBFT_DIR)$(FT_LIB) removed "

re: fclean all
