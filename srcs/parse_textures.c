/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:01 by lde-taey          #+#    #+#             */
/*   Updated: 2025/01/03 16:31:13 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

int	check_struct(t_data *data)
{
	if (data->ea == NULL)
		return (0);
	if (data->no == NULL)
		return (0);
	if (data->we == NULL)
		return (0);
	if (data->so == NULL)
		return (0);
	if (data->c_ceiling.full == 0)
		return (0);
	if (data->c_floor.full == 0)
		return (0);
	return (1);
}

int	store_information(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO", 2))
		store_path_no(line + i + 2, data, line, fd);
	else if (!ft_strncmp(line + i, "SO", 2))
		store_path_so(line + i + 2, data, line, fd);
	else if (!ft_strncmp(line + i, "WE", 2))
		store_path_we(line + i + 2, data, line, fd);
	else if (!ft_strncmp(line + i, "EA", 2))
		store_path_ea(line + i + 2, data, line, fd);
	else if (!ft_strncmp(line + i, "F", 1))
		handle_color_f(line + i + 1, data, line, fd);
	else if (!ft_strncmp(line + i, "C", 1))
		handle_color_c(line + i + 1, data, line, fd);
	else
		return (0);
	return (1);
}

int	valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' \
			|| line[i] == 'S' || line[i] == 'W' \
			|| line[i] == 'E' || line[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

char	*skip_newlines(char *line, int fd, t_data *data)
{
	while (line && *line && !ft_strncmp(line, "\n", 1))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL || !*line)
	{
		printf("No map found.\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
	if (!valid_map_line(line))
		special_error(fd, data, line);
	return (line);
}

char	*parse_firstpart(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (check_struct(data) == 0)
	{
		if (!line || line[0] == '\0')
		information_error(fd, line, data);
		if (ft_strncmp(line, "\n", 1))
		{
			if (!store_information(data, line, fd))
			{
				if (check_struct(data) == 1)
					break ;
				information_error(fd, line, data);
			}
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	line = skip_newlines(line, fd, data);
	return (line);
}
