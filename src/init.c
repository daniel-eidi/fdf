/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:59:36 by coder             #+#    #+#             */
/*   Updated: 2022/03/24 21:02:35 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void data_init(fdf *data, char *file_name)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->zoom = zoom_to_fit(data);
	data-> z_matrix = NULL;
	data-> color_matrix = NULL;
	data-> color = 0;
	data-> max_z = 0;
	data-> sx = 0;
	data-> sy = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	data-> x = 0;
	data-> x1 = 0;
	data-> y = 0;
	data-> y1 = 0;
}