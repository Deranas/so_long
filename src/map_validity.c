/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:31 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 18:59:34 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/So_Long/so_long.h"

void	init_map_val(t_game *game)
{
	game->map.c = 0;
	game->map.e = 0;
	game->map.g = 0;
	game->map.p = 0;
	game->map.w = 0;
	game->game_end = 0;
	game->player.move = 0;
	game->map.ex_acc = 0;
	game->map.c_acc = 0;
}

int	map_val(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_h)
	{
		x = 0;
		while (x < game->map.map_l)
		{
			if ((fill_values(game, y, x) == 1))
				return (1);
			x++;
		}
		y++;
	}
	if ((check_val_input(game)) == 1)
		return (1);
	if ((check_val_level(game)) == 1)
		return (1);
	return (0);
}

int	check_val_input(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.c < 1 || game->map.p != 1 || game->map.e != 1)
		return (1);
	while (game->map.map[++i])
	{
		if (ft_strlen(game->map.map[i]) != ft_strlen(game->map.map[i - 1]))
			return (1);
	}
	i = -1;
	while (++i < game->map.map_h)
	{
		if (game->map.map[i][0] != '1' || \
		game->map.map[i][game->map.map_l - 1] != '1')
			return (1);
	}
	i = -1;
	while (++i < game->map.map_l)
	{
		if (game->map.map[0][i] != '1' || \
		game->map.map[game->map.map_h - 1][i] != '1')
			return (1);
	}
	return (0);
}

int	check_val_level(t_game *game)
{
	char	**map_dup;
	int		i;

	i = -1;
	map_dup = malloc((game->map.map_h + 1) * sizeof(char *));
	if (!map_dup)
		return (parse_fail());
	while (++i < game->map.map_h)
	{
		map_dup[i] = ft_strdup(game->map.map[i]);
		if (map_dup[i] == NULL)
			return (parse_fail());
	}
	map_dup[i] = NULL;
	dfs(game, map_dup, game->player.pos.x, game->player.pos.y);
	free_map(map_dup);
	if (game->map.c_acc == game->map.c && game->map.ex_acc == 1)
		return (0);
	else
		return (1);
}

void	dfs(t_game *game, char **map, int x, int y)
{
	if (game->map.c_acc == game->map.c && game->map.ex_acc == 1)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
	{
		game->map.c_acc++;
		map[y][x] = '1';
	}
	if (map[y][x] == 'E')
	{
		game->map.ex_acc = 1;
		map[y][x] = '1';
	}
	if (map[y][x] == '0' || map[y][x] == 'P')
		map[y][x] = '1';
	dfs(game, map, x + 1, y);
	dfs(game, map, x - 1, y);
	dfs(game, map, x, y + 1);
	dfs(game, map, x, y - 1);
	return ;
}
