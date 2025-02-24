/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:00 by paperez-          #+#    #+#             */
/*   Updated: 2025/02/24 19:48:34 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_mouse_hook(int key, int x, int y, t_fracdata *fracdata)
{
	if (key == 5)
	{
		fracdata->x = ((x - 960)/ fracdata->zoom + fracdata->x) - ((x - 960) / (fracdata->zoom / 1.1));
		fracdata->y = ((y - 540) / fracdata->zoom + fracdata->y) - ((y - 540) / (fracdata->zoom / 1.1));
	}
	if (key == 4)
	{
		fracdata->x = ((x - 960) / fracdata->zoom + fracdata-> x) - ((x - 960) / (fracdata->zoom * 1.1));
		fracdata->y = ((y - 540) / fracdata->zoom + fracdata-> y) - ((y - 540) / (fracdata->zoom * 1.1));
	}
	if (key == 4 || key == 5)
		zoom(key, fracdata);
	return(0);
}

int	close_win(t_fracdata *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

int	on_key_hook(int key, t_fracdata *data)
{
	if (key == 65307)
	{
		close_win(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	static double	z;
	static double	x;
	static double	y;
	t_fracdata	*data;

	z = 500;
	x = 0;
	y = 0;
	if  ((argc > 4 || argc < 2) || (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia")))
	{
		ft_printf("Los fractales disponibles son: Mandelbrot y Julia");
		exit (0);
	}
	data = construct_fracdata(z, x, y, argv);
	paint_fixed_fractal(data, z);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_key_hook(data->mlx_win, on_key_hook, data);
	mlx_mouse_hook(data->mlx_win, *on_mouse_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
	return (0);
}
