/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:59:31 by mrodenbu          #+#    #+#             */
/*   Updated: 2025/01/03 16:31:24 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	turn_left(t_data *data)
{
	data->player->angle += TURN_SPEED;
	if (data->player->angle >= 360)
		data->player->angle -= 360;
	render(data);
}

void	turn_right(t_data *data)
{
	data->player->angle -= TURN_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 360;
	render(data);
}
