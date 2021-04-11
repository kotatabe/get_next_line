/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktabe <ktabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:06:43 by ktabe             #+#    #+#             */
/*   Updated: 2020/07/16 18:38:45 by ktabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free((void *)s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen((char *)s) <= (size_t)start || len == 0)
		return (ft_strdup(""));
	while (i++ < start)
		s++;
	ptr = (char *)s;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (j < len)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
