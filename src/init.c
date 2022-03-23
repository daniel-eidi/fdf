#include "../includes/fdf.h"

fdf *data_init(fdf *data)
{
	data->width = 0;
	data-> height = 0;
	data-> z_matrix = NULL;
	data-> color = 0;
	data-> zoom = 0;
	data-> sx = 0;
	data-> sy = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "Hello world!");
	return(data);
}