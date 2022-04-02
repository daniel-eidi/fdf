/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:47:14 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/04/02 22:19:21 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isomatric(float *x, float *y, int z)
{
	float	new_x;
	float	new_y;

	new_x = (*x - *y) * cos(30 * 0.0174533);
	new_y = (*x + *y) * sin(30 * 0.0174533) - z;
	*x = new_x;
	*y = new_y;
}

void	make_line_right(float x, float y, t_fdf *data)
{
	int		z;
	int		z1;
	int		x1;
	int		y1;

	x1 = x + 1;
	y1 = y;
	z = (data->z_matrix[(int)y][(int)x] - data->min_z) \
	* data->zoom * data->zscale;
	z1 = (data->z_matrix[(int)y1][(int)x1] - data->min_z) \
	* data->zoom * data->zscale;
	data->color = data->color_matrix[(int)y][(int)x];
	data->x = x * data->zoom;
	data->y = y * data->zoom;
	data->x1 = x1 * data->zoom;
	data->y1 = y1 * data->zoom;
	isomatric(&data->x, &data->y, z);
	isomatric(&data->x1, &data->y1, z1);
	bresenham(data);
}

void	make_line_down(float x, float y, t_fdf *data)
{
	int		z;
	int		z1;
	int		x1;
	int		y1;

	x1 = x;
	y1 = y + 1;
	z = (data->z_matrix[(int)y][(int)x] - data->min_z) \
	* data->zoom * data->zscale;
	z1 = (data->z_matrix[(int)y1][(int)x1] - data->min_z) \
	* data->zoom * data->zscale;
	data->color = data->color_matrix[(int)y][(int)x];
	data->x = x * data->zoom;
	data->y = y * data->zoom;
	data->x1 = x1 * data->zoom;
	data->y1 = y1 * data->zoom;
	isomatric(&data->x, &data->y, z);
	isomatric(&data->x1, &data->y1, z1);
	bresenham(data);
}

void	bresenham(t_fdf *data)
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
		if (data->x < WINDOW_WIDTH && data->y < WINDOW_HEIGHT \
		&& data->x > 0 && data->y > 0)
		{
			pixel_to_image(data->image, data->x, data->y, data->color);
		}
		data->x += delta_x;
		data->y += delta_y;
		i++;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->height -1)
	{
		x = 0;
		while (x <= data->width -1)
		{
			if (x < data->width -1)
			{
				make_line_right (x, y, data);
			}
			if (y < data->height -1)
				make_line_down (x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->image->image, 0, 0);
	print_instructions(data);
}
