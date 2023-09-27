/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:24:29 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 16:12:59 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*s;
	size_t	k;

	i = 0;
	s = (char *)src;
	k = ft_strlen(s);
	if (dstsize == 0)
		return (k);
	while (s[i] && i < dstsize - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (k);
}

static size_t	ft_len(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			newlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	newlen = ft_len(s + start, len);
	sub = malloc((newlen + 1) * sizeof(char));
	if (sub != NULL)
		ft_strlcpy(sub, s + start, newlen + 1);
	sub[newlen] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*res;
	char	*ss1;
	char	*sset;

	i = 0;
	ss1 = (char *) s1;
	sset = (char *) set;
	if (ss1 && sset)
	{
		len = ft_strlen(ss1);
		while (ss1[i] && ft_strchr(sset, ss1[i]))
			i++;
		while (len > i && ft_strchr(sset, ss1[len - 1]))
			len--;
		res = ft_substr(ss1, i, len - i);
		return (res);
	}
	return (NULL);
}
