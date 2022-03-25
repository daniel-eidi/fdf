/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:47:14 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/25 01:00:26 by daeidi-h         ###   ########.fr       */
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
void shift (fdf *data)
{
	float ax;
	float ay;

	ax = data->sx;
	ay = data->sy;
	data->x += ax;
	data->x1 += ax;
	data->y += ay;
	data->y1 += ay;
}

void make_line_right(float x, float y, fdf *data)
{
	int		z;
	int		z1;
	int		x1;
	int		y1;

	x1= x + 1;
	y1= y;
	z = data->z_matrix[(int)y][(int)x];	
	z1 = data->z_matrix[(int)y1][(int)x1];
	data->color = data->color_matrix[(int)y][(int)x];

	data->x = x * data->zoom;
	data->y = y * data->zoom;
	data->x1 = x1 * data->zoom;
	data->y1 = y1 * data->zoom;
	
	isomatric(&data->x, &data->y, z);
	isomatric(&data->x1,&data->y1, z1);
	bresenham(data);
}

void make_line_down(float x, float y,fdf *data)
{
	int		z;
	int		z1;
	int		x1;
	int		y1;

	x1= x;
	y1= y + 1;
	z = data->z_matrix[(int)y][(int)x];	
	z1 = data->z_matrix[(int)y1][(int)x1];
	data->color = data->color_matrix[(int)y][(int)x];

	data->x = x * data->zoom;
	data->y = y * data->zoom;
	data->x1 = x1 * data->zoom;
	data->y1 = y1 * data->zoom;
	
	isomatric(&data->x, &data->y, z);
	isomatric(&data->x1, &data->y1, z1);
	bresenham(data);
}

void	bresenham(fdf *data)
{
	float	delta_x;
	float	delta_y;
	int		max_steps;
	int		i;

	max_steps = max(mod(data->x1 - data->x), mod(data->y1 - data->y));
	delta_x = (data->x1 - data->x) / max_steps;
	delta_y = (data->y1 - data->y) / max_steps;
	shift(data);
	i = 0;
	while (i < max_steps)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color);
		data->x += delta_x;
		data->y += delta_y;
		i++;
	}
}

void	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y <= data->height -1)
	{
		x = 0;
		while (x <= data->width -1)
		{
			if (x < data->width -1)
				make_line_right (x, y, data);
			if (y < data->height -1)
				make_line_down (x, y, data);
			x++;
		}
		y++;
	}
}
