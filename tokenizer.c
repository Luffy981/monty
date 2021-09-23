#include "monty.h"

/**
 * tokenizer - Function to tokens
 * @buffer: Buffer
 * @delimiter: Delimiter
 * Return: Return array of strings
 */
char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	char **ptr = NULL;
	unsigned int m = 1;

	if (buffer == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * m);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: realloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (*buffer == ' ' || *buffer == '\t')
	{
		buffer++;
	}
	while ((tokens[i] = str_tok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= m)
		{
			ptr = _realloc(tokens, 8 * i, 8 * (i + 1));
			tokens = ptr;
			if (tokens == NULL)
			{
				fprintf(stderr, "Error: realloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}

/**
 * str_tok - Function to cut string
 * @buffer: Buffer
 * @d: Delimiter
 * Return: Return string
 */
char *str_tok(char *buffer, char *d)
{
	static char *save;
	char *string = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : save;
	if (*buffer != '\0')
	{
		while (*buffer == ' ' || *buffer == '\n' || *buffer == '\t')
		{
			buffer++;
		}
		set = buffer;
		if (!*set)
		{
			save = '\0';
		} else
		{
			string = set;
			while (*set != *d  && *set != '\0')
			{
				set++;
			}
			if (*set != '\0')
			{
				*set = '\0';
				set++;
			}
			save = set;
			return (string);
		}
	}
	save = NULL;
	buffer = NULL;
	return (NULL);
}

/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the previous memory
 * @old_size: the old size
 * @new_size: the new size
 * Return: a pointer to the newly allocated memory
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * fill_an_array - fill an array with elements
 * @str: the given array
 * @c: the given element
 * @len: the length of the array
 * Return: pointer to filled array
 */
void *fill_an_array(void *str, char c, size_t len)
{
	char *p = str;
	unsigned int i = 0;

	while (i < len)
	{
		*p = c;
		p++;
		i++;
	}
	return (str);
}

/**
 * _memcpy - cpies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to dest
 */
void *_memcpy(char *dest, char *src, size_t n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
