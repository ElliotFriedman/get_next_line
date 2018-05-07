/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 23:20:39 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/20 11:16:40 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 1000

typedef struct		s_line
{
	size_t			ctr;
	int				bytes;
	int				wrd_ct;
	int				init;
	char			tmp[1000000];
	char			**answer;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
