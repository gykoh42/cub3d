/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:20:22 by gykoh             #+#    #+#             */
/*   Updated: 2024/03/20 09:23:24 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0

# define SIDE_FIRST 1
# define MIDDLE 2
# define SIDE_LAST 3

# define TRUE 1
# define FALSE 0

# define DECIDE_W_OR_E 0
# define DECIDE_N_OR_S 1

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ESC 53
# define CLICK_CLOSE 17

# define KEY_RELEASE 3
# define KEY_PRESS 2

# define SCREEN_WIDTH 1150
# define SCREEN_HEIGHT 800

# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.05

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "../libft/libft.h"
# include "../mlx_lib/mlx.h"

typedef struct s_coordinate_point_int
{
	int			x;
	int			y;
}	t_point_int;

typedef struct s_coordinate_point_double
{
	double	x;
	double	y;
}	t_point_double;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_raycast
{
	t_point_double	ray_dir;
	t_point_double	delta_dist;
	t_point_double	side_dist;
	t_point_double	player;
	t_point_int		player_pos;
	t_point_int		step_dir;
	t_texture		*wall_type;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			hit_ratio;
}	t_raycast;

typedef struct s_move_flag
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	r;
	int	l;
}	t_move_flag;

typedef struct s_game_info
{
	void			*mlx;
	void			*win;
	t_raycast		ray;
	t_point_double	view_dir;
	t_point_double	plane;
	t_texture		window;
	t_texture		no_texture;
	t_texture		so_texture;
	t_texture		we_texture;
	t_texture		ea_texture;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	double			perp_wall_dist;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_cnt;
	int				map_start;
	int				ceiling_color;
	int				floor_color;
	t_move_flag		move_flag;
}	t_game_info;

// parsing
void	check_line(char *line, t_game_info *game);
void	check_map(char *line, t_game_info *game);
void	check_map_valid(char *line, t_game_info *game, int type);
void	deep_check(t_game_info *game, char *line, int i);
void	error_exit(char *str);
void	fill_map(char *line, t_game_info *game);
void	get_color(char type, char *line, t_game_info *game);
void	get_info(char *map_file, t_game_info *game);
void	get_map(char *map_file, t_game_info *game);
void	get_path(char type, char *line, t_game_info *game);
char	**init_map(t_game_info *game);
void	init_ray_dir(t_game_info *game, char start_dir);
void	invalid_file(char *file_name);

// raycasting
void	calc_ray_params(t_game_info *game, t_raycast *ray, int monitor);
void	calc_wall_length(t_game_info *game, t_raycast *ray);
void	choose_texture(t_game_info *game, t_raycast *ray);
void	control_player(t_game_info *game);
void	dda(t_game_info *game, t_raycast *ray);
int		draw_map(t_game_info *game);
void	draw_texture(t_game_info *game, int monitor);
int		exit_game(t_game_info *game);
int		fetch_pixel_color(t_texture *texture, int x, int y);
void	init_game(t_game_info *game);
void	init_move_flag(t_game_info *game);
void	init_raycast(t_raycast *ray);
void	init_mlx(t_game_info *game);
void	init_vectors(t_raycast *ray, t_game_info *game);
int		is_wall(t_game_info *game, int x, int y);
int		key_press(int keycode, t_game_info *game);
int		key_release(int keycode, t_game_info *game);
void	mlx_pixel_put_once(t_texture *img, int x, int y, int color);
void	move_player(t_game_info *game);
void	paint_background(t_game_info *game);
void	rotate_player(t_game_info *game);

#endif
