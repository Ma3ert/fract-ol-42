/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:45:00 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/10 20:16:32 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	main(int ac, char **av)
{
	t_display	*mlx;

	if (ac == 2)
	{
		mlx = NULL;
		if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
			mandelbrot(mlx);
		else if (ft_strncmp(av[1], "julia", 6) == 0)
			julia(mlx);
		else if (ft_strncmp(av[1], "burning ship", 13) == 0)
			burning_ship(mlx);
		else
			return (printf("unvalid fractol !!\n\
				Ma3ert but you can choose one of those:\n	\n1-mandelbrot\n\
				\n2-julia\n	\n3-burning ship\n"));
	}
	printf("unvalid fractol !!\nMa3ert but you can choose one of those:\n\
			\n1-mandelbrot\n	\n2-julia\n	\n3-burning ship\n");
	return (0);
}
