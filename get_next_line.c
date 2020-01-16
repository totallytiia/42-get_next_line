/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:13:39 by tlaukkan          #+#    #+#             */
/*   Updated: 2019/12/05 17:39:14 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_line(const int fd, char **line, char **cline)
{
	char	*tmp;
	int		i;

	i = 0;
	while (cline[fd][i] != '\n' && cline[fd][i] != '\0')
		i++;
	if (cline[fd][i] == '\n')
	{
		*line = ft_strsub(cline[fd], 0, i);
		tmp = ft_strdup(cline[fd] + i + 1);
		free(cline[fd]);
		cline[fd] = tmp;
		if (cline[fd][0] == '\0')
			ft_strdel(&cline[fd]);
	}
	else if (cline[fd][i] == '\0')
	{
		*line = ft_strdup(cline[fd]);
		ft_strdel(&cline[fd]);
	}
	return (1);
}

static int	result(const int fd, int ret, char **line, char **cline)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && cline[fd] == NULL)
		return (0);
	else
		return (copy_line(fd, line, cline));
}

int			get_next_line(const int fd, char **line)
{
	static char		*cline[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	char			*curr;
	int				ret;

	if (line == NULL || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (cline[fd] == NULL)
			cline[fd] = ft_strnew(1);
		buf[ret] = '\0';
		curr = ft_strjoin(cline[fd], buf);
		free(cline[fd]);
		cline[fd] = curr;
		if (ft_strchr(cline[fd], '\n'))
			break ;
	}
	return (result(fd, ret, line, cline));
}
