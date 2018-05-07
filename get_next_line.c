/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 22:15:18 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/20 11:05:07 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cnt_words(const char *s, char c)
{
	int	ctr;
	int i;

	i = 0;
	ctr = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			ctr++;
		i++;
	}
	return (ctr);
}

int			read2buff(int fd, t_line **list)
{
	int		i;
	int		ctr;

	i = 0;
	ctr = 0;
	while ((ctr = read(fd, &list[fd]->tmp[list[fd]->bytes], BUFF_SIZE)) > 0)
	{
		list[fd]->bytes += ctr;
		i++;
	}
	return (i);
}

static int	init_vars(t_line **list, int fd)
{
	if (!(list[fd] = malloc(sizeof(t_line))))
		return (0);
	list[fd]->ctr = 0;
	list[fd]->init = -1;
	list[fd]->bytes = 0;
	ft_bzero(list[fd]->tmp, 1000000);
	if (!read2buff(fd, list))
		return (-1);
	list[fd]->wrd_ct = cnt_words(list[fd]->tmp, '\n');
	list[fd]->answer = ft_strsplit(list[fd]->tmp, '\n');
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_line *list[9000];

	if (fd < 0 || fd > 8999 || !line)
		return (-1);
	if (!list[fd])
		if (init_vars(list, fd) != 1)
			return (-1);
	if (list[fd]->tmp[list[fd]->ctr] == '\n')
	{
		list[fd]->ctr++;
		line[0] = ft_strnew(0);
		return (1);
	}
	list[fd]->init++;
	if (list[fd]->init == list[fd]->wrd_ct || list[fd]->tmp[list[fd]->ctr] == 0)
	{
		ft_memdel((void**)&list);
		line[0] = ft_strnew(0);
		return (0);
	}
	line[0] = list[fd]->answer[list[fd]->init];
	list[fd]->ctr += ft_strlen(list[fd]->answer[list[fd]->init]) + 1;
	return (1);
}
