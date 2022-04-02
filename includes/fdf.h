/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:32:00 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/04/02 17:45:37 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdio.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/
# include <math.h>
# include <mlx.h>

/*
** My own libft library, completed with previously implemented functions such as
** get_next_line
*/
# include "../libft/libft.h"

/*
** Other fdf libraries
*/
typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_image;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
	int		color;
	float	zoom;
	int		sx;
	int		sy;
	int		min_z;
	float	zscale;
	float	x;
	float	x1;
	float	y;
	float	y1;

	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
}	t_fdf;

void	convert_file_matrix(char *file_name, t_fdf *data);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	bresenham(t_fdf *data);
void	draw(t_fdf *data);
int		close_all(t_fdf *data);
t_fdf	*data_init(char *file_name);
void	neg_z(t_fdf *data);
float	zoom_to_fit(t_fdf *data);
int		mod(float x);
int		max(float x, float y);
int		min(float x, float y);
int		key_hook(int key, t_fdf *data);
void	pixel_to_image(t_image *image, float x, float y, int color);
t_image	*image_init(void *mlx);
void	clear_image(t_image *image);
void	init_matrix(t_fdf *data);
void	shift(t_fdf *data);
void	print_instructions(t_fdf *data);

#endif