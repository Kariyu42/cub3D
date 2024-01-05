/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:35:57 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:46:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

char	**set_flood_fill(t_map *map, char **sketch)
{
	char	**tmp;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_calloc(sizeof(char *), map->map_len + 3);
	if (!tmp)
		return (NULL);
	len = longest_line(sketch) + 3;
	while (++i < map->map_len + 2)
	{
		if (i == 0 || i == map->map_len + 1)
			tmp[i] = fill_extremities(tmp[i], len);
		else if (sketch[j])
		{
			tmp[i] = fill_map(sketch[j], tmp[i], len);
			j++;
		}
	}
	tmp[i] = NULL;
	return (tmp);
}

static int	inspect_map(t_config **conf)
{
	int		i;
	char	**tmp;
	t_map	*map;

	i = -1;
	map = (*conf)->map;
	while (map->sketch[++i])
	{
		if (inspect_line(map, map->sketch[i], "10 NWES\t") == false)
			return (ft_putendl_fd(CHAR_ERR, STDERR_FILENO));
		else if (map->num_player > 1)
			return (ft_putendl_fd(PLAYER_ERR, STDERR_FILENO));
	}
	tmp = set_flood_fill(map, map->sketch);
	if (!tmp)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	if (flood_fill(map, tmp) == false)
	{
		free_double_p(tmp);
		return (ft_putendl_fd(FLOOD_ERR, STDERR_FILENO));
	}
	free_double_p(tmp);
	return (SUCCESS);
}

static t_map	*collect_data(t_config **conf, char **av, int fd)
{
	int		i;
	t_map	*map;

	i = -1;
	init_map_struct(conf);
	if (!(*conf)->map)
		return (NULL);
	map = (*conf)->map;
	map->file_size = text_size(av, fd);
	if (!map->file_size)
		return (free_void_err(conf, LEN_ERR));
	map->file = malloc(sizeof(char *) * (map->file_size + 1));
	if (!map->file)
		return (free_void_err(conf, MALLOC_ERR));
	fd = open(av[1], O_RDONLY);
	while (++i < map->file_size)
		map->file[i] = get_next_line(fd);
	map->file[i] = NULL;
	close(fd);
	return (map);
}

int	parse_data(t_config **conf, char **av)
{
	int	fd;

	fd = 0;
	if (init_config(conf) < 0)
		return (MAP_ERR);
	(*conf)->map = collect_data(conf, av, fd);
	if (!(*conf)->map)
		return (free_table_err(conf, NULL, MAP_ERR));
	if (find_map(conf) < 0 || inspect_map(conf) < 0)
		return (free_table_err(conf, NULL, MAP_ERR));
	if (init_texture_vars(conf) < 0 || init_map_data(conf) == DATA_ERR)
		return (free_table_err(conf, NULL, DATA_ERR));
	return (SUCCESS);
}
