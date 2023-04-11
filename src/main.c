/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:33:07 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 17:04:11 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/Libft/libft.h"
#include "../lib/So_Long/so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (check_arg(argc, argv[1]) == 1)
		return (EXIT_FAILURE);
	if (fill_map(&game, argv[1]) == 1)
		return (EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_MAXIMIZED, true);
	game.mlx = \
	mlx_init(game.map.map_l * 16, game.map.map_h * 16, "Treasure Hunt", true);
	if (!(game.mlx))
		return (EXIT_FAILURE);
	load_textures(&game);
	if ((draw_map(&game)) == 1)
		mlx_close_window(game.mlx);
	mlx_key_hook(game.mlx, my_keyhook, &game);
	mlx_loop(game.mlx);
	free_map(game.map.map);
	free_textures(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
