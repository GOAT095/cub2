/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:22:22 by anassif           #+#    #+#             */
/*   Updated: 2020/11/20 20:57:45 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, int x, int bot, int top)
{
	float	text_x;
	float	text_y;
	int		y;
	int		wall_face;

	if (game->ray[x].is_vert)
	{
		text_x = game->ray[x].wall_y - (int)game->ray[x].wall_y;
		wall_face = game->ray[x].face_lr;
		text_x *= game->tex[wall_face].width;
	}
	else
	{
		text_x = game->ray[x].wall_x - (int)game->ray[x].wall_x;
		wall_face = game->ray[x].face_ud;
		text_x *= game->tex[wall_face].width;
	}
	y = top - 1;
	while (++y < bot)
	{
		text_y = (y + (game->ray[x].stip_height / 2) - (game->res_y / 2)) *
			((double)game->tex[wall_face].width / game->ray[x].stip_height);
		game->img.data[y * game->res_x + x] =
			game->tex[wall_face].tex[(int)text_x][(int)text_y];
	}
}

void	render_ceiling(t_game *game, int x, int top)
{
	while (top >= 0)
	{
		game->img.data[top * game->res_x + x] = game->c;
		top--;
	}
}

void	render_floor(t_game *game, int x, int bot)
{
	while (bot < game->res_y)
	{
		game->img.data[bot * game->res_x + x] = game->f;
		bot++;
	}
}

void	ft_reander_wall(t_game *game, t_player *player)
{
	int		i;
	int		top_pix;
	int		bot_pix;
	float	per_dist;

	i = -1;
	while (++i < game->res_x)
	{
		per_dist = game->ray[i].dist *
			cos(game->ray[i].angle - player->rotate_angle);
		game->ray[i].stip_height = (TILE_SIZE / per_dist) *
			((game->res_x / 2) / (tan(game->fov / 2)));
		top_pix = (game->res_y / 2) - (game->ray[i].stip_height / 2);
		top_pix = (top_pix < 0) ? 0 : top_pix;
		bot_pix = (game->res_y / 2) + (game->ray[i].stip_height / 2);
		bot_pix = (bot_pix > game->res_y) ? game->res_y : bot_pix;
		render_ceiling(game, i, top_pix);
		render_floor(game, i, bot_pix);
		draw_wall(game, i, bot_pix, top_pix);
	}
}
