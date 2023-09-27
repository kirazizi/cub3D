/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:09:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/25 00:04:53 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

double	dstto_wall(t_data *data, double hdist, double vdist, double xinter)
{
	if (hdist < vdist || vdist == floor(-1))
	{
		data->intersect_coordinate = xinter;
		data->north_south_direction = 0;
		return (hdist);
	}
	return (vdist);
}

int	check_wall(t_data *data, double xinter, double yinter, int h)
{
	double	x;
	double	y;

	x = xinter;
	y = yinter;
	if (h)
	{
		if (sin(data->ray_angle) <= 0)
			y -= 1.0;
	}
	else
	{
		if (cos(data->ray_angle) <= 0)
			x -= 1.0;
	}
	if (data->map_path[(size_t)(y / 64.0)][(size_t)(x / 64.0)] == '1'
		|| (data->map_path[(size_t)(y / 64.0)][(size_t)(x / 64.0)] == '5'))
		return (1);
	return (0);
}

double	find_vintersecto(t_data *data, double ray_angle)
{
	double	xinter;
	double	yinter;

	xinter = floor(data->player_data.x / 64) * 64 + percise_xcrdnt(ray_angle);
	yinter = data->player_data.y + (fabs((xinter - data->player_data.x) \
		* tan(ray_angle)) * yray_direction(ray_angle));
	while (1)
	{
		if (((size_t)(yinter / 64.0) >= ((data->map_height))) || xinter < 0.0
			|| yinter < 0.0 || ((size_t)(xinter / 64.0) >= ((data->map_width))))
			return (floor(-1));
		if (check_wall(data, xinter, yinter, 0))
		{
			data->intersect_coordinate = yinter;
			data->north_south_direction = 1;
			return (sqrt(pow(data->player_data.y - yinter, 2)
					+ pow(data->player_data.x - xinter, 2)));
		}
		xinter += (64 * xray_direction(ray_angle));
		yinter += 64 * fabs(tan(ray_angle)) * yray_direction(ray_angle);
	}
}

double	find_intersecto(t_data *data, double ray_angle)
{
	double	xinter;
	double	yinter;
	double	vintersectdist;
	double	hintersectdist;

	yinter = (floor(data->player_data.y / 64) * 64) + percise_ycrdnt(ray_angle);
	xinter = data->player_data.x + (fabs((yinter - (long)data->player_data.y) \
		/ tan(ray_angle)) * xray_direction(ray_angle));
	while (1)
	{
		if (((size_t)(yinter / 64.0) >= ((data->map_height))) || xinter < 0.0
			|| yinter < 0.0 || ((size_t)(xinter / 64.0) >= ((data->map_width))))
			return (find_vintersecto(data, ray_angle));
		if (check_wall(data, xinter, yinter, 1))
		{
			hintersectdist = sqrt(pow(data->player_data.x - xinter, 2)
					+ pow(data->player_data.y - yinter, 2));
			vintersectdist = find_vintersecto(data, ray_angle);
			return (dstto_wall(data, hintersectdist, vintersectdist, xinter));
		}
		yinter += (64 * yray_direction(ray_angle));
		xinter += (fabs(64 / tan(ray_angle)) * xray_direction(ray_angle));
	}
}

void	castrays(t_data *data)
{
	int		i;
	double	ray_step;
	double	ray_angle;
	double	ray_dist;

	i = 0;
	ray_step = (M_PI / 3) / WIDTH;
	ray_angle = data->player_data.rt_angle - (M_PI / 6);
	while (i < WIDTH)
	{
		ray_dist = find_intersecto(data, ray_angle);
		data->ray_angle = ray_angle;
		project_dawall(data, ray_dist, i);
		ray_angle += ray_step;
		i++;
	}
}
