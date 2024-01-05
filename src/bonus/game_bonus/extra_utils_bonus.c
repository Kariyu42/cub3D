/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:44:11 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 14:37:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	handle_door(t_config **conf)
{
	int			i;
	int			j;
	t_player	*p;

	i = -1;
	p = (*conf)->usr;
	while ((*conf)->map->sketch[++i])
	{
		j = -1;
		while ((*conf)->map->sketch[i][++j])
		{
			if ((*conf)->map->sketch[i][j] == '2')
			{
				if ((int)p->pos_x == i && (int)p->pos_y == j)
					return ;
				(*conf)->map->sketch[i][j] = '3';
			}
			else if ((*conf)->map->sketch[i][j] == '3')
			{
				if ((int)p->pos_x == i && (int)p->pos_y == j)
					return ;
				(*conf)->map->sketch[i][j] = '2';
			}
		}
	}
}
