/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:36:36 by coder             #+#    #+#             */
/*   Updated: 2022/03/24 20:57:27 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int	expose_handle(fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data ->win_ptr);
	draw(data);
	return (0);
}
int	mouse_hook(int button, int x, int y)
{
	printf("button %d, x = %d, y=%d\n ", button, x, y);
	return(0);
}

int	main(int argc,char **argv)
{
	
	fdf *data;
	char *file_name;
	int i;
	int j;

	if(argc != 2)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	file_name = argv[1];	
	data = (fdf*)malloc(sizeof(fdf));
	data_init(data, file_name);	
	convert_file_matrix(file_name, data);
	max_z(data);
	draw(data);
	i = 0;
	while((i < data->height))
	{
		j=0;
		while((j < data->width))
		{
			printf("%3d ", data->z_matrix[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 17, 1L<<0, close_all, data);
	mlx_expose_hook(data->win_ptr, expose_handle, data);
	mlx_loop(data->mlx_ptr);
	
}
