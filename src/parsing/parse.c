/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:54:28 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 15:27:53 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse_player(t_data *data)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (data->map_path[y])
	{
		x = 0;
		while (data->map_path[y][x])
		{
			if (data->map_path[y][x] == 'N' || data->map_path[y][x] == 'S' 
			|| data->map_path[y][x] == 'W' || data->map_path[y][x] == 'E')
			{
				count++;
				data->x_pos = x;
				data->y_pos = y;
				data->player = data->map_path[y][x];
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		ft_error("player_not_valid");
}

void	final_pars_map(char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'N'
			&& map[x][y] != 'S' && map[x][y] != 'W' && map[x][y] != 'E'
			&& map[x][y] != '5')
				ft_error("map_not_valid");
			if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' 
			|| map[x][y] == 'W' || map[x][y] == 'E')
			{
				if (map[x][y + 1] == '5' || map[x][y - 1] == '5' 
				|| map[x + 1][y] == '5' || map[x - 1][y] == '5')
					ft_error("map_not_valid");
			}
			y++;
		}
		x++;
	}
}

void	ft_inisialize(t_data *data)
{
	data->map_array = NULL;
	data->map_path = NULL;
	data->n_path = NULL;
	data->s_path = NULL;
	data->w_path = NULL;
	data->e_path = NULL;
	data->f_color = 0;
	data->c_color = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->x_pos = 0;
	data->y_pos = 0;
	data->player = 0;
}

void	ft_parsing_part(char *map, t_data *data)
{
	char	*line;
	int		fd;

	ft_inisialize(data);
	fd = open(map, O_RDWR, 0777);
	check_name(map);
	if (fd < 0)
		ft_error("file_not_found");
	line = get_next_line(fd);
	while (line)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	ft_parsing(int ac, char *map, t_data *data)
{
	if (ac != 2)
		ft_error("Error : invalid number of arguments");
	if (HEIGHT <= 0 || WIDTH <= 0)
		ft_error("Error : invalid resolution");
	ft_parsing_part(map, data);
	ft_fill_array(data, map);
	ft_get_width(data);
	get_path(data);
	if (check_path(data))
		return (1);
	allocate_map(data);
	check_map(data);
	parse_player(data);
	final_pars_map(data->map_path);
	ft_get_height(data);
	return (0);
}
