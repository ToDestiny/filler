/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:50:32 by acolas            #+#    #+#             */
/*   Updated: 2019/01/09 19:31:25 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	error(t_filler	*filler)
{
	int		i;
	
	i = 0;
	if (!filler->map)
		while (filler->map[i] != '\0')
		{
			free(filler->map[i]);
			i++;
		}
	if (!filler->piece)
		while (filler->piece[i] != '\0')
		{
			free(filler->piece[i]);
			i++;
		}

	free(filler->piece);
	free(filler->map);	

	exit(0);
	//free map
	//	while
	//free piece
	//	while
}
