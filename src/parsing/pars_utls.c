/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:11:06 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/26 05:26:16 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*ft_strdup_newline(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (strlen(line) + 1));
	if (!str)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	get_path_res(t_data *data, int i)
{
	if (ft_strncmp(data->map_array[i], "NO", 2) == 0)
		data->n_path = ft_get_path(ft_strdup(&data->map_array[i][2]));
	if (ft_strncmp(data->map_array[i], "SO", 2) == 0)
		data->s_path = ft_get_path(ft_strdup(&data->map_array[i][2]));
	if (ft_strncmp(data->map_array[i], "WE", 2) == 0)
		data->w_path = ft_get_path(ft_strdup(&data->map_array[i][2]));
	if (ft_strncmp(data->map_array[i], "EA", 2) == 0)
		data->e_path = ft_get_path(ft_strdup(&data->map_array[i][2]));
	if (ft_strncmp(data->map_array[i], "F", 1) == 0)
		data->f_color = ft_get_color(ft_strdup(&data->map_array[i][1]));
	if (ft_strncmp(data->map_array[i], "C", 1) == 0)
		data->c_color = ft_get_color(ft_strdup(&data->map_array[i][1]));
}
