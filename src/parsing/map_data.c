#include "cub3d.h"
#include "err_type.h"

bool	is_dir(char *arg)
{
	int		fd;
	bool	res;

	res = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		res = true;
	}
	return (res);
}

char	*format_path_texture(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			j = -1;
			while (str[++j])
				str[j] = str[j + 1];
			i = -1;
		}
		else
			break ;
	}
	i = ft_strlen(str);
	i--;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	init_map_data(t_config **conf)
{
	int		i;
	char	**file;
	t_data	*data;

	i = -1;
	data = (*conf)->data;
	file = (*conf)->map->file;
	while (++i < (*conf)->map->map_loc)
		if (get_textures(file, data, i) == 2 || get_colors(conf, file, i) == 2)
			return (DATA_ERR);
	if (data->count_data != 6)
		return (ft_putendl_fd(ELEMENT_ERR, STDERR_FILENO));
	if (same_color(conf) == DATA_ERR)
		return (DATA_ERR);
	return (SUCCESS);
}
