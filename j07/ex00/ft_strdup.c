#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *string;
	int src_size;
	int i;

	i = 0;
	while (src[src_size] != '\0')
	{
		sc_size++;
		string = (char*)malloc(sizeof(*string) * (src_size));
	}	
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[sc_size] = '\0';
	return (string);
}

