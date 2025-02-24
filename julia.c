/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:23 by paperez-          #+#    #+#             */
/*   Updated: 2025/02/24 18:58:22 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia_point(complex c, int depth, t_fracdata *data)
{
	complex	z;
	double	tmp;
	int		i;

	z.r = c.r;
	z.i = c.i;
	i = 0;
	while (i < depth)
	{
		tmp = (z.r * z.r) + (z.i * z.i);
		if (tmp > 4)
			return (i);
		else
		{
			tmp = z.r * z.r - z.i * z.i + data->i;
			z.i = 2 * z.r * z.i + data->j;
			z.r = tmp;
		}
		i++;
	}
	return (i);
}
