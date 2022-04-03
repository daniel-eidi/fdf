/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:36:36 by coder             #+#    #+#             */
/*   Updated: 2022/04/03 04:50:20 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	expose_handle(t_fdf *data)
{
	draw(data);
	return (0);
}

static int	checkfd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		*data;
	char		*file_name;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong usage. Expected './fdf <file_path>'.\n", 1);
		return (1);
	}
	file_name = argv[1];
	if (checkfd(file_name))
	{
		ft_putstr_fd("File not found.\n", 1);
		return (1);
	}
	data = data_init(file_name);
	convert_file_matrix(file_name, data);
	neg_z(data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, close_all, data);
	mlx_expose_hook(data->win_ptr, expose_handle, data);
	mlx_loop(data->mlx_ptr);
}
