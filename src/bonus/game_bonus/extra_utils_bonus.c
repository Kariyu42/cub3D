/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:44:11 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/09 19:58:52 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_player proximity_door(t_config **conf)
{
	int			i;
	int			j;
	t_player	*p;
	t_player	res;
	char		**map;

	i = 0;
	j = 0;
	res.pos_x = -1;
	res.pos_y = -1;
	p = (*conf)->usr;
	map = (*conf)->map->sketch;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == '2' || map[i][j] == '3') && \
				ft_abs(p->pos_x - i) <= 4 && ft_abs(p->pos_y - j) <= 4)
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
	res = ft_abs(p->pos_x - door.pos_x) + ft_abs(p->pos_y - door.pos_y);
	printf("res: %f\n", res);
	if (res && res <= 4 && (int)door.pos_x != p->pos_x \
		&& (int)door.pos_y != p->pos_y)
	{
		printf("x: %f, y: %f\n", door.pos_x, door.pos_y);
		printf("caca\n");
		if ((*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] == '2')
		{
			printf("oui\n");
			(*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] = '3';
			printf("oui2\n");
		}
		else if ((*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] == '3')
			(*conf)->map->sketch[(int)door.pos_x][(int)door.pos_y] = '2';
	}
}
