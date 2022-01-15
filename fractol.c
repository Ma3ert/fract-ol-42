/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:42 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/15 20:45:23 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	red_cross(t_display *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	free(mlx->color);
	free(mlx->img);
	free(mlx);
	exit(0);
}
void	mandelbrot(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol D Ma3ert");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
			&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fract = 1;
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx); 
	mlx_hook(mlx->win, 17, 0, &red_cross, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}

void	julia(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol D Ma3ert");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
			&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fract = 2;
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win, 17, 0, &red_cross, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_hook(mlx->win, 6, 1L << 0, &mouse_cord, mlx);
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}

void	burning_ship(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, SIDE, SIDE, "Fractol D Ma3ert");
	mlx->img->img = mlx_new_image(mlx->init, SIDE, SIDE);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
			&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx->fract = 3;
	mlx_hook(mlx->win, 17, 0, &red_cross, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, &mouse_event, mlx);
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}
