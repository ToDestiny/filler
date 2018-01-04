/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2018/01/03 17:57:18 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/inc/libft.h"
#include "inc/filler.h"
#include "getnbr.c"
int		main(int ac, char **av)
{
	t_filler	info;
	char		*line;
	FILE		*ret1;
	FILE		*ply;
	FILE		*result;
	FILE		*plt;
	FILE		*infplt;
	FILE		*infplt2;
	int		i;
	int		*plateau;

	i = 0;
	ret1 = fopen("ret1.txt", "w+"); 
	ply = fopen("player.txt", "w+"); 
	result = fopen("result.txt", "w+"); 
	plt = fopen("plateau.txt", "w+"); 
	infplt = fopen("infoplt.txt", "w+"); 
	infplt2 = fopen("infoplt2.txt", "w+"); 
	get_next_line(0, &line);
	fprintf(ret1, "%s\n", line);
	if (!ft_strstr(line, "p1"))
		fprintf(ply, "p2");
	else
		fprintf(ply, "p1");
	get_next_line(0, &line);
	fprintf(plt, "%s\n", line);
	plateau = getint(line);
	info.plt = plateau;
	fprintf(infplt, "%d\n", info.plt[0]);
	fprintf(infplt2, "%d\n", info.plt[1]);
//	fprintf(fp3, "p1=%d\n", ft_memcmp("p1", line, 42));
//	fprintf(fp4, "p2=%d\n", ft_memcmp(line, "p2", 42));
//	if (ac < 1)
//	{
//		ft_putstr("usage : ./filler_vm -f ...*\n");
//		return (0);
//	}
	while (i < 50)
	{
		get_next_line(0, &line);
		i++;
		fprintf(result, "%s\n", line);
	}
	return (0);
}
