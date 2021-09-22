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
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
	fstat(fd, &st);
	buffer = malloc(sizeof(char) * st.st_size + 1);
	if (buffer == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
		close(fd);
		return(NULL);
	}
	size = read(fd, buffer, st.st_size);
	if (size == -1)
	{
        fprintf(stderr, "Error: Can't read file %s\n", filename);
		close(fd);
		free(buffer);
		return(NULL);
	}
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
