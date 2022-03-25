/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:00:55 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/24 18:52:32 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, fdf *data)
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
		data->zoom += 1;
	if (key == 45 | key == 65453)
		data->zoom -= 1;
	if (key == 65307)
		close_all(data);
	mlx_clear_window(data->mlx_ptr, data ->win_ptr);
	draw(data);
	return (0);
}
