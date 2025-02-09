
#include <stdio.h>
#include <stdlib.h>

/*
void	calc_nb_lc(char *str, int *nb_line, int *nb_col)
{
	int	i = 0;
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			if (str[i] == '\n')
				len -= 1;
			if (len > *nb_col)
				(*nb_col) = len;
			(*nb_line)++;
			len = 0;
		}
		len++;
		i++;
	}
	(*nb_line)++;
	(void)(*nb_line);
}

char	*reform_str(char *str, int nb_line, int nb_col)
{
	char	*map;
	int		i;
	int		j;

	map = malloc(sizeof(char) * nb_line * nb_col + 1);
	if (!map)
	{
		printf("malloc error\n");
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\n') || (str[i] == '\0'))
		{
			while (j % nb_col != 0)
			{
				map[j] = '_';
				j++;
			}
		}
		else
		{
			if (str[i] == ' ')
				map[j] = '_';
			else
				map[j] = str[i];
			j++;
		}
		i++;
	}
	return (map);
}

void	display(char *map, int nb_col)
{
	int	i = 0;

	while (map[i])
	{
		if ((i != 0) && (i % nb_col == 0))
			printf("\n");
		printf("%c", map[i]);
		i++;
	}
}

int	main(void)
{
	char	*str;
	char	*map;
	int		nb_line = 0;
	int		nb_col = 0;

	str = "111\n101\n101 111\n1011101\n1000001\n1110111\n  111\0";
	calc_nb_lc(str, &nb_line, &nb_col);
	printf("nb_line = %d, nb_col = %d\n", nb_line, nb_col);
	map = reform_str(str, nb_line, nb_col);
	printf("\n");
	display(map, nb_col);
	return (0);
}*/