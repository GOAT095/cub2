/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:43:12 by anassif           #+#    #+#             */
/*   Updated: 2020/11/20 17:26:49 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				loop_game(t_game *game)
{
	player_movement(&game->map, &game->player);
	caste_all_ray(game, &game->player);
	ft_reander_wall(game, &game->player);
	generete_sprite(game, &game->player);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr,
	0, 0);
	return (0);
}

static	void	window_init(t_game *game, t_img *img)
{
	if (!(game->mlx_ptr = mlx_init()))
		error_global(game);
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr,
		game->res_x, game->res_y, "cub3d")))
		error_global(game);
	img->img_ptr = mlx_new_image(game->mlx_ptr, game->res_x, game->res_y);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
	&img->size_l, &img->endian);
}

int				main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2 || ac > 3)
		log_global_error("number of argument should be 2 or 3", NULL);
	game = game_initialization();
	read_file_game(av[1], (ac == 3 ? av[2] : "rerre"), game);
	window_init(game, &game->img);
	init_player_on_map(&game->map, &game->player);
	init_textute(game);
	keys_set(game);
	mlx_loop_hook(game->mlx_ptr, loop_game, game);
	if (game->save == 1)
		create_bmp(game);
	else
		mlx_loop(game->mlx_ptr);
	return (0);
}
