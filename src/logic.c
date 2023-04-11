/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:41 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 16:36:36 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/So_Long/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		check_collision(game, game->player.pos.x, game->player.pos.y - 1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		check_collision(game, game->player.pos.x, game->player.pos.y + 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		check_collision(game, game->player.pos.x - 1, game->player.pos.y);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		check_collision(game, game->player.pos.x + 1, game->player.pos.y);
	redraw_char(game, game->player.pos.x, game->player.pos.y);
}

int	check_collision(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == '1')
		return (1);
	put_move_count(game);
	if (game->map.map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->sprites.img_g, x * 16, y * 16);
		game->map.c--;
	}
	else if (game->map.map[y][x] == 'E')
		check_end(game);
	update_map(game, x, y);
	return (0);
}

void	update_map(t_game *game, int x, int y)
{
	if (game->exit.x == game->player.pos.x \
	&& game->exit.y == game->player.pos.y)
		game->map.map[game->player.pos.y][game->player.pos.x] = 'E';
	else
		game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	game->map.map[y][x] = 'P';
	game->player.pos.y = y;
	game->player.pos.x = x;
}

void	check_end(t_game *game)
{
	if (game->map.c == 0)
	{
		ft_printf("Congrats! Final move count:%i\n", game->player.move);
		mlx_close_window(game->mlx);
	}
}

void	put_move_count(t_game *game)
{
	char	*str;

	game->player.move++;
	str = ft_itoa(game->player.move);
	if (game->m_count)
		mlx_delete_image(game->mlx, game->m_count);
	game->m_count = mlx_put_string(game->mlx, str, 0, -4);
	free(str);
}
