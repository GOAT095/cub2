/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:24:53 by anassif           #+#    #+#             */
/*   Updated: 2020/11/22 18:59:34 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_sprite(t_game *game, int x, int y)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	game->num_sprite++;
	if (!(sprite = malloc(sizeof(*sprite))))
		error_global(game);
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->texture = TEX_S;
	if (game->sprite)
		sprite->next = game->sprite;
	else
		sprite->next = NULL;
	game->sprite = sprite;
}

static void	sort_sprite(t_sprite **begin)
{
	t_sprite	*sprite;
	t_sprite	*before;
	t_sprite	*next;

	if (*begin)
	{
		sprite = *begin;
		before = 0;
		while (sprite->next)
		{
			next = sprite->next;
			if (sprite->dist < next->dist)
			{
				sprite->next = next->next;
				next->next = sprite;
				if (before)
					before->next = next;
				else
					*begin = next;
				sprite = *begin;
			}
			before = sprite;
			sprite = sprite->next;
		}
	}
}

static void	render_sprite(t_game *game, int spt_size, int x_ofst, int y_ofst)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < spt_size)
	{
		if (x_ofst + i < 0 || x_ofst + i > game->res_x)
			continue ;
		if (game->ray[x_ofst + i].dist <= game->sprite->dist)
			continue ;
		j = -1;
		while (++j < spt_size)
		{
			if (y_ofst + j < 0 || y_ofst + j >= game->res_y)
				continue ;
			color = game->tex[TEX_S].tex[i * game->tex[TEX_S].width / spt_size]
			[j * game->tex[TEX_S].width / spt_size];
			if (color != 0)
				game->img.data[(y_ofst + j) * game->res_x +
					(game->res_x + x_ofst + i)] = color;
		}
	}
}

static void	sprite_position(t_game *game, t_sprite *sprite, t_player *player)
{
	int		spt_size;
	int		x_ofst;
	int		y_ofst;
	float	sprite_dir;

	sprite_dir = atan2(sprite->y - player->y, sprite->x - player->x);
	while (sprite_dir - player->rotate_angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - player->rotate_angle < -M_PI)
		sprite_dir += 2 * M_PI;
	spt_size = game->res_x / sprite->dist;
	x_ofst = (sprite_dir - player->rotate_angle) *
		game->res_x / game->fov + (game->res_x / 2 - spt_size / 2);
	y_ofst = game->res_y / 2 - spt_size / 2;
	render_sprite(game, spt_size, x_ofst, y_ofst);
}

void		generete_sprite(t_game *game, t_player *player)
{
	t_sprite *sprite;

	sprite = game->sprite;
	while (sprite)
	{
		sprite->dist = dist_point(player->x, player->y, sprite->x, sprite->y);
		sprite = sprite->next;
	}
	sort_sprite(&game->sprite);
	sprite = game->sprite;
	while (game->sprite)
	{
		sprite_position(game, game->sprite, player);
		game->sprite = game->sprite->next;
	}
	game->sprite = sprite;
}
