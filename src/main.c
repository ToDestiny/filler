/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/02/14 12:16:14 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_find_solution(t_map *map)
{
	t_sol	*s;

	if (!(s = (t_sol*)ft_memalloc(sizeof(t_sol))))
	{
		ft_putstr("-1 -1\n");
		return ;
	}
	s->h = -1;
	s->w = -1;
	s->d = map->h + map->w;
	ft_play(map, s);
	ft_putnbr(s->h);
	ft_putchar(' ');
	ft_putnbr(s->w);
	ft_putchar('\n');
	free(s);
}

void		ft_read_map(t_map *map)
{
	char	*s;
	int		i;

	if (!(map->m = (char **)ft_memalloc(sizeof(char *) * (map->h + 1))))
		return ;
	i = 0;
	if (!(get_next_line(0, &s)))
	{
		free(map->m);
		return ;
	}
	free(s);
	ft_read_map_part_two(map, s, i);
}

void		ft_read_piece(t_map *map)
{
	char	*s;
	int		i;

	if (!(map->p = (char **)ft_memalloc(sizeof(char *) * (map->ph + 1))))
		return ;
	i = 0;
	while (i < map->ph)
	{
		get_next_line(0, &s);
		if (!(map->p[i] = ft_strdup(s)))
			break ;
		free(s);
		i++;
	}
	if (i != map->ph)
	{
		free(s);
		ft_free_arr(map->p);
	}
}

void		ft_read(t_map *map, char **a)
{
	char	*s;

	while (get_next_line(0, &s))
	{
		if (ft_strncmp(s, "Plateau", 7) == 0)
		{
			a = ft_strsplit(s, ' ');
			if (!(a[1]) || !(a[2]))
			{
				ft_free_arr(a);
				return ;
			}
			map->h = ft_atoi(a[1]);
			map->w = ft_atoi(a[2]);
			ft_read_map(map);
			ft_free_arr(a);
		}
		ft_read_second_part(map, s, a);
		free(s);
	}
	free(s);
}

int			main(void)
{
	t_map	map;
	char	*s;
	int		i;
	char	**a;

	i = 0;
	a = NULL;
	if (!(get_next_line(0, &s)))
		return (0);
	if (ft_strlen(s) < 11)
		return (0);
	if (ft_player(&map, s) == 0)
		return (0);
	free(s);
	ft_read(&map, a);
	return (1);
}
