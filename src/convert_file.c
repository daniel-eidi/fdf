#include "../includes/fdf.h"

int	get_height(char *file_name)
{
	char *line;
	int fd;
	int height;
	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return(height);
}

int	get_width(char *file_name)
{
	char *line;
	int fd;
	int width;
	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_countword(line, ' ');
	free(line);
	close(fd);
	return(width);
}
void put_line_matrix(char *line, int *z_line)
{
	char **value;
	int i;

	value = ft_split(line, ' ');
	i = 0;
	while(value[i])
	{
		z_line[i] = ft_atoi(value[i]);
		free(value[i]);
		i++;
	}
	free(value);
}

void convert_file_matrix(char * file_name, fdf *data)
{
	int fd;
	char * line;
	int i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data ->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i=0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int*) * (data-> width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		printf("Inserindo linha %d na matriz : %s", i, line);
		put_line_matrix (line, data->z_matrix[i]);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	close(fd);

}
