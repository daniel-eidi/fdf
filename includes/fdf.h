#ifndef FDF_H
# define FDF_H

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
	int color;
	int zoom;
	int sx;
	int sy;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;


void	convert_file_matrix(char * file_name, fdf *data);
int	get_height(char *file_name);
int	get_width(char *file_name);
void bresenham(float x, float y, float x1, float y1, fdf *data);
void draw (fdf *data);
int close_all();
fdf *data_init(fdf *data);

#endif