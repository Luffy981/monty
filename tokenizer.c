#include "monty.h"

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
		return (NULL);
	}
	while(*buffer == ' ')
	{
		buffer++;
	}
	while((tokens[i] = str_tok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= m)
		{
			ptr = _realloc(tokens, 8 * i, 8 * (i + 1));
			tokens = ptr;
			if (tokens == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (tokens);
}
char *str_tok(char *buffer, char *d)
{
	static char *save = NULL;
	char *string = NULL;
	char *set = NULL;

	buffer = buffer ? buffer : save;
	if (*buffer != '\0')
	{
		while(*buffer == ' ' || *buffer == '\n')
		{
			buffer++;
		}
		if(!*set)
		{
			save = '\0';
		} else
		{
			string = set;
			while (*set != *d && *set != '\0')
			{
				set++;
			}
			if (!*set != '\0')
			{
				*set = '\0';
				set++;
			}
			save = set;
			return(string);
		}
	}
	save = NULL;
	buffer = NULL;
	return (NULL);
}

void *_realloc(void *str, size_t old_size, size_t new_size)
{
	void *new_memory = NULL;

	if (new_size  == old_size)
	{
		return (str);
	}
	if (new_size == 0 && str)
	{
		free(str);
		return(NULL);
	}
	new_memory = malloc(new_size);
	if (new_memory == NULL)
	{
		return (NULL);
	}
	if (str == NULL)
	{
		fill_an_array(new_memory, '\0', new_size);
		free(str);
	} else
	{
		_memcpy(new_memory, str, old_size);
		free(str);
	}
	result (new_memory);
}

void *_memcpy(char *dest, char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n ; i++)
	{
		dest[i] = src[i];
	}
	return(dest);
}

void *fill_an_array(void *str, char c, size_t len)
{
	void *p = str;
	size_t i = 0;
	while (i < len)
	{
		*p = c;
		p++;
		i++;
	}
	return (str);
}
