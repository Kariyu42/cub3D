/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:34:13 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 16:17:12 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

//* apply the correct pixel color from the texture
void	apply_texture(t_config **conf, int dir, int x, int y)
{
	int		color;
	t_ray	*r;

	color = 0;
	r = (*conf)->ray;
	if (dir == DOOR)
		color = get_pixel_color(&(*conf)->text[DOOR], r->tex_x, r->tex_y);
	if (dir == NORTH)
		color = get_pixel_color(&(*conf)->text[NORTH], r->tex_x, r->tex_y);
	else if (dir == SOUTH)
		color = get_pixel_color(&(*conf)->text[SOUTH], r->tex_x, r->tex_y);
	else if (dir == EAST)
		color = get_pixel_color(&(*conf)->text[EAST], r->tex_x, r->tex_y);
	else if (dir == WEST)
		color = get_pixel_color(&(*conf)->text[WEST], r->tex_x, r->tex_y);
	my_mlx_pixel_put((*conf)->mlx, x, y, color);
}

void	find_texture_size(t_ray *ray, t_player *p)
{
	if (ray->side == true)
		ray->wall_x = p->pos_x + ray->perp_wall_dist * ray->raydir_x;
	else
		ray->wall_x = p->pos_y + ray->perp_wall_dist * ray->raydir_y;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = ray->wall_x * TEXTURE_W;
	if (ray->side == false && ray->raydir_x > 0)
		ray->tex_x = TEXTURE_W - ray->tex_x - 1;
	if (ray->side == true && ray->raydir_y < 0)
		ray->tex_x = TEXTURE_W - ray->tex_x - 1;
	ray->step_text = 1.0 * TEXTURE_H / ray->line_height;
	ray->text_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) \
		* ray->step_text;
}
