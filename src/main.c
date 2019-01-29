/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/01/29 15:12:22 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_solution(t_map *map)
{
	t_sol	*s;

	s = (t_sol*)ft_memalloc(sizeof(t_sol));
	s->h = -1;
	s->w = -1;
	s->d = map->h + map->w;
	ft_play(map, s);
	ft_putnbr(s->h);
	ft_putchar(' ');
	ft_putnbr(s->w);
	ft_putchar('\n');
	if (s->h == -1)
		exit(0);
}

void	ft_read_map(t_map *map)
{
	char	*s;
	int		i;

	map->m = (char**)ft_memalloc(sizeof(char *) * map->h);
	i = 0;
	get_next_line(0, &s);
	while (i < map->h)
	{
		get_next_line(0, &s);
		map->m[i] = (char *)ft_memalloc(sizeof(char) * map->w);
		ft_strcpy(map->m[i], ft_strchr(s, ' ') + 1);
		free(s);
		i++;
	}
}

void	ft_read_piece(t_map *map)
{
	char	*s;
	int		i;

	map->p = (char **)ft_memalloc(sizeof(char *) * map->ph);
	i = 0;
	while (i < map->ph)
	{
		get_next_line(0, &s);
		map->p[i] = ft_strdup(s);
		free(s);
		i++;
	}
}

void	ft_read(t_map *map)
{
	char	*s;
	char	**a;

	while (get_next_line(0, &s) > -1)
	{
		if (ft_strncmp(s, "Plateau", 7) == 0)
		{
			a = ft_strsplit(s, ' ');
			map->h = ft_atoi(a[1]);
			map->w = ft_atoi(a[2]);
			ft_read_map(map);
			ft_free_arr(a);
		}
		if (ft_strncmp(s, "Piece", 5) == 0)
		{
			a = ft_strsplit(s, ' ');
			map->ph = ft_atoi(a[1]);
			map->pw = ft_atoi(a[2]);
			ft_read_piece(map);
			ft_find_solution(map);
			ft_free_arr(a);
		}
		free(s);
	}
}

int		main(void)
{
	t_map	*map;
	char	*s;

	get_next_line(0, &s);
	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (s[10] == '1')
	{
		map->pc = 'O';
		map->oc = 'X';
	}
	else if (s[10] == '2')
	{
		map->pc = 'X';
		map->oc = 'O';
	}
	free(s);
	ft_read(map);
	return (1);
}
