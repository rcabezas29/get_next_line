/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:57:40 by rcabezas          #+#    #+#             */
/*   Updated: 2019/12/18 17:45:58 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	p = dst;
	q = src;
	if ((int)p == '\0' && (int)q == '\0')
		return (dst);
	else
	{
		while (n--)
			*p++ = *q++;
		return (dst);
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s1) + 1;
	new = (char *)malloc(len);
	if (new == 0)
		return (0);
	ft_memcpy(new, s1, len);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;
	char			*p;

	i = 0;
	p = (char *)str;
	ch = c + '\0';
	while (p[i] != '\0')
	{
		if (p[i] == ch)
			return (p + i);
		i++;
	}
	if (ch == '\0')
		return (p + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = start;
	j = 0;
	a = (char *)malloc(len + 1);
	if (!a)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (j < len)
	{
		a[j] = s[i];
		i++;
		j++;
	}
	a[j] = '\0';
	return (a);
}
