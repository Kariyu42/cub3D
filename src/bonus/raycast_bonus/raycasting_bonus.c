/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:34:43 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 16:14:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_ray_dir(t_ray *ray, t_player *usr, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = usr->dir_x + usr->plane_x * ray->cam_x;
	ray->raydir_y = usr->dir_y + usr->plane_y * ray->cam_x;
	ray->map_x = (int)usr->pos_x;
	ray->map_y = (int)usr->pos_y;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = ft_abs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = ft_abs(1 / ray->raydir_y);
}

void	define_ray_dir(t_ray *ray, t_player *usr)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (usr->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - usr->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (usr->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - usr->pos_y) * ray->deltadist_y;
	}
}

void	start_dda_algo(char **map, t_ray *ray)
{
	bool	wall_hit;

	wall_hit = false;
	ray->door_hit = false;
	while (wall_hit != true)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = false;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = true;
		}
		if (map[ray->map_x][ray->map_y] == '1' \
			|| map[ray->map_x][ray->map_y] == '2')
			wall_hit = true;
		if (map[ray->map_x][ray->map_y] == '2')
			ray->door_hit = true;
	}
}

void	get_wall_height(t_ray *ray)
{
	if (ray->side == false)
		ray->perp_wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perp_wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
