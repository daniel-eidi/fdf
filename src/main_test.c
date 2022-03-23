#include "../includes/fdf.h"
#include <stdio.h>

int main (int argc,char **argv)
{
	int fd1;
	int i;
	char *line;

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY, 0);
		i = 0;
		while (1)
		{
			line = get_next_line(fd1);
			if (line == NULL)
				break ;
			printf("Inserindo linha %d na matriz : %s", i, line);
			free(line);
			i++;
		}
		close(fd1);
	}
	return(0);
}