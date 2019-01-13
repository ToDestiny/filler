/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:01:38 by acolas            #+#    #+#             */
/*   Updated: 2019/01/13 19:15:55 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_init_players(t_filler *filler)
{
	int		x;
	char	*y;

	x = filler->h_map;
	y = 0;
	while (filler->map[x--])
	{
		if (ft_strstr(filler->map[x], "o"))
			{
				filler->p1_x = x;
				filler->p1_y = ft_atoi(y);
			}
		else (ft_strstr(filler->map[x], "x"))
			{
				filler->p2_x = x;
				filler->p2_y = ft_atoi(y);
			}
	}
}

void			ft_algo(t_filler *filler)
{
	ft_init_players(filler);
	//ft_check_map(&filler);
	printf("p1_x = %d\n", filler->p1_x);
	printf("p1_y = %d\n", filler->p1_y);
	printf("p2_x = %d\n", filler->p2_x);
	printf("p2_y = %d\n", filler->p2_y);
}
