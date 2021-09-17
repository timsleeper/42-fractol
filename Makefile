#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2021/09/12 19:05:31 by ftadeu-d          #+#    #+#             */
#/*   Updated: 2021/09/13 22:56:08 by ftadeu-d         ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

NAME = fractol

MLX = libmlx-linux.a

MLX_PATH = minilibx-linux

MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = ./burningship.c\
		./fractol.c\
		./init.c\
		./julia.c\
		./main.c\
		./mandelbrot.c

OBJ = ./burningship.o\
		./fractol.o\
		./init.o\
		./julia.o\
		./main.o\
		./mandelbrot.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -w -g -o $(NAME) $(OBJ) -L $(MLX_PATH) $(MLX_FLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(OBJ): $(SRC)
	@$(CC) $(FLAGS) -w -g -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJ) $(NAME)

re: fclean all