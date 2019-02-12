/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/02/12 16:41:31 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_solution(t_map *map)
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
	/*
	if (s->h == -1)
		return ;
	*/
	free(s);
}

void	ft_read_map(t_map *map)
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
	while (i < map->h)
	{
		get_next_line(0, &s);
		if (!(map->m[i] = (char *)ft_memalloc(sizeof(char) * (map->w + 1))))
			break ;
		if (ft_strchr(s, ' ') == 0)
			break ;
		else
			ft_strcpy(map->m[i], ft_strchr(s, ' ') + 1);
		free(s);
		i++;
	}
	if (i != map->h)
	{
		free(s);
		ft_free_arr(map->m);
	}
}

void	ft_read_piece(t_map *map)
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

static void ft_read_second_part(t_map *map, char *s, char **a)
{
	if (ft_strncmp(s, "Piece", 5) == 0)
	{
		a = ft_strsplit(s, ' ');
		if (!(a[1]) || !(a[2]))
		{
			ft_free_arr(a);
			return ;
		}
		map->ph = ft_atoi(a[1]);
		map->pw = ft_atoi(a[2]);
		ft_read_piece(map);
		ft_find_solution(map);
		ft_free_arr(map->p);
		map->p = NULL;
		ft_free_arr(map->m);
		map->m = NULL;
		ft_free_arr(a);
	}
}

void	ft_read(t_map *map, char *s, char **a)
{
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

int		main(void)
{
	t_map	map;
	char	*s;
	int		i;
	char	*t;
	char	**a;

	i = 0;
	t = NULL;
	a = NULL;
	if (!(get_next_line(0, &s)))
		return (0);
	if (ft_strlen(s) < 11)
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
	ft_read(&map, t, a);
	return (1);
}
