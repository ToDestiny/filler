/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:50:32 by acolas            #+#    #+#             */
/*   Updated: 2019/01/12 17:07:55 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	error(t_filler	*filler)
{
	int		i;
	
	i = 0;
	if (filler->map)
	{
		while (filler->map[i] != '\0')
		{
			free(filler->map[i]);
			i++;
		}
		free(filler->map);
	}
	if (filler->piece)
	{
		while (filler->piece[i] != '\0')
		{
			free(filler->piece[i]);
			i++;
		}
		free(filler->piece);
	}

	exit(0);
	//free map
	//	while
	//free piece
	//	while
}
