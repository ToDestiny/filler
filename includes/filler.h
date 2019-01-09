#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include "../libft//libft.h"
#include <stdio.h>

typedef struct	s_filler
{
	int		player;
	char	me;
	char	op;
	char	**map;
	char	**piece;
	int		w_map;
	int		h_map;
	int		w_piece;
	int		h_piece;

}				t_filler;

int		get_next_line(const int fd, char **line);
void	ft_get_info(t_filler *filler);
int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_strdup(const char *str);
void	ft_parsing(t_filler *filler);
void	error(t_filler *filler);

#endif
