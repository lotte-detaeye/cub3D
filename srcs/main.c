/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:58 by lde-taey          #+#    #+#             */
/*   Updated: 2025/01/03 16:29:34 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

int	check_args(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		printf("Error.\nThis program takes one (and only one) argument.\n");
		return (1);
	}
	if (check_ext(argv[1]))
	{
		printf("Error.\nThis program only accepts .cub files as an argument.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (1);
	if (init_everything(argv[1], &data))
		return (1);
	free_everything(&data);
	return (0);
}
