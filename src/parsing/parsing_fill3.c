/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:39:18 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 16:18:16 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	replace_empty(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_path[i])
	{
		j = 0;
		while (data->map_path[i][j])
		{
			if (data->map_path[i][j] == ' ' || data->map_path[i][j] == '\t')
				data->map_path[i][j] = '5';
			j++;
		}
		i++;
	}
}

void	allocate_map_part(t_data *data, size_t i, int j)
{
	while (data->map_array[i])
	{
		if (ft_strncmp(data->map_array[i], "1", 1) == 0 
			|| ft_strncmp(data->map_array[i], " ", 1) == 0
			|| ft_strchr(data->map_array[i], '\t') != 0)
		{
			while (i < data->map_height)
			{
				data->map_path[j] = malloc(sizeof(char) *(data->map_width + 1));
				if (!data->map_path[j])
					ft_error("malloc_error");
				ft_strcpy(data->map_path[j], data->map_array[i]);
				if (strlen(data->map_path[j]) < data->map_width)
					ft_fill_space(data->map_path[j], data->map_width);
				if (data->map_array[i][0] == '\0')
					break ;
				i++;
				j++;
			}
			data->map_path[j] = NULL;
			break ;
		}
		i++;
	}
}

void	allocate_map(t_data *data)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (data->map_path != NULL)
		return ;
	data->map_path = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_path)
		ft_error("malloc_error");
	allocate_map_part(data, i, j);
	replace_empty(data);
}

void	get_path_part(t_data *data, int i)
{
	get_path_res(data, i);
	if (ft_strncmp(data->map_array[i], "1", 1) == 0 
		|| ft_strncmp(data->map_array[i], " ", 1) == 0)
		allocate_map(data);
	if (ft_strncmp(data->map_array[i], "1", 1) != 0
		&& ft_strncmp(data->map_array[i], "NO", 2) != 0
		&& ft_strncmp(data->map_array[i], "SO", 2) != 0
		&& ft_strncmp(data->map_array[i], "WE", 2) != 0
		&& ft_strncmp(data->map_array[i], "EA", 2) != 0
		&& ft_strncmp(data->map_array[i], "F", 1) != 0
		&& ft_strncmp(data->map_array[i], "C", 1) != 0
		&& ft_strncmp(data->map_array[i], "", 1) != 0
		&& ft_strncmp(data->map_array[i], " ", 1) != 0
		&& ft_strchr(data->map_array[i], '\t') == 0)
		ft_error("config_not_valid");
}

void	get_path(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->map_array[i])
	{
		get_path_part(data, i);
		i++;
	}
	if (!data->n_path || !data->s_path || !data->w_path || !data->e_path 
		|| !data->f_color || !data->c_color || !data->map_path)
		ft_error("config_not_valid");
	tmp = data->n_path;
	data->n_path = ft_strtrim(data->n_path, " ");
	free(tmp);
	tmp = data->s_path;
	data->s_path = ft_strtrim(data->s_path, " ");
	free(tmp);
	tmp = data->w_path;
	data->w_path = ft_strtrim(data->w_path, " ");
	free(tmp);
	tmp = data->e_path;
	data->e_path = ft_strtrim(data->e_path, " ");
	free(tmp);
}
