/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:37:32 by phanna            #+#    #+#             */
/*   Updated: 2017/09/25 09:38:09 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	s;
	unsigned char	*tmp;

	i = 0;
	s = (unsigned char)c;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = s;
		i++;
	}
	b = (void*)tmp;
	return (b);
}
