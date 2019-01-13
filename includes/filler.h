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
	int		p1_x;
	int		p1_y;
	int		p2_x;
	int		p2_y;

}				t_filler;

int		get_next_line(const int fd, char **line);
void	ft_player(t_filler *filler);
int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_strdup(const char *str);
void	ft_parsing(t_filler *filler);
void	error(t_filler *filler);
char	*ft_strstr(const char *str, const char *to_find);
void	ft_algo(t_filler *filler);

#endif
