/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:42:31 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/24 10:49:33 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

double	player_angle(t_data *data, int i, int j)
{
	if (data->map_path[i][j] == 'N')
		return (3 * M_PI_2);
	else if (data->map_path[i][j] == 'S')
		return (M_PI_2);
	else if (data->map_path[i][j] == 'W')
		return (M_PI);
	else if (data->map_path[i][j] == 'E')
		return (0.0);
	return (-1);
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_path[i])
	{
		j = 0;
		while (data->map_path[i][j++])
			if (data->map_path[i][j] == 'N' || data->map_path[i][j] == 'S'
				|| data->map_path[i][j] == 'W' || data->map_path[i][j] == 'E')
				data->player_data.rt_angle = player_angle(data, i, j);
		i++;
	}
}

void	set_texture_colors(mlx_texture_t *png_strct, unsigned int *texture)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (png_strct->pixels[i] && (j < png_strct->width * png_strct->height))
	{
		texture[j] = get_rgba(png_strct->pixels[i],
				png_strct->pixels[i + 1],
				png_strct->pixels[i + 2],
				255);
		j++;
		i += png_strct->bytes_per_pixel;
	}
}

void	load_pngs(t_data *data)
{
	data->space_data->ntexture = mlx_load_png(data->n_path);
	data->space_data->stexture = mlx_load_png(data->s_path);
	data->space_data->wtexture = mlx_load_png(data->w_path);
	data->space_data->etexture = mlx_load_png(data->e_path);
	if (data->space_data->ntexture == NULL
		|| data->space_data->stexture == NULL
		|| data->space_data->etexture == NULL
		|| data->space_data->wtexture == NULL
		|| data->space_data->ntexture->height != 64 
		|| data->space_data->ntexture->width != 64 
		|| data->space_data->stexture->height != 64 
		|| data->space_data->stexture->width != 64
		|| data->space_data->etexture->height != 64 
		|| data->space_data->etexture->width != 64
		|| data->space_data->wtexture->height != 64
		|| data->space_data->wtexture->width != 64)
	{
		printf("Error : invalide texture\n"); 
		mlx_terminate(data->mlx);
		exit(0);
	}
}

void	init(t_data *data)
{
	player_position(data);
	data->pp_dist = 512 / tan(M_PI / 6);
	data->space_data = (t_space *)ft_calloc(1, sizeof(t_space));
	data->space_data->ntex = (unsigned int *)ft_calloc(1,
			sizeof(unsigned int) * (64 * 64));
	data->space_data->stex = (unsigned int *)ft_calloc(1,
			sizeof(unsigned int) * (64 * 64));
	data->space_data->etex = (unsigned int *)ft_calloc(1,
			sizeof(unsigned int) * (64 * 64));
	data->space_data->wtex = (unsigned int *)ft_calloc(1,
			sizeof(unsigned int) * (64 * 64));
	load_pngs(data);
	set_texture_colors(data->space_data->ntexture, data->space_data->ntex);
	set_texture_colors(data->space_data->stexture, data->space_data->stex);
	set_texture_colors(data->space_data->wtexture, data->space_data->wtex);
	set_texture_colors(data->space_data->etexture, data->space_data->etex);
}
