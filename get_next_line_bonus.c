/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:10:45 by rcabezas          #+#    #+#             */
/*   Updated: 2019/12/18 18:02:37 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		strdel(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static int		readline(char **a, char **line, int fd)
{
	int		len;
	char	*aux;

	len = 0;
	while (a[fd][len] != '\n')
		len++;
	*line = ft_substr(a[fd], 0, len);
	aux = ft_strdup(&a[fd][len + 1]);
	free(a[fd]);
	a[fd] = aux;
	return (1);
}

static int		output(char **a, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (a[fd] == NULL || a[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		strdel(&a[fd]);
		return (0);
	}
	else if (ft_strchr(a[fd], '\n'))
		return (readline(a, line, fd));
	else
	{
		*line = ft_strdup(a[fd]);
		strdel(&a[fd]);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	*a[4096];
	int			ret;
	char		*buff;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 ||
		(!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (a[fd] == NULL)
			a[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(a[fd], buff);
			free(a[fd]);
			a[fd] = tmp;
		}
		if (ft_strchr(a[fd], '\n'))
			break ;
	}
	free(buff);
	return (output(a, line, ret, fd));
}
