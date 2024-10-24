/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:44:34 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/24 13:22:48 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < n)
		i++;
	while (src[j] && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dst[i] = '\0';
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		len;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, len + 1);
	free(s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
