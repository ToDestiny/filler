/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/02/04 23:55:05 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_solution(t_map *map)
{
	t_sol	*s;

	if (!(s = (t_sol*)ft_memalloc(sizeof(t_sol))))
		exit(0);
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
	free(s);
}

void	ft_read_map(t_map *map)
{
	char	*s;
	int		i;
	
	map->m = (char **)ft_memalloc(sizeof(char *) * (map->h + 1));
	if (!(map->m))
		exit (0);
	i = 0;
	get_next_line(0, &s);
	free(s);
	while (i < map->h)
	{
		get_next_line(0, &s);
		if (!(map->m[i] = (char *)ft_memalloc(sizeof(char) * (map->w + 1))))
			exit (0);
		if (ft_strchr(s, ' ') == 0)
			exit (0);
		else
			ft_strcpy(map->m[i], ft_strchr(s, ' ') + 1);
		free(s);
		i++;
	}
}

void	ft_read_piece(t_map *map)
{
	char	*s;
	int		i;

	if (!(map->p = (char **)ft_memalloc(sizeof(char *) * (map->ph + 1))))
		exit (0);
	i = 0;
	while (i < map->ph)
	{
		get_next_line(0, &s);
		if (!(map->p[i] = ft_strdup(s)))
				exit (0);
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
			if (!(a[1]) || !(a[2]))
				exit(0);
			map->h = ft_atoi(a[1]);
			map->w = ft_atoi(a[2]);
			ft_read_map(map);
			ft_free_arr(a);
		}
		if (ft_strncmp(s, "Piece", 5) == 0)
		{
			a = ft_strsplit(s, ' ');
			if (!(a[1]) || !(a[2]))
				exit (0);
			map->ph = ft_atoi(a[1]);
			map->pw = ft_atoi(a[2]);
			ft_read_piece(map);
			ft_find_solution(map);
			ft_free_arr(map->p);
			ft_free_arr(map->m);
			ft_free_arr(a);
		}
		free(s);
	}
}

int		main(void)
{
	t_map	map;
	char	*s;
	int		i;

	i = 0;
	get_next_line(0, &s);
	if (strlen(s) < 11)
		return (0);
	if (s[10] == '1')
	{
		map.pc = 'O';
		map.oc = 'X';
	}
	else if (s[10] == '2')
	{
		map.pc = 'X';
		map.oc = 'O';
	}
	free(s);
	ft_read(&map);
	return (1);
}
