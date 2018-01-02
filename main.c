/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:11:22 by acolas            #+#    #+#             */
/*   Updated: 2017/12/06 19:18:45 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/inc/libft.h"

int		main(int ac, char **av)
{
	char	*line;
	FILE	*fp;
	int		i;

	i = 0;
	fp = fopen("result.txt", "w+"); 
	get_next_line(0, &line);
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
