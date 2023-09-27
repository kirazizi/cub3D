/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:28:13 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/23 01:31:51 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	move_up(t_data *data, int keycode, double x_stp, double y_stp)
{
	if (keycode == UP && !wach_kayn_wall(data, 
			data->player_data.x + x_stp, data->player_data.y + y_stp))
	{
		data->player_data.x += x_stp;
		data->player_data.y += y_stp;
	}
}

void	move_down(t_data *data, int keycode, double x_stp, double y_stp)
{
	if (keycode == DOWN && !wach_kayn_wall(data, 
			data->player_data.x - x_stp, data->player_data.y - y_stp))
	{
		data->player_data.x -= x_stp;
		data->player_data.y -= y_stp;
	}
}

void	move_left(t_data *data, int keycode, double x_stp, double y_stp)
{
	if (keycode == LEFT && !wach_kayn_wall(data, 
			data->player_data.x + y_stp, data->player_data.y - x_stp))
	{
		data->player_data.x += y_stp;
		data->player_data.y -= x_stp;
	}
}

void	move_right(t_data *data, int keycode, double x_stp, double y_stp)
{
	if (keycode == RIGHT && !wach_kayn_wall(data, 
			data->player_data.x - y_stp, data->player_data.y + x_stp))
	{
		data->player_data.x -= y_stp;
		data->player_data.y += x_stp;
	}
}
