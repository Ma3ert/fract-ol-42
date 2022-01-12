/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_Ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:39:36 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/07 20:44:20 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_iteration_ship(t_complex z, int x, int y, t_display *mlx)
{
	t_complex	r;
	t_complex	c;

	mlx->it = 0;
	c.real = ((x * mlx->xscale) - mlx->zoom_x);
	c.imag = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.imag * z.imag) < 4) && mlx->it < mlx->max_it)
	{
		r.real = (fabs(z.real) * fabs(z.real)) - (fabs(z.imag) * fabs(z.imag));
		r.real += c.real;
		r.imag = (2 * fabs(z.imag) * fabs(z.real)) + c.imag;
		z = r;
		mlx->it++;
	}
	return (mlx->it);
}

void	lighting_pixels_ship(t_display *mlx)
{
	int			x;
	int			y;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	y = 0;
	while (y < SIDE)
	{
		x = 0;
		while (x < SIDE)
		{
			mlx->it = ft_iteration_ship(z, x, y, mlx);
			if (mlx->it == mlx->max_it)
				pixels_image(mlx, x, y, 0x000000);
			else
				pixels_image(mlx, x, y, coloring_pixels(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 5, 0, 0xffffff, "press space for help");
	mlx_string_put(mlx->init, mlx->win, 700, 770, 0xffffff, "By Ma3ert");
	if (mlx->h == -1)
		ft_help(mlx);
}
