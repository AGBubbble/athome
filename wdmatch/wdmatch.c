#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	wdmatch(char *s1, char *s2)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			i++;
		}
		else
			j++;
		if (s2[j] == '\0')
		{
			ft_putchar('\n');
			break;
		}
		if (s1[i] == '\0')
		{
			ft_putstr(s1);
			ft_putchar('\n');
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
	}
	else
	{
		wdmatch(argv[1], argv[2]);
	}
	return 0;
		
}