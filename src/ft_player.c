/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:20:16 by acolas            #+#    #+#             */
/*   Updated: 2019/01/09 15:45:22 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_player(t_filler *filler)
{
	char	*line;
	
	if (get_next_line(0, &line) < 1)
		error(filler);
	filler->player = ft_atoi(&line[10]);
	free(line);
}

void		ft_letter(t_filler *filler)
{
	if (filler->player == 1)
	{
		filler->me = 'O';
		filler->op = 'X';
	}
	else
	{
		filler->me = 'X';
		filler->op = 'O';
	}
}

void		ft_get_info(t_filler *filler)
{
	ft_player(filler);
	ft_letter(filler);
}
