#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include "../libft//libft.h"
#include <stdio.h>

typedef struct	s_filler
{
	int		player;
	char	letter;
	int		width;
	int		height;

}				t_filler;

int		get_next_line(const int fd, char **line);
void	ft_get_info(t_filler *filler);

int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);

#endif
