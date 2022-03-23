#include "../includes/fdf.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
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
int	key_hook(int key, fdf *data)
{
	printf("%d\n", key);
	
	if(key == 65362)
		data -> sy -= 10;
	if(key == 65364)
		data -> sy += 10;
	if(key == 65363)
		data -> sx += 10;
	if(key == 65361)
		data -> sx -= 10;
	if(key == 65307)
		close_all(data);
	mlx_clear_window(data->mlx_ptr, data ->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc,char **argv)
{
	
	fdf *data;
	char *file_name;
	int i;
	int j;

	data = (fdf*)malloc(sizeof(fdf));
	data_init(data);	
	if(argc != 2)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	file_name = argv[1];	
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	convert_file_matrix(file_name, data);
	data->zoom = 20;
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
