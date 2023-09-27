/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:23:40 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/22 06:53:55 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	ft_count_words(char *str, char separator)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = 0;
	tmp = 1;
	while (str[i])
	{
		if (str[i] == separator)
			tmp = 1;
		if (str[i] != separator && tmp)
		{
			tmp = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_get_word_lenght(char *str, char separator, int x)
{
	int	j;

	j = 0;
	while (str[x] && str[x] != separator)
	{
		x++;
		j++;
	}
	return (j);
}

static char	**free_all(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	*ft_get_next_word(char *str, char separator, int *i)
{
	int		index;
	char	*src;
	int		j;

	j = 0;
	index = *i;
	while (str[index] == separator)
		index++;
	src = malloc ((ft_get_word_lenght(str, separator, index) + 1)
			* sizeof(char));
	if (!src)
		return (NULL);
	while (str[index] && str[index] != separator)
	{
		src[j] = str[index];
		j++;
		index++;
	}
	src[j] = '\0';
	*i = index;
	return (src);
}

char	**ft_split(char const	*s, char c)
{
	int		i;
	char	**src;
	int		words;
	int		s_words;

	if (!s)
		return (NULL);
	i = 0;
	s_words = 0;
	words = ft_count_words((char *)s, c);
	src = malloc(sizeof(char *) * (words + 1));
	if (!src)
		return (NULL);
	while (s_words < words)
	{
		src[s_words] = ft_get_next_word((char *) s, c, &i);
		if (!src[s_words])
			return (free_all(src, s_words));
		s_words++;
	}
	src[s_words] = NULL;
	return (src);
}
