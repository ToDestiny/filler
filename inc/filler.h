#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include "../libft/inc/libft.h"
#include <stdio.h>

typedef struct	s_filler
{
	char		ply;
	int			pltx;
	int			plty;
}				t_filler;

int	*getintt(char *str);
int	get_nb_intt(char *str);

#endif
