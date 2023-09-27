/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_datexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:33:38 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/25 09:09:55 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

unsigned int	*get_texture(t_data *data, double ray_angle)
{
	if (data->north_south_direction == 1)
	{
		if (xray_direction(ray_angle) > 0)
			return (data->space_data->etex);
		return (data->space_data->wtex);
	}
	else
	{
		if (yray_direction(ray_angle) > 0)
			return (data->space_data->stex);
		return (data->space_data->ntex);
	}
}

void	draw_to_wall(t_data *data, unsigned int wp_height, int i, int j)
{
	unsigned int	d;
	unsigned int	color;
	unsigned int	*txtr;
	unsigned int	texture_xoffest;
	unsigned int	texture_yoffest;

	txtr = get_texture(data, data->ray_angle);
	texture_xoffest = (unsigned int)(data->intersect_coordinate) % 64;
	d = j + ((wp_height - HEIGHT) / 2);
	texture_yoffest = (d * 64) / wp_height;
	color = txtr[(texture_yoffest * 64) + texture_xoffest];
	mlx_put_pixel(data->img, i, j, color);
}

void	map_datexture(t_data *data, unsigned int wp_height, int i)
{
	unsigned int	j;
	long			pixel_ofla;
	long			pixel_izdar;

	j = 0;
	pixel_ofla = (long)(HEIGHT / 2) - (long)(wp_height / 2);
	if (pixel_ofla < 0)
		pixel_ofla = 0;
	pixel_izdar = (long)(HEIGHT / 2) + (long)(wp_height / 2);
	if (pixel_izdar > HEIGHT)
		pixel_izdar = HEIGHT;
	while (j < pixel_ofla)
		mlx_put_pixel(data->img, i, j++, data->c_color);
	while (j < pixel_izdar)
	{
		draw_to_wall(data, wp_height, i, j);
		j++;
	}
	while (j < HEIGHT)
		mlx_put_pixel(data->img, i, j++, data->f_color);
}

void	project_dawall(t_data *data, double ray_dist, int i)
{
	double	ray_disty;
	double	wp_height;
	double	destortion_angle;
	double	ray_step;

	ray_step = (M_PI / 3) / WIDTH;
	destortion_angle = (M_PI / 6) - (i * ray_step);
	ray_disty = ray_dist * fabs(cos(destortion_angle));
	wp_height = (data->pp_dist / ray_disty) * 64;
	map_datexture(data, wp_height, i);
}
