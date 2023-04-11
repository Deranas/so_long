/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:33 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 16:29:53 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/So_Long/so_long.h"

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_h)
	{
		x = 0;
		while (x < game->map.map_l)
		{
			put_images(game, y, x);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, \
	game->player.img_k, game->player.pos.x * 16, game->player.pos.y * 16 - 12);
	game->m_count = mlx_put_string(game->mlx, "0", 0, -4);
	return (0);
}

void	put_images(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->sprites.img_w, x * 16, y * 16);
	else if (game->map.map[y][x] == '0')
		mlx_image_to_window(game->mlx, game->sprites.img_g, x * 16, y * 16);
	else if (game->map.map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->sprites.img_g, x * 16, y * 16);
		mlx_image_to_window(game->mlx, game->sprites.img_c, x * 16, y * 16);
	}
	else if (game->map.map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->sprites.img_g, x * 16, y * 16);
	else if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->sprites.img_d, x * 16, y * 16);
}

int	malloc_map(t_game *game, char *str)
{
	int		fd;

	game->map.map_h = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open file");
		return (1);
	}
	get_map_size(game, fd);
	close(fd);
	game->map.map = malloc((game->map.map_h + 1) * sizeof(char *));
	if (!game->map.map)
		return (1);
	game->map.map[game->map.map_h] = NULL;
	return (0);
}

int	fill_map(t_game *game, char *str)
{
	int	fd;
	int	i;

	i = -1;
	if ((malloc_map(game, str) == 1))
		return (1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open file.\n");
		return (1);
	}
	while (++i < game->map.map_h)
	{
		game->map.map[i] = get_next_line(fd);
		if (game->map.map[i] == NULL)
			return (parse_fail());
	}
	close(fd);
	init_map_val(game);
	if ((map_val(game)) == 1)
		return (print_invalid(game->map.map));
	return (0);
}

int	fill_values(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == 'C')
		game->map.c++;
	else if (game->map.map[y][x] == '1')
		game->map.w++;
	else if (game->map.map[y][x] == '0')
		game->map.g++;
	else if (game->map.map[y][x] == 'P')
	{
		game->map.p++;
		game->player.pos.x = x;
		game->player.pos.y = y;
	}
	else if (game->map.map[y][x] == 'E')
	{
		game->map.e++;
		game->exit.x = x;
		game->exit.y = y;
	}
	else
		return (1);
	return (0);
}
