/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:40 by mrodenbu          #+#    #+#             */
/*   Updated: 2025/01/03 16:30:05 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

t_point	get_grid_position(t_point point)
{
	t_point	cube;

	cube.x = floor(point.x / CUBE_SIZE);
	cube.y = floor(point.y / CUBE_SIZE);
	return (cube);
}
