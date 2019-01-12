/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:20:16 by acolas            #+#    #+#             */
/*   Updated: 2019/01/12 17:54:02 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_player(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) < 1)
		error(filler);
	if (ft_strstr(line, "p1"))
	{
		filler->player = 1;
		filler->me = 'O';
		filler->op = 'X';
	}
	else
	{
		filler->player = 2;
		filler->me = 'X';
		filler->op = 'O';
	}
	if (filler->player != 1 && filler->player != 2)
		error(filler);
	free(line);
}
