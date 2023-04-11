/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:31:31 by aschmid           #+#    #+#             */
/*   Updated: 2023/03/30 16:35:10 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../Libft/libft.h"

typedef struct s_point {
	size_t	x;
	size_t	y;
}				t_point;

typedef struct s_map {
	char	**map;
	int		map_h;
	int		map_l;
	int		c;
	int		w;
	int		g;
	int		e;
	int		p;
	int		ex_acc;
	int		c_acc;
}				t_map;

typedef struct s_player {
	t_point			pos;
	mlx_texture_t	*k;
	mlx_image_t		*img_k;
	int				move;
}				t_player;

typedef struct s_textures {
	mlx_image_t		*img_w;
	mlx_texture_t	*w;
	mlx_image_t		*img_d;
	mlx_texture_t	*d;
	mlx_image_t		*img_c;
	mlx_texture_t	*c;
	mlx_image_t		*img_g;
	mlx_texture_t	*g;
}					t_textures;

typedef struct s_game {
	mlx_t			*mlx;
	t_map			map;
	t_player		player;
	t_textures		sprites;
	mlx_image_t		*m_count;
	t_point			exit;
	int				game_end;
}	t_game;

//helper
int		check_arg(int count, char *str);
int		print_invalid(char **map);
void	get_map_size(t_game *game, int fd);
int		parse_fail(void);

//logic
int		check_collision(t_game *game, int x, int y);
void	update_map(t_game *game, int x, int y);
void	check_end(t_game *game);
void	put_move_count(t_game *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);

// load and free functions
void	load_textures(t_game *game);
void	free_textures(t_game *game);
void	free_map(char **map);
void	redraw_char(t_game *game, int x, int y);

// build map
int		fill_map(t_game *game, char *str);
int		malloc_map(t_game *game, char *str);
int		fill_values(t_game *game, int y, int x);
int		draw_map(t_game *game);
void	put_images(t_game *game, int y, int x);

// map validity
void	init_map_val(t_game *game);
int		map_val(t_game *game);
int		check_val_level(t_game *game);
void	dfs(t_game *game, char **map, int x, int y);
int		check_val_input(t_game *game);

#endif