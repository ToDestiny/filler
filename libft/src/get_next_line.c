/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 04:14:32 by phanna            #+#    #+#             */
/*   Updated: 2017/10/23 13:29:37 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static t_list	*fd_select(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("", 1)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

char			*gnl_read(char **buff, int fd, char *str)
{
	int		ret;
	char	*tmp;
	char	buff_rd[BUFF_SIZE + 1];

	while ((ret = read(fd, buff_rd, BUFF_SIZE)))
	{
		buff_rd[ret] = '\0';
		tmp = *buff;
		if (!(*buff = ft_strjoin(*buff, buff_rd)))
			return (NULL);
		free(tmp);
		if ((str = ft_strchr(*buff, '\n')))
			return (str);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*box;
	char			*str;
	char			*tmp;

	if (!(box = fd_select(&list, fd)) || fd > FD_MAX || fd < 0
			|| !line || read(fd, box->content, 0) < 0)
		return (ERROR);
	str = ft_strchr(box->content, '\n');
	if (!str)
		str = gnl_read((char**)&box->content, fd, str);
	if (str)
	{
		*str = '\0';
		*line = ft_strdup(box->content);
		tmp = box->content;
		box->content = ft_strdup(str + 1);
		free(tmp);
		return (SUCCESS);
	}
	*line = ft_strdup(box->content);
	box->content = ft_strdup("\0");
	return ((**line) ? SUCCESS : 0);
}
