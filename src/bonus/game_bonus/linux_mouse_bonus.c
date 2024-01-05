/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:48:02 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 14:27:49 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static void	mouse_move(t_config **conf)
{
	int		x;
	int		y;
	t_mlx	*mlx;

	mlx = (*conf)->mlx;
	if ((*conf)->data->mouse_show)
	{
		mlx_mouse_show(mlx->mlx, mlx->win);
		return ;
	}
	mlx_mouse_hide(mlx->mlx, mlx->win);
	mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
	if (x < WIDTH / 2)
		rotate_keys(conf, LEFT_KEY);
	else if (x > WIDTH / 2)
		rotate_keys(conf, RIGHT_KEY);
	mlx_mouse_move(mlx->mlx, mlx->win, WIDTH / 2, HEIGHT / 2);
}

int	game_loop(t_config **conf)
{
	int	r_value;

	r_value = SUCCESS;
	mouse_move(conf);
	r_value = render_game(conf, (*conf)->ray, (*conf)->usr);
	if (r_value != SUCCESS)
		ft_close(conf);
	r_value = ft_load_minimap(conf, (*conf)->mlx);
	if (r_value != SUCCESS)
		ft_close(conf);
	return (r_value);
}
