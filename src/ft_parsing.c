/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:33:07 by acolas            #+#    #+#             */
/*   Updated: 2019/01/12 17:54:05 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
static void		ft_parsing_map(t_filler *filler)
{
	int		i;
	char	*line;
	
	i = 0;
	if (!(filler->map = ft_memalloc((filler->h_map + 1) * sizeof(char *))))
		error(filler); //TODO later..
	if (get_next_line(0, &line) < 1)
		error(filler);
	free(line);
	while (i < filler->h_map)
	{
		if (get_next_line(0, &line) < 1)
			error(filler);
		filler->map[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
}

static void		ft_parsing_piece(t_filler *filler)
{
	int		i;
	
	i = 0;
	if (!(filler->piece = ft_memalloc((filler->h_piece + 1) * sizeof(char *))))
		error(filler);
	while (i++ < filler->h_piece)
	{
		if (get_next_line(0, &filler->piece[i]) < 1)
			error(filler);
	}
}


static void		ft_piece(t_filler *filler)
{
	char	*line;
	char	**res;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 1)
		error(filler);
	res = ft_strsplit(line, ' ');
	filler->h_piece = ft_atoi(res[1]);
	filler->w_piece = ft_atoi(res[2]);
	free(line);
	while (i++ < 3)
		free(res[i]);
	free(res);
}
static void		ft_map(t_filler *filler)
{
	char	*line;
	char	**res;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 1)
		error(filler);
	res = ft_strsplit(line, ' ');
	filler->h_map = ft_atoi(res[1]);
	filler->w_map = ft_atoi(res[2]);
	free(line);
	while (i++ < 3)
		free(res[i]);
	free(res);
}

void		ft_parsing(t_filler	*filler)
{
	ft_map(filler);
	ft_parsing_map(filler);
	ft_piece(filler);
	ft_parsing_piece(filler);
}
