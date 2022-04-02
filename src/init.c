/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:59:36 by coder             #+#    #+#             */
/*   Updated: 2022/04/02 17:46:05 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*data_init(char *file_name)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->zoom = zoom_to_fit(data);
	init_matrix(data);
	data->color = 0;
	data->min_z = 0;
	data->sx = WINDOW_WIDTH / 2 - (data->width * data->zoom) / 2;
	data->sy = WINDOW_HEIGHT / 2 - (data->height * data->zoom) / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	data->x = 0;
	data->zscale = 1;
	data->x1 = 0;
	data->y = 0;
	data->y1 = 0;
	data->image = image_init(data->mlx_ptr);
	return (data);
}

t_image	*image_init(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, \
	&image->pixel_bits, &image->line_bytes, &image->endian);
	return (image);
}

void	init_matrix(t_fdf *data)
{
	int	i;

	data ->z_matrix = \
	(int **)malloc(sizeof(int *) * (data->height + 1));
	data ->color_matrix = \
	(int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = \
		(int *)malloc(sizeof(int *) * (data-> width + 1));
		data->color_matrix[i++] = \
		(int *)malloc(sizeof(int *) * (data-> width + 1));
	}
}
