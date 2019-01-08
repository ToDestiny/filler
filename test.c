#include "./includes/filler.h"
#include <stdio.h>

int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);

int		main(void)
{
	char 	*str = "Plateau 24 40";
	char	**res;
	int		i = 0;
	int		y = 0;
	
	
	res = ft_strsplit(str, ' ');
	i = ft_atoi(res[1]);
	y = ft_atoi(res[2]);
	printf("i = %d, y = %d\n", i, y);
	return (0);
}
