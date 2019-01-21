#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:28:37 by akolinko          #+#    #+#              #
#    Updated: 2018/06/08 23:12:24 by akolinko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m
WAC = \x1b[33m

SRC = fractol.c ft_error.c new_window.c  values_fractol.c mandelbrot.c hook.c hook1.c julia.c values.c thread.c mand_my.c serp.c burningship.c barnsley.c hook3.c my_mand2.c my_mand3.c values2.c hook2.c hook4.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ)  -lmlx\
    -framework OpenGl -framework AppKit -o $(NAME) -l ft -I libft -L libft

	@echo "$(OKC)Fractol:\tFractol ready$(NOC)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft
	@echo "$(WAC)Fractol:\tObject was created$(NOC)"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "$(ERC)Fractol:\tObjects were deleted$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(ERC)Fractol:\tFDF was deleted$(NOC)"

re: fclean all