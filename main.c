/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2018/01/05 20:56:34 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/filler.h"

int		main(int ac, char **av)
{



	FILE		*ply;
	FILE		*result;
	FILE		*infpltx;
	FILE		*infplty;
	
	ply = fopen("player.txt", "w+"); 
	result = fopen("result.txt", "w+"); 
	infpltx = fopen("infopltx.txt", "w+"); 
	infplty = fopen("infoplty.txt", "w+"); 



	t_filler	info;
	char		*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ft_atoi(line + 10) == 1 ? info.ply = 'O' : (info.ply = 'X');
	get_next_line(0, &line);
	info.plty = ft_atoi(line + 8);
	info.pltx = ft_atoi(line + 11);
	fprintf(ply, "%c\n", info.ply);
	fprintf(infpltx, "%d\n", info.pltx);
	fprintf(infplty, "%d\n", info.plty);
	while (i++ <= info.plty)
	{
		get_next_line(0, &line);
		fprintf(result, "%s\n", line);
	}
	return (0);
}
