#include "cub3d.h"
#include "err_type.h"

void	setup_player(t_player *character, char c)
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

char	identify_pos_player(t_player *p, int j, char *map_part, bool *identified)
{
	int		i;
	char	c;

	i = -1;
	c = '\0';
	while (map_part[++i])
	{
		if (ft_strchr("NWES", map_part[i]) != 0)
		{
			p->pos_y = i + 0.5;
			p->pos_x = j + 0.5;
			c = map_part[i];
			*identified = true;
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
