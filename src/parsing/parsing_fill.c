/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:07:16 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 16:01:43 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_fill_array(t_data *data, char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	data->map_array = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_array)
		ft_error("malloc_error");
	fd = open(map, O_RDWR, 0777);
	line = get_next_line(fd);
	while (line)
	{
		data->map_array[i] = ft_strdup_newline(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map_array[i] = NULL;
}

void	ft_fill_space(char *str, int width)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i < width)
	{
		str[i] = '5';
		i++;
	}
	str[i] = '\0';
}

void	ft_get_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_path[i])
		i++;
	data->map_height = i;
}

void	ft_get_width(t_data *data)
{
	size_t	max;
	int		i;
	int		j;

	max = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		if (ft_strncmp(data->map_array[i], "1", 1) == 0 
			|| ft_strncmp(data->map_array[i], " ", 1) == 0 
			|| ft_strchr(data->map_array[i], '\t') != 0)
		{
			while (data->map_array[i][j])
			{
				max = ft_strlen(data->map_array[i]);
				if (max > data->map_width)
					data->map_width = max;
				j++;
			}
		}
		i++;
	}
}

int	check_path(t_data *data)
{
	if (open(data->n_path, O_RDONLY) < 0)
		return (printf("north path not valid\n"), 1);
	if (open(data->s_path, O_RDONLY) < 0)
		return (printf("south path not valid\n"), 1);
	if (open(data->w_path, O_RDONLY) < 0)
		return (printf("west path not valid\n"), 1);
	if (open(data->e_path, O_RDONLY) < 0)
		return (printf("east path not valid\n"), 1);
	return (0);
}
