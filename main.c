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

int		main(int ac, char **av)
{
	char	*line;
	FILE	*fp;
	FILE	*fp2;
	FILE	*fp3;
	FILE	*fp4;
	int		i;

	i = 0;
	fp = fopen("result.txt", "w+"); 
	fp2 = fopen("result2.txt", "w+"); 
	fp3 = fopen("result3.txt", "w+"); 
	fp4 = fopen("result4.txt", "w+"); 
	get_next_line(0, &line);
	fprintf(fp, "%s\n", line);
	if (!ft_strstr(line, "p1"))
		fprintf(fp2, "p2");
	else
		fprintf(fp2, "p1");
//	fprintf(fp3, "p1=%d\n", ft_memcmp("p1", line, 42));
//	fprintf(fp4, "p2=%d\n", ft_memcmp(line, "p2", 42));
	if (ac < 1)
	{
		ft_putstr("usage : ./filler_vm -f ...*\n");
		return (0);
	}
	while (i < 50)
	{
		get_next_line(0, &line);
		i++;
		fprintf(fp, "%s\n", line);
	}
	return (0);
}
