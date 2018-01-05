/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:53:21 by phanna            #+#    #+#             */
/*   Updated: 2018/01/05 15:53:36 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/filler.h"

int	get_nb_intt(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret++;
			while ((str[i] >= '0' && str[i] <= '9') && str[i])
				i++;
		}
		else
			i++;
	}
	return (ret);
}

int	*getintt(char *str)
{
	int	*ret;
	int	nb;
	int	i;
	int	j;
	FILE	*int1;

	int1 = fopen("int1.txt", "w+");
	i = 0;
	j = 0;
	nb = get_nb_intt(str);
	ret = malloc(sizeof(int) * nb);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret[j] = ft_atoi(str + i);
			fprintf(int1, "%d\n", ret[i]);
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			j++;
		}
		else
			i++;
	}
	return (ret);
}
