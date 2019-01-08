/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:20:16 by acolas            #+#    #+#             */
/*   Updated: 2019/01/08 15:55:51 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_player(t_filler *filler)
{
	int		ret;
	char	*line;
	
	ret = get_next_line(0, &line);
	filler->player = ft_atoi(&line[10]);
}

void		ft_letter(t_filler *filler)
{
	if (filler->player == '1')
		filler->letter = 'O';
	else
		filler->letter = 'X';
}

void		ft_map(t_filler *filler)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	filler->height = ft_atoi(&line[8]);
	filler->width = ft_atoi(&line[11]);
}

void		ft_get_info(t_filler *filler)
{
	ft_player(filler);
	ft_letter(filler);
	ft_map(filler);
}
