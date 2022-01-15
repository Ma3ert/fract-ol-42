/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:24 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/15 16:21:32 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

char	*ft_filling(char *r, char *g, char *b)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	str[i++] = '0';
	str[i++] = 'x';
	ft_strlcat(str, r, 10);
	ft_strlcat(str, g, 10);
	ft_strlcat(str, b, 10);
	return (str);
}

char	*dectohex(unsigned int num)
{
	char	*temp;
	int		mod;
	int		i;

	i = 1;
	mod = 0;
	temp = malloc(sizeof(char) * 4);
	while (num != 0)
	{
		mod = num % 16;
		if (mod < 10)
			temp[i--] = mod + 48;
		else
			temp[i--] = mod + 55;
		num = num / 16;
	}
	temp[2] = '\0';
	return (temp);
}

int	ft_convert(int red, int green, int blue)
{
	char	*r;
	char	*g;
	char	*b;
	char	*color;
	int		res;

	r = dectohex(red);
	g = dectohex(green);
	b = dectohex(blue);
	color = ft_filling(r, g, b);
	free(r);
	free(g);
	free(b);
	res = ft_atoi_hex(color);
	free(color);
	return (res);
}

int	coloring_pixels(t_display *mlx)
{
	double			n;
	int				res;

	if (mlx->it == mlx->max_it && mlx->fract != 2)
		return (0x000000);
	n = (double)mlx->it / (double)mlx->max_it;
	mlx->color->r = mlx->color->startr * (1 - n) + mlx->color->endr * n;
	mlx->color->g = mlx->color->startg * (1 - n) + mlx->color->endg * n;
	mlx->color->b = mlx->color->startb * (1 - n) + mlx->color->endb * n;
	res = ft_convert(mlx->color->r, mlx->color->g, mlx->color->b);
	return (res);
}
