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
	while((tokens[i] = strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= m)
		{
			ptr = realloc(tokens, 8 * (i + 1));
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
