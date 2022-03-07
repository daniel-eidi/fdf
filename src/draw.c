#include "../includes/fdf.h"

static int mod(float x)
{
	if(x)
		return(x);
	return(x * -1);
}

static int max(float x, float y)
{
	if(x >= y)
		return(x);
	return(y);
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float delta_x;
	float delta_y;
	int div;
	int z;
	int z1;
	z = data->z_matrix[(int)y][(int)x];	
	z1 = data->z_matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	
	
	data->color = 0xBBFAFF;
	if(z != 0 || z1 != 0)
		data->color =  0xfc0345;
	div =  max(mod(x1 - x),  mod(y1 - y));
	delta_x = (x1 - x) / div;
	delta_y = (y1 - y) / div;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += delta_x;
		y += delta_y;
	}
}

void draw (fdf *data)
{
	int y;
	int x;
	
	printf("Iniciando draw, h =%d, w = %d \n", data->height, data->width);
	y = 0;
	while(y <= data->height -1)
	{
		x = 0;
		while(x <= data->width -1)
		{
			if(x < data->width -1)
				bresenham(x, y, x+1, y, data);
			if(y < data->height -1)
				bresenham(x, y, x, y+1, data);
			//printf("imprimindo linha %d, coluna %d \n", y, x);
			x++;
		}
		y++;
	}
}