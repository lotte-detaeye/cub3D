/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:08:14 by lde-taey          #+#    #+#             */
/*   Updated: 2025/01/03 16:30:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

// this should check if there are no zeros outside of the walls
void	zero_check(t_data *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '0')
			{
				zero_horizontal_check(data, fd, i, j);
				zero_vertical_check(data, fd, i, j);
			}
			j++;
		}
		i++;
	}
}

void	space_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == ' ')
				data->map[i][j] = '*';
			j++;
		}
		i++;
	}
}

void	store_player_data(t_data *data, int i, int j)
{
	data->player->position->x = j * CUBE_SIZE + CUBE_SIZE / 2;
	data->player->position->y = i * CUBE_SIZE + CUBE_SIZE / 2;
	if (data->map[i][j] == 'N')
		data->player->angle = 90;
	else if (data->map[i][j] == 'E')
		data->player->angle = 0;
	else if (data->map[i][j] == 'S')
		data->player->angle = 270;
	else if (data->map[i][j] == 'W')
		data->player->angle = 180;
}

int	directions_check(t_data *data)
{
	int	i;
	int	j;
	int	play_num;

	i = 0;
	play_num = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || \
				data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				store_player_data(data, i, j);
				play_num++;
			}
			j++;
		}
		i++;
	}
	return (play_num);
}

void	player_check(t_data *data, int fd)
{
	int	play_num;

	play_num = directions_check(data);
	if (play_num == 0)
	{
		printf("No player found.");
		map_error2(fd, data);
	}
	else if (play_num > 1)
	{
		printf("More than one player found.");
		map_error2(fd, data);
	}
}
