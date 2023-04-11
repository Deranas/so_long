/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:39 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 16:36:21 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/So_Long/so_long.h"

void	load_textures(t_game *game)
{
	game->player.k = mlx_load_png("./Textures/knight_f_idle_anim_f0.png");
	game->player.img_k = mlx_texture_to_image(game->mlx, game->player.k);
	game->sprites.g = mlx_load_png("./Textures/floor_1.png");
	game->sprites.img_g = mlx_texture_to_image(game->mlx, game->sprites.g);
	game->sprites.w = mlx_load_png("./Textures/wall_corner_front_left.png");
	game->sprites.img_w = mlx_texture_to_image(game->mlx, game->sprites.w);
	game->sprites.d = mlx_load_png("./Textures/door.png");
	game->sprites.img_d = mlx_texture_to_image(game->mlx, game->sprites.d);
	game->sprites.c = mlx_load_png("./Textures/chest_full_open_anim_f1.png");
	game->sprites.img_c = mlx_texture_to_image(game->mlx, game->sprites.c);
}

void	free_textures(t_game *game)
{
	mlx_delete_image(game->mlx, game->sprites.img_c);
	mlx_delete_image(game->mlx, game->sprites.img_g);
	mlx_delete_image(game->mlx, game->sprites.img_w);
	mlx_delete_image(game->mlx, game->sprites.img_d);
	mlx_delete_image(game->mlx, game->player.img_k);
	mlx_delete_texture(game->sprites.c);
	mlx_delete_texture(game->sprites.g);
	mlx_delete_texture(game->sprites.d);
	mlx_delete_texture(game->sprites.w);
	mlx_delete_texture(game->player.k);
	mlx_delete_image(game->mlx, game->m_count);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

void	redraw_char(t_game *game, int x, int y)
{
	mlx_delete_image(game->mlx, game->player.img_k);
	game->player.img_k = mlx_texture_to_image(game->mlx, game->player.k);
	mlx_image_to_window(game->mlx, game->player.img_k, x * 16, y * 16 - 12);
}
