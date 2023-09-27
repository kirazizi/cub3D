/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:35:44 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/27 13:51:56 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	mouse_move(t_data *data)
{
	static int	lock;

	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE) && lock == 0)
	{
		lock = 1;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE) && lock == 1)
	{
		lock = 0;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	}
	if (lock == 1)
	{
		mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_y);
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
		if (data->mouse_x > data->old_mouse_x)
		{
			data->player_data.rt_angle += 0.05;
		}
		else if (data->mouse_x < data->old_mouse_x)
		{
			data->player_data.rt_angle -= 0.05;
		}
	}
}

void	mini_player(t_data *data)
{
	size_t	mini_len;

	mini_len = 120;
	my_mlx_pixel_put(data->img, (mini_len / 2), (mini_len / 2), 0xFF0000FF);
	my_mlx_pixel_put(data->img, (mini_len / 2) + 1, (mini_len / 2), 0xFF0000FF);
	my_mlx_pixel_put(data->img, (mini_len / 2) - 1, (mini_len / 2), 0xFF0000FF);
	my_mlx_pixel_put(data->img, (mini_len / 2), (mini_len / 2) + 1, 0xFF0000FF);
	my_mlx_pixel_put(data->img, (mini_len / 2), (mini_len / 2) - 1, 0xFF0000FF);
}

void	mini_map_init(t_data *data)
{
	data->minimap.mini_len = 120;
	data->minimap.x = data->player_data.x - (data->minimap.mini_len / 2);
	data->minimap.y = data->player_data.y - (data->minimap.mini_len / 2);
	data->minimap.x_tmp = data->minimap.x;
	data->minimap.y_tmp = data->minimap.y;
	data->minimap.x_draw = 0;
	data->minimap.y_draw = 0;
}

void	mini_map(t_data *data)
{
	mini_map_init(data);
	while (data->minimap.y < (data->minimap.y_tmp + data->minimap.mini_len))
	{
		data->minimap.x_draw = 0;
		data->minimap.x = data->minimap.x_tmp;
		while (data->minimap.x < (data->minimap.x_tmp + data->minimap.mini_len))
		{
			if (data->map_path[(int)(data->minimap.y / GRID)]
				[(int)(data->minimap.x / GRID)] == '0')
				data->minimap.color = 0x00000000;
			else if (data->map_path[(int)(data->minimap.y / GRID)]
					[(int)(data->minimap.x / GRID)] == data->player)
				data->minimap.color = 0x00000000;
			else
				data->minimap.color = 0xFFFFFFFF;
			my_mlx_pixel_put(data->img, data->minimap.x_draw, 
				data->minimap.y_draw, data->minimap.color);
			data->minimap.x_draw++;
			data->minimap.x++;
		}
		data->minimap.y_draw++;
		data->minimap.y++;
	}
}

void	render_map(t_data *data)
{
	castrays(data);
	mini_map(data);
	mini_player(data);
	mouse_move(data);
}
