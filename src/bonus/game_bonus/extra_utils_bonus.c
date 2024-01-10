/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:44:11 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/10 11:13:39 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_player	proximity_door(t_config **conf)
{
	int			i;
	int			j;
	t_player	res;

	i = 0;
	j = 0;
	res.pos_x = -1;
	res.pos_y = -1;
	while ((*conf)->map->sketch[++i])
	{
		j = -1;
		while ((*conf)->map->sketch[i][++j])
		{
			if (((*conf)->map->sketch[i][j] == '2' || \
				(*conf)->map->sketch[i][j] == '3') && \
				ft_abs((*conf)->usr->pos_x - i) <= 2.5 && \
				ft_abs((*conf)->usr->pos_y - j) <= 2.5)
			{
				res.pos_x = i;
				res.pos_y = j;
				return (res);
			}
		}
	}
	return (res);
}

void	handle_door(t_config **conf)
{
	t_player	door;
	t_player	*p;
	double		res;

	res = 0;
	p = (*conf)->usr;
	door = proximity_door(conf);
	if (door.pos_x < 0 || door.pos_y < 0)
		return ;
	res = sqrt(pow(p->pos_x - door.pos_x, 2) + pow(p->pos_y - door.pos_y, 2));
	if (res && res <= 2.5 && res >= 1.5)
	{
		if ((*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] == '2')
			(*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] = '3';
		else if ((*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] == '3')
			(*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] = '2';
	}
}
