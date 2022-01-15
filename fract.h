/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:45:42 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/15 20:45:30 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define SIDE 800

typedef struct d_color{
	unsigned char	r;
	int				startr;
	int				endr;
	unsigned char	b;
	int				startb;
	int				endb;
	unsigned char	g;
	int				startg;
	int				endg;
}				t_color;

typedef struct d_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct d_zomm {
	int		x;
	int		y;
	double	scale;
	int		it;
	int		max_it;
}			t_zoom;

typedef struct d_complex {
	double	imag;
	double	real;
}				t_complex;

typedef struct d_display{
	void	*init;
	void	*win;
	double	yscale;
	double	xscale;
	double	xtran;
	double	ytran;
	int		it;
	int		max_it;
	double	zoom_x;
	double	zoom_y;
	double	xcord;
	double	ycord;
	int		position;
	int		fract;
	int		h;
	t_img	*img;
	t_color	*color;
}				t_display;

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			is_hexa(char c);
int			ft_atoi_hex(char *str);
char		*ft_filling(char *r, char *g, char *b);
char		*dectohex(unsigned int num);
int			ft_convert(int red, int green, int blue);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

t_display	*mlx_initialization(void);
void		value_sitting(t_display *mlx);
void		mandelbrot(t_display *mlx);
void		julia(t_display *mlx);
void		burning_ship(t_display *mlx);
void		lighting_pixels_man(t_display *mlx);
void		lighting_pixels_julia(t_display *mlx);
void		lighting_pixels_ship(t_display *mlx);
int			ft_iteration_man(t_complex z, int x, int y, t_display *mlx);
int			ft_iteration_julia(t_complex c, int x, int y, t_display *mlx);
int			ft_iteration_ship(t_complex z, int x, int y, t_display *mlx);
int			coloring_pixels(t_display *mlx);
void		pixels_image(t_display *mlx, int x, int y, int color);

int			key_event(int keysym, t_display *mlx);
int			mouse_event(int button, int x, int y, t_display *mlx);
int			hundle_no_event(t_display *mlx);
int			mouse_cord(int x, int y, t_display *mlx);
void		hundle_key_event(int keysym, t_display *mlx);
void		hundle_mouse_event(int button, int x, int y, t_display *mlx);
int			red_cross(t_display *mlx);
void		ft_help(t_display *mlx);

#endif