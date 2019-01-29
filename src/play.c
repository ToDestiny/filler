/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:12:29 by acolas            #+#    #+#             */
/*   Updated: 2019/01/29 15:12:43 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_count_dist(t_map *map, int i, int j)
{
	int	k;
	int l;
	int	d;
	int	t;

	k = 0;
	d = 1000;
	while (k < map->h)
	{
		l = 0;
		while (l < map->w)
		{
			if (map->m[k][l] == map->oc || map->m[k][l] == map->oc + 32)
			{
				t = DIST(i, j, k, l);
				if (t <= d)
					d = t;
			}
			l++;
		}
		k++;
	}
	return (d);
}

int		ft_get_small_dist(t_map *map, int i, int j)
{
	int	k;
	int l;
	int	d;
	int	t;

	k = 0;
	d = map->h + map->w;
	while (k < map->ph)
	{
		l = 0;
		while (l < map->pw)
		{
			if (map->p[k][l] == '*')
			{
				t = ft_count_dist(map, i + k, j + l);
				if (t <= d)
					d = t;
			}
			l++;
		}
		k++;
	}
	return (d);
}

void	ft_try_sol(t_map *map, int i, int j, t_sol *s)
{
	int	t;

	t = ft_get_small_dist(map, i, j);
	if (t < s->d)
	{
		s->h = i;
		s->w = j;
		s->d = t;
	}
}

int		ft_valid(t_map *map, int i, int j)
{
	int	k;
	int l;
	int	c;

	k = 0;
	c = 0;
	while (k < map->ph)
	{
		l = 0;
		while (l < map->pw)
		{
			if (l + j >= map->w || k + i >= map->h)
				return (0);
			if (map->p[k][l] == '*' && map->m[i + k][j + l] == map->pc)
				c++;
			else if (map->p[k][l] == '*' && map->m[i + k][j + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	if (c == 1)
		return (1);
	return (0);
}

void	ft_play(t_map *map, t_sol *s)
{
	int	i;
	int j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (ft_valid(map, i, j))
				ft_try_sol(map, i, j, s);
			j++;
		}
		i++;
	}
}
