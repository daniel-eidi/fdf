/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:47:14 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/24 21:03:08 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void isomatric(float *x, float *y, int z)
{
	float	new_x;
	float	new_y;

	new_x = (*x - *y) * cos(0.7);
	new_y = (*x + *y) * sin(0.7) - z;
	*x = new_x;
	*y = new_y;
}
void shift (int sx, int sy,float *x, float *y, float *x1, float *y1)
{
	*x = *x + sx;
	*x1 = *x1 + sx;
	*y = *y + sy;
	*y1 = *y1 + sy;
}

void make_line(float x, float y, float x1, float y1, fdf *data)
{
	int		z;
	int		z1;
		
	z = data->z_matrix[(int)y][(int)x];	
	z1 = data->z_matrix[(int)y1][(int)x1];
	data->color = data->color_matrix[(int)y][(int)x];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	isomatric(&x, &y, z);
	isomatric(&x1, &y1, z1);
	bresenham(x, y, x1, y1, data);
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	delta_x;
	float	delta_y;
	int		max_steps;
	int		i;

	max_steps = max(mod(x1 - x), mod(y1 - y));
	delta_x = (x1 - x) / max_steps;
	delta_y = (y1 - y) / max_steps;
	shift(data->sx, data->sy, &x, &y, &x1, &y1);
	i = 0;
	while (i < max_steps)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += delta_x;
		y += delta_y;
		i++;
	}
}

void	draw(fdf *data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= data->height -1)
	{
		x = 0;
		while (x <= data->width -1)
		{
			if (x < data->width -1)
				make_line (x, y, x + 1, y, data);
			if (y < data->height -1)
				make_line (x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
