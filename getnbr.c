#include <stdlib.h>
#include "libft/inc/libft.h"
int	get_nb_int(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret++;
			while ((str[i] >= '0' && str[i] <= '9') && str[i])
				i++;
		}
		else
			i++;
	}
	return (ret);
}
#include <stdio.h>
int	*getint(char *str)
{
	int	*ret;
	int	nb;
	int	i;
	int	j;
	FILE	*int1;
//	FILE	*int2;

	int1 = fopen("int1.txt", "w+");
//	int2 = fopen("int2.txt", "w+");
	i = 0;
	j = 0;
	nb = get_nb_int(str);
	ret = malloc(sizeof(int) * nb);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret[j] = ft_atoi(str + i);
			fprintf(int1, "%d\n", ret[i]);
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			j++;
		}
		else
			i++;
	}
	return (ret);
}
