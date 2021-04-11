/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:25:50 by ktabe             #+#    #+#             */
/*   Updated: 2020/08/27 21:44:16 by kotatabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	index_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

int	free_false(char *buf, char *save)
{
	free(buf);
	free(save);
	return (FALSE);
}

int	read_line(int fd, char **save, int *index)
{
	int			ret;
	char		*buf;
	char		*tmp;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (FALSE);
	if (!*save)
	{
		if (!(*save = ft_strdup("")))
		{
			free(buf);
			return (FALSE);
		}
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin_free(*save, buf)))
			free_false(buf, *save);
		*save = tmp;
		if ((*index = index_nl(*save)) != NOT_FOUND)
			break ;
	}
	free(buf);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	int			index;
	char		*tmp;
	static char	*save[MAX_FD + 1];

	if (fd < 0 || MAX_FD < fd)
		return (FALSE);
	ret = read_line(fd, &save[fd], &index);
	if (ret == END)
		index = index_nl(save[fd]);
	if (ret == END && index == NOT_FOUND)
	{
		*line = ft_strdup(save[fd]);
		free(save[fd]);
		save[fd] = NULL;
		return (*line ? END : FALSE);
	}
	*line = ft_substr(save[fd], 0, index);
	tmp = ft_strdup(save[fd] + index + 1);
	free(save[fd]);
	save[fd] = tmp;
	return (TRUE);
}
