/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:54:57 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 12:07:06 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_init(t_data *data)
{
	double	ray_step;

	ray_step = (M_PI / 3) / WIDTH;
	data->player_data.x = ((data->x_pos) * GRID) + (GRID / 2);
	data->player_data.y = ((data->y_pos) * GRID) + (GRID / 2);
	data->player_data.mv_speed = 2;
	data->old_mouse_x = WIDTH / 2;
	data->player_data.rt_speed = ray_step * 50;
}

void	frew_krew(t_data *data)
{
	free_resource(data->map_array);
	free_resource(data->map_path);
	free(data->space_data->etex);
	free(data->space_data->wtex);
	free(data->space_data->stex);
	free(data->space_data->ntex);
	free(data->n_path);
	free(data->s_path);
	free(data->w_path);
	free(data->e_path);
	mlx_delete_image(data->mlx, data->img);
	mlx_delete_texture(data->space_data->etexture);
	mlx_delete_texture(data->space_data->ntexture);
	mlx_delete_texture(data->space_data->stexture);
	mlx_delete_texture(data->space_data->wtexture);
	free(data->space_data);
	mlx_terminate(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parsing(ac, av[1], &data))
		exit (1);
	data.mlx = mlx_init(WIDTH, HEIGHT, CUB3D, false);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	player_init(&data);
	init(&data);
	mlx_loop_hook(data.mlx, key_press, &data);
	mlx_loop(data.mlx);
	frew_krew(&data);
	return (0);
}
