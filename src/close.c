/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:39:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/28 22:42:32 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_matrix(t_fdf *data)
{
	int	j;

	j = 0;
	while (j < data->height)
	{
		free(data->z_matrix[j]);
		free(data->color_matrix[j]);
		j++;
	}
	free(data->z_matrix);
	free(data->color_matrix);
}

int	close_all(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->image);
	free(data->mlx_ptr);
	free_matrix(data);
	free(data);
	exit(0);
	return (0);
}
