/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:25:37 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/09 19:33:15 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static void	do_move(t_config **conf, double new_x, double new_y)
{
	int			move_x;
	int			move_y;
	char		**map;
	t_player	*p;

	map = (*conf)->map->sketch;
	p = (*conf)->usr;
	move_x = (int)(p->pos_x + new_x * (MOVE_SPEED + 0.1));
	move_y = (int)(p->pos_y + new_y * (MOVE_SPEED + 0.1));
	if (map[move_x][(int)(p->pos_y)] != '1' \
		 && map[move_x][(int)(p->pos_y)] != '2')
		p->pos_x += new_x * MOVE_SPEED;
	if (map[(int)(p->pos_x)][move_y] != '1' \
		&& map[(int)(p->pos_x)][move_y] != '2')
		p->pos_y += new_y * MOVE_SPEED;
}

void	move_keys(t_config **conf, int key_pressed)
{
	t_player	*p;

	p = (*conf)->usr;
	if (key_pressed == W_KEY)
		do_move(conf, p->dir_x, p->dir_y);
	else if (key_pressed == S_KEY)
		do_move(conf, -p->dir_x, -p->dir_y);
	else if (key_pressed == A_KEY)
		do_move(conf, -p->dir_y, p->dir_x);
	else if (key_pressed == D_KEY)
		do_move(conf, p->dir_y, -p->dir_x);
}

void	rotate_keys(t_config **conf, int key_pressed)
{
	t_player	*p;

	p = (*conf)->usr;
	if (key_pressed == RIGHT_KEY)
	{
		p->old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-ROT_SPEED) - p->dir_y * sin(-ROT_SPEED);
		p->dir_y = p->old_dir_x * sin(-ROT_SPEED) + p->dir_y * cos(-ROT_SPEED);
		p->old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-ROT_SPEED) - \
			p->plane_y * sin(-ROT_SPEED);
		p->plane_y = p->old_plane_x * sin(-ROT_SPEED) + \
			p->plane_y * cos(-ROT_SPEED);
	}
	else if (key_pressed == LEFT_KEY)
	{
		p->old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(ROT_SPEED) - p->dir_y * sin(ROT_SPEED);
		p->dir_y = p->old_dir_x * sin(ROT_SPEED) + p->dir_y * cos(ROT_SPEED);
		p->old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(ROT_SPEED) - \
			p->plane_y * sin(ROT_SPEED);
		p->plane_y = p->old_plane_x * sin(ROT_SPEED) + \
			p->plane_y * cos(ROT_SPEED);
	}
}

void	reload_img(t_config **conf)
{
	mlx_destroy_image((*conf)->mlx->mlx, (*conf)->mlx->img);
	(*conf)->mlx->img = mlx_new_image((*conf)->mlx->mlx, WIDTH, HEIGHT);
	if (!(*conf)->mlx->img)
		return ;
	(*conf)->mlx->addr = mlx_get_data_addr((*conf)->mlx->img, \
		&(*conf)->mlx->bpp, &(*conf)->mlx->line_len, &(*conf)->mlx->endian);
	if (!(*conf)->mlx->addr)
		return ;
	render_game(conf, (*conf)->ray, (*conf)->usr);
}

int	key_handler(int key_pressed, t_config **conf)
{
	if (key_pressed == ESC_KEY)
		ft_close(conf);
	if (key_pressed == MOUSE_TOGGLE)
	{
		if (!(*conf)->data->mouse_show)
			(*conf)->data->mouse_show = true;
		else
			(*conf)->data->mouse_show = false;
	}
	if (key_pressed == SPACE_BAR)
		handle_door(conf);
	move_keys(conf, key_pressed);
	rotate_keys(conf, key_pressed);
	return (SUCCESS);
}
