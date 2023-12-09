# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:46:48 by rhsu              #+#    #+#              #
#    Updated: 2023/12/06 16:25:40 by rhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INC = ft_printf.h

LIB = libft.a
LIB_DIR = libft/
OBJS = *.o

CFILES = ft_printf.c \
		ft_extract_print_1_conv.c \
		ft_hexint.c \
		ft_min_prec_conv.c \
		ft_p_chr.c \
		ft_p_common_fn.c \
		ft_p_conv.c \
		ft_p_hex.c \
		ft_p_int.c \
		ft_p_ptr.c \
		ft_p_str.c \
		ft_p_unsigned.c \
		ft_utoa.c

OFILES = $(CFILES:.c=.o)

BONUS_CFILES = 	ft_printf.c \
		ft_extract_print_1_conv.c \
		ft_hexint.c \
		ft_min_prec_conv.c \
		ft_p_chr_bonus.c \
		ft_p_common_fn.c \
		ft_p_conv_bonus.c \
		ft_p_hex_bonus.c \
		ft_p_int_bonus.c \
		ft_p_ptr_bonus.c \
		ft_p_str_bonus.c \
		ft_p_unsigned_bonus.c \
		ft_utoa.c

LIBOFILES =  \
		$(LIB_DIR)ft_atoi.o \
		$(LIB_DIR)ft_bzero.o \
		$(LIB_DIR)ft_calloc.o \
		$(LIB_DIR)ft_isalnum.o \
		$(LIB_DIR)ft_isalpha.o \
		$(LIB_DIR)ft_isascii.o \
		$(LIB_DIR)ft_isdigit.o \
		$(LIB_DIR)ft_isprint.o \
		$(LIB_DIR)ft_itoa.o \
		$(LIB_DIR)ft_memchr.o \
		$(LIB_DIR)ft_memcmp.o \
		$(LIB_DIR)ft_memcpy.o \
		$(LIB_DIR)ft_memmove.o \
		$(LIB_DIR)ft_memset.o \
		$(LIB_DIR)ft_putchar_fd.o \
		$(LIB_DIR)ft_putendl_fd.o \
		$(LIB_DIR)ft_putnbr_fd.o \
		$(LIB_DIR)ft_putstr_fd.o \
		$(LIB_DIR)ft_split.o \
		$(LIB_DIR)ft_strchr.o \
		$(LIB_DIR)ft_strdup.o \
		$(LIB_DIR)ft_striteri.o \
		$(LIB_DIR)ft_strjoin.o \
		$(LIB_DIR)ft_strlcat.o \
		$(LIB_DIR)ft_strlcpy.o \
		$(LIB_DIR)ft_strlen.o \
		$(LIB_DIR)ft_strmapi.o \
		$(LIB_DIR)ft_strncmp.o \
		$(LIB_DIR)ft_strnstr.o \
		$(LIB_DIR)ft_strrchr.o \
		$(LIB_DIR)ft_strtrim.o \
		$(LIB_DIR)ft_substr.o \
		$(LIB_DIR)ft_tolower.o \
		$(LIB_DIR)ft_toupper.o 

BONUS_OFILES = $(BONUS_CFILES:.c=.o)

.PHONY: all bonus clean fclean re makelibft

all: $(NAME)

$(NAME): $(OFILES) makelibft
	@ar rc $(NAME) $(OFILES) $(LIBOFILES) 
	@ranlib $(NAME)
	@echo "$@ compiled"

makelibft:
	@make -C $(LIB_DIR)

bonus: $(BONUS_OFILES) makelibft
	@ar rc $(NAME) $(BONUS_OFILES) $(LIBOFILES)
	@ranlib $(NAME)
	@echo "bonus library compiled"

%.o : %.c $(INC)
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES) $(BONUS_OFILES) $(LIB_DIR)$(OBJS)
	@echo "ftprintf, libft objects file removed"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)$(LIB)
	@echo "$(NAME), $(LIB_DIR)$(LIB) removed "

re: fclean all
