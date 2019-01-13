/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/01/13 19:16:03 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init_struct(t_filler *filler)
{
	filler->player = 0;
	filler->w_map = 0;
	filler->h_map = 0;
	filler->w_piece = 0;
	filler->h_piece = 0;
	filler->me = 0;
	filler->op = 0;
	filler->map = NULL;
	filler->piece = NULL;
	filler->p1_x = 0;
	filler->p1_y = 0;
	filler->p2_x = 0;
	filler->p2_y = 0;
}

int				main(void)
{
	t_filler	filler;

	init_struct(&filler);
	ft_player(&filler);
	while(1)
	{
		ft_parsing(&filler);
		ft_algo(&filler);
		break;
	}
//	for (int i= 0; i < filler.h_map; i++)
//		printf("%s\n", filler.map[i]);
	return (0);
}
