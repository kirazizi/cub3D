/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:21:26 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/26 05:01:03 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "./libmlx42/includes/MLX42.h"

# define CUB3D "moraba3at"
# define WIDTH 1024
# define HEIGHT 640
# define GRID 64

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_space
{
	mlx_texture_t	*ntexture;
	mlx_texture_t	*stexture;
	mlx_texture_t	*wtexture;
	mlx_texture_t	*etexture;
	unsigned int	*ntex;
	unsigned int	*stex;
	unsigned int	*wtex;
	unsigned int	*etex;

}	t_space;

typedef struct s_minmap
{
	double		x;
	double		y;
	double		x_tmp;
	double		y_tmp;
	double		x_draw;
	double		y_draw;
	int			color;
	int			mini_len;

}	t_minimap;

typedef struct player
{
	double		x;
	double		y;
	double		rt_angle;
	double		mv_speed;
	double		rt_speed;

}	t_player;

typedef struct s_data
{
	char			**map_array;
	char			**map_path;
	size_t			map_width;
	size_t			map_height;

	size_t			x_pos;
	size_t			y_pos;

	char			player;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;

	int				f_color;
	int				c_color;

	int				mouse_x;
	int				mouse_y;
	int				old_mouse_x;
	int				old_mouse_y;

	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*png_strct;

	t_player		player_data;
	t_space			*space_data;
	t_minimap		minimap;

	double			intersect_coordinate;
	int				north_south_direction;
	double			ray_angle;
	double			pp_dist;

}	t_data;

/*________________________*/

void	init(t_data *data);

/*__________ray casting______________*/

void	castrays(t_data *data);
float	percise_xcrdnt(double ray_angle);
float	percise_ycrdnt(double ray_angle);
int		yray_direction(double ray_angle);
int		xray_direction(double ray_angle);
/*_______________texture_______________________*/

int		get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void	map_datexture(t_data *data, unsigned int wp_height, int i);
void	project_dawall(t_data *data, double ray_dist, int i);

/*____________tabaqa lkadi7a 3awd hhhhhh______________*/

double	ft_min(double val1, double val2);
char	**ft_split(char const	*s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
int		is_digit(char *str);
char	*ft_strdup_newline(char *line);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *keep);
size_t	ft_strlen(char const *str);
int		ft_strchr( char *str, char c);
char	*ft_strdup( char *s);
char	*ft_strndup(char *s, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
//////////////////////////////////////////////////////////////
int		ft_parsing(int ac, char *av, t_data *data);
void	ft_fill_array(t_data *data, char *map);
void	ft_get_width(t_data *data);
void	ft_get_height(t_data *data);
void	get_path(t_data *data);
void	check_map(t_data *data);
void	check_name(char *map);
char	*ft_get_path(char *path);
int		ft_get_color(char *path);
int		check_path(t_data *data);
void	allocate_map(t_data *data);
void	ft_fill_space(char *str, int width);
void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, int color);
void	ft_error(char *str);
void	key_press(void *dat);
void	render_map(t_data *data);
int		wach_kayn_wall(t_data *data, double x, double y);
int		check_wall_move(t_data *data, double x, double y);
void	move_up(t_data *data, int keycode, double x_stp, double y_stp);
void	move_down(t_data *data, int keycode, double x_stp, double y_stp);
void	move_left(t_data *data, int keycode, double x_stp, double y_stp);
void	move_right(t_data *data, int keycode, double x_stp, double y_stp);
void	free_resource(char **array);
void	mouse_move(t_data *data);
void	mini_player(t_data *data);
void	mini_map(t_data *data);
void	get_path_res(t_data *data, int i);

#endif