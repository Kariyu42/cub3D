/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_dup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:36:06 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/09 18:47:08 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static void	examine_path(t_map *map, char **tmp, t_pos pos, char *to_fill)
{
	if (pos.y < 0 || pos.x < 0 \
		|| pos.y >= map->map_len + 2 \
		|| !ft_strchr(to_fill, tmp[pos.y][pos.x]) \
		|| tmp[pos.y][pos.x] == '1' || map->anomaly)
		return ;
	if (tmp[pos.y][pos.x] && (tmp[pos.y][pos.x] == '/' \
		|| tmp[pos.y][pos.x] == ' ' || tmp[pos.y][pos.x] == '\t'))
		map->anomaly = true;
	tmp[pos.y][pos.x] = 'X';
	examine_path(map, tmp, (t_pos){pos.x - 1, pos.y}, to_fill);
	examine_path(map, tmp, (t_pos){pos.x + 1, pos.y}, to_fill);
	examine_path(map, tmp, (t_pos){pos.x, pos.y - 1}, to_fill);
	examine_path(map, tmp, (t_pos){pos.x, pos.y + 1}, to_fill);
}

static bool	check_player_pos(t_map *map, char **tmp)
{
	int		i;
	char	c;

	i = -1;
	c = '\0';
	while (tmp[++i])
	{
		if (ft_strchr(tmp[i], 'N'))
			c = 'N';
		else if (ft_strchr(tmp[i], 'S'))
			c = 'S';
		else if (ft_strchr(tmp[i], 'E'))
			c = 'E';
		else if (ft_strchr(tmp[i], 'W'))
			c = 'W';
		if (c)
			break ;
	}
	examine_path(map, tmp, find_pos(c, tmp), "0 2/NWSE\t");
	if (map->anomaly == true)
		return (false);
	return (true);
}

bool	flood_fill(t_map *map, char **tmp)
{
	int		i;
	t_pos	pos;

	i = -1;
	if (!check_player_pos(map, tmp))
	{
		ft_putendl_fd(PLAYER_POS_ERR, STDERR_FILENO);
		return (false);
	}
	map->anomaly = false;
	while (tmp[++i])
	{
		while (tmp[i] && ft_strchr(tmp[i], '0'))
		{
			pos = find_pos('0', tmp);
			if (pos.x < 0 || pos.y < 0)
				return (false);
			examine_path(map, tmp, pos, "0 2/NWSE\t");
		}
		if (map->anomaly == true)
			return (false);
	}
	return (true);
}
