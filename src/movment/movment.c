/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:17:43 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 10:49:04 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	check_wall_move(t_data *data, double x, double y)
{
	int	x1;
	int	y1;

	x1 = floor((x) / GRID);
	y1 = floor((y) / GRID);
	if (y1 >= (int)(data->map_height) || y1 < 0 
		|| x1 < 0 || (x1 >= (int)(data->map_width)))
		return (1);
	if (data->map_path[y1][x1] && data->map_path[y1][x1] == '1')
		return (1);
	return (0);
}

int	wach_kayn_wall(t_data *data, double x, double y)
{
	if (check_wall_move(data, x, y) == 1)
		return (1);
	else if (check_wall_move(data, x, y - 5) == 1)
		return (1);
	else if (check_wall_move(data, x, y + 5) == 1)
		return (1);
	else if (check_wall_move(data, x - 5, y) == 1)
		return (1);
	else if (check_wall_move(data, x + 5, y) == 1)
		return (1);
	else if (check_wall_move(data, x - 5, y - 5) == 1)
		return (1);
	else if (check_wall_move(data, x + 5, y + 5) == 1)
		return (1);
	else 
		return (0);
}

void	update_move_player(t_data *data, int keycode)
{
	double	x_stp;
	double	y_stp;

	x_stp = round(cos(data->player_data.rt_angle) * data->player_data.mv_speed);
	y_stp = round(sin(data->player_data.rt_angle) * data->player_data.mv_speed);
	move_up(data, keycode, x_stp, y_stp);
	move_down(data, keycode, x_stp, y_stp);
	move_left(data, keycode, x_stp, y_stp);
	move_right(data, keycode, x_stp, y_stp);
	if (keycode == ROTATE_LEFT)
		data->player_data.rt_angle -= data->player_data.rt_speed;
	if (keycode == ROTATE_RIGHT)
		data->player_data.rt_angle += data->player_data.rt_speed;
}

void	key_press(void *dat)
{
	t_data	*data;

	data = (t_data *)dat;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		update_move_player(data, UP);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		update_move_player(data, DOWN);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		update_move_player(data, LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		update_move_player(data, RIGHT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		update_move_player(data, ROTATE_LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		update_move_player(data, ROTATE_RIGHT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit(0);
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	render_map(data);
}
