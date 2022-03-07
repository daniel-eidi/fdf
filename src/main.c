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

int	key_hook(int key)
{
	printf("%d\n", key);
	return (0);
}

int	main(int argc,char **argv)
{
	
	fdf *data;
	char *file_name;
	int i;
	int j;

	data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "Hello world!");
	
	if(argc != 2)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	file_name = argv[1];

	convert_file_matrix(file_name, data);
	//draw(data);
	printf("h = %d\n", data->height);
	printf("w = %d\n", data->width);
	data->zoom = 20;
	
	//bresenham(2,2, 100,100, data);
	//bresenham(100,10, 100,100, data);
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
	//mlx_key_hook(data->win_ptr, key_hook, NULL);
	
	mlx_loop(data->mlx_ptr);
	
}
