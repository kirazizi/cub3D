/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:12:20 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 15:44:16 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	ft_get_color(char *path)
{
	char	**new_path;
	char	*tmp;
	int		comma;
	int		i;

	new_path = NULL;
	i = 0;
	comma = ft_count_comma(path);
	new_path = ft_split(path, ',');
	while (new_path[i])
	{
		tmp = new_path[i];
		new_path[i] = ft_strtrim(new_path[i], " ");
		free(tmp);
		if (atoi(new_path[i]) > 255 || atoi(new_path[i]) < 0
			|| is_digit(new_path[i]) || comma != 2)
			ft_error("color_not_valid");
		i++;
	}
	i = get_rgba(atoi(new_path[0]), atoi(new_path[1]), atoi(new_path[2]), 255);
	free_resource(new_path);
	free(path);
	return (i);
}

char	*ft_get_path(char *path)
{
	char	*new_path;
	char	*tmp_path;
	int		i;

	i = 0;
	new_path = NULL;
	tmp_path = path;
	path = ft_strtrim(tmp_path, " ");
	free(tmp_path);
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == 'p' && path[i + 2] == 'n' 
			&& path[i + 3] == 'g' && path[i + 4] == '\0')
		{
			new_path = ft_strndup(path, i +4);
			free(path);
			return (new_path);
		}
		i++;
	}
	free(path);
	return (new_path);
}

void	check_name(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'b' || map[len - 2] != 'u' 
		|| map[len - 3] != 'c' || map[len - 4] != '.')
		ft_error("path_not_valid");
}

void	check_map(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (data->map_path[len])
	{
		while (data->map_path[0][i])
		{
			if (data->map_path[0][i] != '1' && data->map_path[0][i] != '5' 
				&& data->map_path[0][i] != ' ' && data->map_path[0][i] != '\t')
				ft_error("map_not_valid");
			i++;
		}
		len++;
	}
	i = 0;
	while (data->map_path[len -1][i])
	{
		if (data->map_path[len -1][i] != '1' 
			&& data->map_path[len -1][i] != '5')
			ft_error("map_not_valid");
		i++;
	}
}
