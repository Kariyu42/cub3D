/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:20:13 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:38:55 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

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
