/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:42:39 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 16:13:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../Lib/Libft/inc/libft.h"
# include "../Lib/Libft/inc/get_next_line.h"

# ifdef __APPLE__
#  include "../mlx/macos/mlx.h"
// KEY PRESSED
#  define ESC_KEY 53
#  define RIGHT_KEY 124
#  define LEFT_KEY 123
#  define W_KEY 13
#  define D_KEY 2
#  define S_KEY 1
#  define A_KEY 0
#  define MOUSE_TOGGLE 46
#  define SPACE_BAR 49
# else
#  include "../mlx/linux/mlx.h"
// KEY PRESSED
#  define ESC_KEY 65307
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361
#  define W_KEY 119
#  define D_KEY 100
#  define S_KEY 115
#  define A_KEY 97
#  define MOUSE_TOGGLE 46
#  define SPACE_BAR 49
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

// Game Macros
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// Size of the screen
# define WIDTH 1080
# define HEIGHT 720

// Size of Textures
# define TEXTURE_W 64
# define TEXTURE_H 64

// Size of Minimap
# define SIZE_MINIMAP 11
# define MID_MINIMAP 6

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DOOR
}	t_dir;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	char	c;
	double	pos_x;
	double	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	double	old_dir_x;
	double	old_plane_x;
}	t_player;

typedef struct s_ray
{
	double	cam_x;
	double	raydir_x;
	double	raydir_y;

	int		map_x;
	int		map_y;

	double	sidedist_x;
	double	sidedist_y;

	double	deltadist_x;
	double	deltadist_y;

	double	step_x;
	double	step_y;
	bool	side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	bool	door_hit;

	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step_text;
	double	text_pos;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	char	**file;
	int		file_size;
	char	**sketch;
	int		map_len;
	int		map_loc;
	int		num_player;
	bool	anomaly;
}	t_map;

typedef struct s_data
{
	int		count_data;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		no_find;
	int		so_find;
	int		we_find;
	int		ea_find;
	int		f_find;
	int		c_find;
	char	**f_color;
	char	**c_color;
	char	*door_text;
	double	pos_mmap_x;
	double	pos_mmap_y;
	bool	mouse_show;
	t_mlx	wall;
	t_mlx	empty;
	t_mlx	floor;
	t_mlx	tex_player;
	t_mlx	door_o;
	t_mlx	door_c;
}	t_data;

typedef struct s_config
{
	t_map		*map;
	t_data		*data;
	t_mlx		text[5];
	t_mlx		*mlx;
	t_ray		*ray;
	t_player	*usr;
}	t_config;

/* UTILS */
int		check_extension(char *str);
int		init_config(t_config **conf);
int		init_map_struct(t_config **conf);
int		init_texture_vars(t_config **conf);
int		init_player(t_config **conf);
void	init_ray_struct(t_config **conf);

/* --- PARSING --- kquetat- */
int		parse_data(t_config **conf, char **av);
int		find_map(t_config **conf);
int		map_len(t_map *map);
int		text_size(char **av, int fd);
char	*trim_newline(char *str, char c);
bool	inspect_line(t_map *map, char *map_line, char *to_find);
int		longest_line(char **map);

/* INSPECT_MAP functions kquetat- */
char	*fill_map(char *map, char *tmp, int line_len);
char	*fill_extremities(char *tmp, int line_len);
bool	flood_fill(t_map *map, char **tmp);
t_pos	find_pos(char letter, char **map);

// kquetat- raycasting part && mlx_window.
int		initialize_mlx_win(t_config **conf);
int		init_cub(t_config **conf);
int		init_game(t_config **conf);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
double	ft_abs(double num);

/* --- epraduro --- */

/*	GET_TEXTURE.C	*/
int		get_colors(t_config **conf, char **file, int i);
int		get_textures(char **file, t_data *data, int i);
int		get_path(char *str, char **store_data, int *data);

/*	CHECK_COLOR.C	*/
int		ft_strcmp(char *s1, char *s2);
int		same_color(t_config **conf);
int		len_tab(char **tab);
int		valid_color(char **color);
int		check_color(char ***color, char *str, int *data);

/*	MAP_DATA.C	*/
int		init_map_data(t_config **conf);
bool	is_dir(char *arg);
int		check_path(char *arg);
int		stock_image(t_config **conf);
char	*format_path_texture(char *str);
int		ft_contain(char *str, char *find);

/* RAYCASTING FUNCTIONS */
int		render_game(t_config **conf, t_ray *ray, t_player *usr);
void	init_ray_dir(t_ray *ray, t_player *usr, int x);
void	define_ray_dir(t_ray *ray, t_player *usr);
void	start_dda_algo(char **map, t_ray *ray);
void	get_wall_height(t_ray *ray);

/* TEXTURE FUNCTIONS */
void	find_texture_size(t_ray *ray, t_player *p);
void	fill_colors(char **color_table, int *to_fill);
int		create_trgb(int t, int r, int g, int b);
void	apply_texture(t_config **conf, int dir, int x, int y);

/* GAME FUNCTIONS */
int		get_pixel_color(t_mlx *data, int x, int y);
int		key_handler(int key_pressed, t_config **conf);
void	rotate_keys(t_config **conf, int key_pressed);
int		game_loop(t_config **conf);

/* MINIMAP FUNCTIONS */
int		ft_load_minimap(t_config **conf, t_mlx *mlx);
void	load_minimap_img(t_config **conf);

/* OTHER BONUSES */
void	handle_door(t_config **conf);

int		ft_close(t_config **conf);

#endif
