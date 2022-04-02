/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:36:36 by coder             #+#    #+#             */
/*   Updated: 2022/04/02 15:41:05 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	expose_handle(t_fdf *data)
{
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		*data;
	char		*file_name;

	if (argc != 2)
		ft_putstr_fd("Wrong usage. Expected './fdf <file_path>'.\n", 1);
	file_name = argv[1];
	data = data_init(file_name);
	convert_file_matrix(file_name, data);
	neg_z(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, close_all, data);
	mlx_expose_hook(data->win_ptr, expose_handle, data);
	mlx_loop(data->mlx_ptr);
}
