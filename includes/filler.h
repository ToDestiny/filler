/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:29:00 by acolas            #+#    #+#             */
/*   Updated: 2019/02/14 13:06:13 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ABS(x) (((x) > 0) ? (x) : (-1) * (x))
# define DIST(i, j, k, l) (ABS(i - k) + ABS(j - l))
# include "../libft/libft.h"

typedef struct	s_map
{
	int		w;
	int		h;
	char	**m;
	char	**p;
	int		pw;
	int		ph;
	char	pc;
	char	oc;
}				t_map;

typedef struct	s_sol
{
	int		h;
	int		w;
	int		d;
}				t_sol;

void			ft_play(t_map *map, t_sol *s);
int				get_next_line(const int fd, char **line);
void			ft_read_second_part(t_map *map, char *s, char **a);
void			ft_read_map_part_two(t_map *map, char *s, int i);
int				ft_player(t_map *map, char *s);
void			ft_read_piece(t_map *map);
void			ft_find_solution(t_map *map);

#endif
