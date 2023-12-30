#include "cub3d.h"
#include "err_type.h"

static char	**collect_map(t_map *map)
{
	int		i;
	int		j;
	char	**sketch;

	j = 0;
	i = map->map_loc;
	sketch = malloc(sizeof(char *) * (map->map_len + 1));
	if (!sketch)
		return (NULL);
	while (map->file[i])
	{
		sketch[j] = trim_newline(map->file[i], '\n');
		i++;
		j++;
	}
	sketch[j] = NULL;
	return (sketch);
}

static bool	scan_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strchr("10", line[i]))
		return (true);
	return (false);
}

static void	pinpoint_map(t_map *map)
{
	int	i;

	i = -1;
	map->map_loc = 0;
	while (++i < map->file_size)
	{
		if (scan_map(map->file[i]) == true)
			break ;
		map->map_loc++;
	}
}

int	find_map(t_config **conf)
{
	t_map	*map;

	map = (*conf)->map;
	pinpoint_map(map);
	if (!map->map_loc)
		return (ft_putendl_fd(LOC_ERR, -1));
	map->map_len = map_len(map);
	if (!map->map_len)
		return (ft_putendl_fd(LEN_ERR, -1));
	map->sketch = collect_map(map);
	if (!map->sketch)
		return (ft_putendl_fd(EMPTY_ERR, -1));
	return (SUCCESS);
}
