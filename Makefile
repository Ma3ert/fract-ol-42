# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:13:21 by yait-iaz          #+#    #+#              #
#    Updated: 2022/01/11 20:22:57 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c extra_mlx.c hook_hundle.c mandelbrot.c color.c utils.c fractol.c Julia.c Burning_Ship.c
OBJS = $(SRCS:.c=.o)
NAME = fractol
HEADER = fract.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAG = -lm -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(MLX_FLAG) $(FLAGS) $(OBJS) -o $(NAME)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $<
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
