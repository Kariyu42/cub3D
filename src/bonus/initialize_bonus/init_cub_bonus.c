/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:20:13 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/04 17:30:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static t_mlx	ft_new_sprite(void *mlx, char *path)
{
	t_mlx	img;
	int		width;
	int		height;

	width = 12;
	height = 12;
	img.img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);
	return (img);
}

void	load_minimap_img(t_config **conf)
{
	t_mlx	*mlx;

	mlx = (*conf)->mlx;
	(*conf)->data->door_c = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/door_close.xpm");
	(*conf)->data->floor = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/floor.xpm");
	(*conf)->data->door_o = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/door_open.xpm");
	(*conf)->data->wall = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/wall.xpm");
	(*conf)->data->tex_player = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/player.xpm");
	(*conf)->data->empty = ft_new_sprite(mlx->mlx, \
		"./textures/bonus/minimap/void.xpm");
}

static void	setup_player(t_player *character, char c)
{
	if (c == 'N')
	{
		character->dir_x = -1;
		character->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		character->dir_x = 1;
		character->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		character->dir_y = 1;
		character->plane_x = 0.66;
	}
	else if (c == 'W')
	{
		character->dir_y = -1;
		character->plane_x = -0.66;
	}
}

static char	identify_pos_player(t_player *p, int j, char *map, bool *id)
{
	int		i;
	char	c;

	i = -1;
	c = '\0';
	while (map[++i])
	{
		if (ft_strchr("NWES", map[i]) != 0)
		{
			p->pos_y = i + 0.5;
			p->pos_x = j + 0.5;
			c = map[i];
			*id = true;
			break ;
		}
	}
	return (c);
}

int	init_cub(t_config **conf)
{
	int		i;
	char	c;
	bool	id;
	char	**map;

	init_player(conf);
	if (!(*conf)->usr)
		return (-1);
	i = -1;
	id = false;
	map = (*conf)->map->sketch;
	while (map[++i] && !id)
		c = identify_pos_player((*conf)->usr, i, map[i], &id);
	if (!c)
		return (-1);
	setup_player((*conf)->usr, c);
	return (SUCCESS);
}
