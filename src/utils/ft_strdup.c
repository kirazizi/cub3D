/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:58:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/25 16:18:27 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*ft_strncpy(char *s1, char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < len)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	ft_strncpy(result, s, len);
	result[len] = '\0';
	return (result);
}
