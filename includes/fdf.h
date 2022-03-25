#ifndef FDF_H
# define FDF_H

# define HEXADECIMAL_BASE	"0123456789abcdef"
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT	800
/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit. 
*/
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/
# include <math.h>
# include <mlx.h>

/*
** My own libft library, completed with previously implemented functions such as
** get_next_line and ft_printf. 
*/
# include "../libft/libft.h"

/*
** Other fdf libraries
*/
typedef struct
{
	int width;
	int height;
	int **z_matrix;
	int **color_matrix;
	int color;
	int zoom;
	int sx;
	int sy;
	int max_z;
	float	x;
	float	x1;
	float	y;
	float	y1;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	convert_file_matrix(char * file_name, fdf *data);
int	get_height(char *file_name);
int	get_width(char *file_name);
void bresenham(fdf *data);
void draw (fdf *data);
int close_all();
void data_init(fdf *data, char * file_name);
void max_z(fdf *data);
float	zoom_to_fit(fdf *data);
int mod(float x);
int max(float x, float y);
int min(float x, float y);
int	key_hook(int key, fdf *data);

#endif