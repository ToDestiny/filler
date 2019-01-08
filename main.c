/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2019/01/08 15:58:26 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

static void		init_struct(t_filler *filler)
{
	filler->player = 0;
	filler->width = 0;
	filler->height = 0;
	filler->letter = 0;
}

int				main(void)
{
	t_filler	filler;

	init_struct(&filler);
	ft_get_info(&filler);
	while(1)
	{
		break;	
	}	
	//map = ft_map();

	return (0);
}
