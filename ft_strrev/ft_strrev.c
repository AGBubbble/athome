#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	ft_strlen(char *str)
{
	int i;
	
	i = 0;
		while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int i;
	int length;
	char tmp;
	
	i = 0;
	length = ft_strlen(str);
	while (i == length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
		
	}
	return (str);
	
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	else
		ft_putstr(ft_strrev(argv[1]));
	return 0;
}