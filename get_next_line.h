/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktabe <ktabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:04:24 by ktabe             #+#    #+#             */
/*   Updated: 2020/07/16 18:36:48 by ktabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 1024
# define END 0
# define TRUE 1
# define FALSE -1
# define NOT_FOUND -1

int		get_next_line(int const fd, char **line);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
