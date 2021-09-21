#include "monty.h"

char *file_read(char *filename)
{
	ssize_t size;
	int fd;
	char *buffer = NULL;
	struct stat st;

	if (filename == NULL)
		return(NULL);
	fd = open(filename, O_CREAT | O_RDONLY, 600);
	if (fd == -1)
		return (NULL);
	fstat(fd, &st);
	buffer = malloc(sizeof(char) * st.st_size + 1);
	if (buffer == NULL)
	{
		close(fd);
		return(NULL);
	}
	size = read(fd, buffer, st.st_size);
	if (size == -1)
	{
		close(fd);
		free(buffer);
		return(NULL);
	}
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
