/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:47 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 16:32:11 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/So_Long/so_long.h"

void	get_map_size(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		game->map.map_h++;
	game->map.map_l = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			game->map.map_h++;
	}
}

int	parse_fail(void)
{
	ft_printf("Error\nFailed to parse map");
	return (1);
}

int	print_invalid(char **map)
{
	ft_printf("Error\nInvalid map");
	free_map(map);
	return (1);
}

int	check_arg(int count, char *str)
{
	int	len;

	if (count != 2)
	{
		ft_printf("Error\nWrong number of arguments");
		return (1);
	}
	len = ft_strlen(str);
	if (str[len - 1] == 'r' && str[len - 2] == 'e' \
	&& str[len - 3] == 'b' && str[len - 4] == '.')
		return (0);
	else
		ft_printf("Error\nPlease pass a .ber file");
	return (1);
}
