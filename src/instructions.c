/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:47:48 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/04/02 20:53:06 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_instructions(t_fdf *data)
{
	int	y;

	y = 0;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, \
	y += 50, -1, "FDF");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, \
	y += 35, -1, "Press 'ESC' to close");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, \
	y += 35, -1, "Press '-' or '+' to zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, \
	y += 20, -1, "Press arrow keys to move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, \
	y += 20, -1, "Press 'Z' to increase and 'A' to decrease Z index");
}
