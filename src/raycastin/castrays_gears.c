/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays_gears.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:20:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/22 07:35:07 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

float	percise_ycrdnt(double ray_angle)
{
	if (sin(ray_angle) > 0)
		return (64.0);
	return (0.0);
}

float	percise_xcrdnt(double ray_angle)
{
	if (cos(ray_angle) > 0)
		return (64.0);
	return (0.0);
}

int	xray_direction(double ray_angle)
{
	return (fabs(cos(ray_angle)) / cos(ray_angle));
}

int	yray_direction(double ray_angle)
{
	return (fabs(sin(ray_angle)) / sin(ray_angle));
}
