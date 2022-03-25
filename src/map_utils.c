/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:51:13 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/24 20:14:05 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	zoom_to_fit(fdf *data)
{
	float	proportion_x;
	float	proportion_y;
	float	zoom;

	proportion_x = WINDOW_WIDTH / data->width;
	proportion_y = WINDOW_HEIGHT / data->height;
	zoom = min(proportion_x, proportion_y);
	if (zoom < 4)
		return (2);
	return (zoom / 2);
}

void	max_z(fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while ((i < data->height))
	{
		j = 0;
		while ((j < data->width))
		{
			if (mod(data->z_matrix[i][j]) > data->max_z)
				data->max_z = mod(data->z_matrix[i][j]);
			j++;
		}
		i++;
	}	
	printf ("maior z = %d\n", data->max_z);
}
