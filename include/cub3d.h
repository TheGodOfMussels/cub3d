/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:59 by dimolin2          #+#    #+#             */
/*   Updated: 2024/01/10 17:10:52 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define PI 3.141592653589793
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_R 114
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_render
{
	int			start;
	int			end;
	int			color;
}				t_render;

typedef struct s_ray
{
	double		ray_angle;
	double		currentx;
	double		currenty;
	double		raycos;
	double		raysin;
	double		dist;
	double		wallheight;
	int			direction;
}				t_ray;

typedef struct s_column
{
	int			sky_start;
	int			sky_end;
	int			sky_color;
	int			wall_start;
	int			wall_end;
	int			wall_color;
	int			floor_start;
	int			floor_end;
	int			floor_color;
	int			colnbr;
	int			direction;
	double		currenty;
	double		currentx;
}				t_column;

typedef struct s_vectors
{
	double		x;
	double		y;
}				t_vectors;

typedef struct s_texture
{
	char		*path;
	char		*data;
	void		*ptr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			currenty;
}				t_texture;

typedef struct s_colors
{
	int			r;
	int			g;
	int			b;
}				t_colors;

typedef struct s_camera
{
	t_vectors	pos;
	t_vectors	dir;
	t_vectors	x_dir;
	t_vectors	plane;
}				t_camera;

typedef struct s_game
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	img;
	t_vectors	size;
	t_colors	color[2];
	t_camera	camera;
	void		*mlx;
	int			err;
	char		**map;
	double		spawn_x;
	double		spawn_y;
	double		angle;
	void		*win_ptr;
	double		half_h;
	double		half_w;
	double		fov;
	double		half_fov;
	double		rc_incrementing;
	int			rdelay;
	int			rc_precision;
	int			i;
	int			j;
	int			number_of_rows;
	int			flag;
}				t_game;

// Readfile functions
char			**ft_readfile(char *path);
int				ft_read_fields(t_game *p, char **file);

// Check functions
int				ft_param_check(char **file);
int				ft_check_tex_color(t_game *p);

// Map save functions
void			ft_read_map(t_game *p, char **file);

// Map checker functions
int				ft_map_checker(char **map);
int				ft_check_charset(char *str);
int				ft_check_horizontal(char **map, int idx, int k);
int				ft_check_vertical(char **map, int idx, int j);

// Utils functions
int				ft_isspace(char c);
int				ft_atoi_special(char *str);
char			*ft_strdup_special(char *str);
void			ft_color_err(t_colors *color);
int				ft_param_check(char **file);
int				ft_strlen_special(char *str);
void			ft_render_pixel(t_texture img, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_texture *data, int x, int y);
unsigned int	ft_color_converter(int r, int g, int b);
double			ft_degrees_to_radiants(double degrees);
int				ft_is_direction(char c);

// Init and setup functions
void			ft_struct_setup(t_game *p);
void			ft_spawn(t_game *p);
void			ft_create_window(t_game *p);

// Raycast and render functions
void			ft_raycasting(t_game *p);
void			ft_render_full_column(t_game *p, t_texture img,
					t_column column);
void			ft_render_walls(t_game *p, t_texture img, t_column column);
void			ft_render_wall(t_texture *texture, t_texture img,
					t_column column);
void			ft_render_column(t_texture img, t_column column, int flag);
void			ft_ren_col_piece(t_texture img, t_render render, int nb);

// Key handler functions
int				ft_handlekeys(int ks, t_game *p);
void			ft_move_left(t_game *prg, double playercos, double playersin);
void			ft_move_right(t_game *prg, double playercos, double playersin);
void			ft_move_up(t_game *prg, double playercos, double playersin);
void			ft_move_down(t_game *prg, double playercos, double playersin);

// Free and destroy functions
void			ft_free_path(t_game *p);
int				ft_close(t_game *p);

#endif