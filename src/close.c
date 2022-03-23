#include "../includes/fdf.h"
static void free_matrix(fdf *data)
{
	int j;
	j=0;
	while(j < data->height)
	{
		free(data->z_matrix[j]);			
		j++;
	}
	free(data->z_matrix);
}

int close_all(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_matrix(data);
	free(data);
	exit(0);
	return(0);
}
