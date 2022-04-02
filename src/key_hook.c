/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:00:55 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/04/02 18:21:16 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_fdf *data)
{
	if (key == 65362)
		data -> sy -= 10;
	if (key == 65364)
		data -> sy += 10;
	if (key == 65363)
		data -> sx += 10;
	if (key == 65361)
		data -> sx -= 10;
	if (key == 61 | key == 65451)
		data->zoom /= 0.9;
	if ((key == 45 | key == 65453) && data->zoom > 1.12)
		data->zoom *= 0.9;
	if (key == 65307)
		close_all(data);
	if (key == 122 && data->zscale < 3)
		data->zscale += 0.1;
	if (key == 97 && data->zscale > 0.1)
		data->zscale -= 0.1;
	clear_image(data->image);
	draw(data);
	return (0);
}

void	shift(t_fdf *data)
{
	float	ax;
	float	ay;

	ax = data->sx;
	ay = data->sy;
	data->x += ax;
	data->x1 += ax;
	data->y += ay;
	data->y1 += ay;
}
