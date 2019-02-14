/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:50:11 by acolas            #+#    #+#             */
/*   Updated: 2019/02/14 13:06:16 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_map_part_two(t_map *map, char *s, int i)
{
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
		s = NULL;
		i++;
	}
	if (i != map->h)
	{
		free(s);
		s = NULL;
		ft_free_arr(map->m);
		map->m = NULL;
	}
}

void	ft_read_second_part(t_map *map, char *s, char **a)
{
	if (ft_strncmp(s, "Piece", 5) == 0)
	{
		a = ft_strsplit(s, ' ');
		if (!(a[1]) || !(a[2]))
		{
			ft_free_arr(a);
			a = NULL;
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

int		ft_player(t_map *map, char *s)
{
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
	else
	{
		free(s);
		s = NULL;
		return (0);
	}
	return (1);
}
