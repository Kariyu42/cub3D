/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:23 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:24:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

void	init_ray_struct(t_config **conf)
{
	(*conf)->ray = malloc(sizeof(t_ray));
	if (!(*conf)->ray)
		return ;
	(*conf)->ray->cam_x = 0;
	(*conf)->ray->raydir_x = 0;
	(*conf)->ray->raydir_y = 0;
	(*conf)->ray->map_x = 0;
	(*conf)->ray->map_y = 0;
	(*conf)->ray->sidedist_x = 0;
	(*conf)->ray->sidedist_y = 0;
	(*conf)->ray->deltadist_x = 0;
	(*conf)->ray->deltadist_y = 0;
	(*conf)->ray->perp_wall_dist = 0;
	(*conf)->ray->step_x = 0;
	(*conf)->ray->step_y = 0;
	(*conf)->ray->side = false;
	(*conf)->ray->line_height = 0;
	(*conf)->ray->draw_start = 0;
	(*conf)->ray->draw_end = 0;
}

int	init_player(t_config **conf)
{
	(*conf)->usr = malloc(sizeof(t_player));
	if (!(*conf)->usr)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	(*conf)->usr->c = '\0';
	(*conf)->usr->pos_x = 0;
	(*conf)->usr->pos_y = 0;
	(*conf)->usr->dir_x = 0;
	(*conf)->usr->dir_y = 0;
	(*conf)->usr->plane_x = 0;
	(*conf)->usr->plane_y = 0;
	(*conf)->usr->old_dir_x = 0;
	(*conf)->usr->old_plane_x = 0;
	return (SUCCESS);
}

int	init_texture_vars(t_config **conf)
{
	(*conf)->data = malloc(sizeof(t_data));
	if (!(*conf)->data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	(*conf)->data->count_data = 0;
	(*conf)->data->no_text = NULL;
	(*conf)->data->so_text = NULL;
	(*conf)->data->we_text = NULL;
	(*conf)->data->ea_text = NULL;
	(*conf)->data->no_find = 0;
	(*conf)->data->so_find = 0;
	(*conf)->data->we_find = 0;
	(*conf)->data->ea_find = 0;
	(*conf)->data->f_find = 0;
	(*conf)->data->c_find = 0;
	(*conf)->data->f_color = NULL;
	(*conf)->data->c_color = NULL;
	return (SUCCESS);
}

int	init_map_struct(t_config **conf)
{
	(*conf)->map = malloc(sizeof(t_map));
	if (!(*conf)->map)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	(*conf)->map->file = NULL;
	(*conf)->map->file_size = 0;
	(*conf)->map->sketch = NULL;
	(*conf)->map->map_len = 0;
	(*conf)->map->map_loc = 0;
	(*conf)->map->num_player = 0;
	(*conf)->map->anomaly = false;
	return (SUCCESS);
}

int	init_config(t_config **conf)
{
	*conf = malloc(sizeof(t_config));
	if (!conf || !*conf)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	(*conf)->map = NULL;
	(*conf)->data = NULL;
	(*conf)->mlx = NULL;
	(*conf)->ray = NULL;
	(*conf)->usr = NULL;
	return (SUCCESS);
}
