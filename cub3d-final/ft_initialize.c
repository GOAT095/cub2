/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:23:06 by anassif           #+#    #+#             */
/*   Updated: 2020/11/23 18:08:50 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_comma(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	return (j);
}

t_map			map_initialization(void)
{
	t_map map;

	map.map_row = 0;
	map.map_col = 0;
	map.player_x = -1;
	map.player_y = -1;
	map.map = NULL;
	return (map);
}

t_player		player_initialization(void)
{
	t_player player;

	player.y = 0;
	player.x = 0;
	player.turn_dir_r = 0;
	player.turn_dir_l = 0;
	player.walk_dir_u = 0;
	player.walk_dir_d = 0;
	player.straf_r = 0;
	player.straf_l = 0;
	player.rotate_angle = 0.0;
	player.move_speed = MOVE_SPEED;
	player.rotate_speed = ROTATE_SPEED * (M_PI / 180);
	return (player);
}

t_ray			inisialize_ray(t_ray ray, float ray_angle)
{
	ray.angle = norm_angle(ray_angle);
	ray.wall_x = 0;
	ray.wall_y = 0;
	ray.dist = 0;
	ray.is_vert = 0;
	ray.face_ud = (ray.angle > 0 && ray.angle < M_PI) ? FAC_DOWN : FAC_UP;
	ray.face_lr = (ray.angle < 0.5 * M_PI || ray.angle > 1.5 * M_PI) ?
	FAC_RIGHT : FAC_LEFT;
	return (ray);
}

t_game			*game_initialization(void)
{
	t_game *game;

	if (!(game = malloc(sizeof(*game))))
		error_global(game);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->res_x = 0;
	game->res_y = 0;
	game->f = -1;
	game->c = -1;
	game->num_sprite = 0;
	game->sprite = NULL;
	game->map = map_initialization();
	game->player = player_initialization();
	game->fov = (FOV * (M_PI / 180));
	game->save = 0;
	return (game);
}
