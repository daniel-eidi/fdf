/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:42:20 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/28 22:43:33 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_countword(line, ' ');
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	free(line);
	return (width);
}

void	split_color(char *value, int *color_matrix, int *z_line)
{
	char	**split;
	int		j;

	split = ft_split(value, ',');
	*color_matrix = ft_atoi_base(split[1], HEXADECIMAL_BASE);
	*z_line = ft_atoi(split[0]);
	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

void	put_line_matrix(char *line, int *z_line, int *color_matrix)
{
	char	**value;
	int		i;

	value = ft_split(line, ' ');
	i = 0;
	while (value[i])
	{	
		color_matrix[i] = -1;
		if (ft_strchr(value[i], ','))
		{
			split_color(value[i], &color_matrix[i], &z_line[i]);
		}
		else
			z_line[i] = ft_atoi(value[i]);
		free(value[i]);
		i++;
	}
	free(value);
}

void	convert_file_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		put_line_matrix (line, data->z_matrix[i], data->color_matrix[i]);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	data->color_matrix[i] = NULL;
	close(fd);
}
