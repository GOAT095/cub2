/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:23:34 by anassif           #+#    #+#             */
/*   Updated: 2020/11/20 18:38:49 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isallnumber(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void		ft_print_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.map_row)
	{
		ft_putstr_fd(game->map.map[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int			round_check(int i, int j, t_game *game)
{
	if (!ft_strchr("SNEW012", game->map.map[i - 1][j])
	|| !ft_strchr("SNEW012", game->map.map[i][j - 1])
	|| !ft_strchr("SNEW012", game->map.map[i][j + 1])
	|| !ft_strchr("SNEW012", game->map.map[i + 1][j]))
		return (1);
	return (0);
}

void		check_tex(t_game *game)
{
	if (game->tex[TEX_NO].path == NULL)
		log_global_error("north texture is missing  or missing next param"
		, game);
	if (game->tex[TEX_SO].path == NULL)
		log_global_error("SOUTH texture is missing  or missing next param"
		, game);
	if (game->tex[TEX_WE].path == NULL)
		log_global_error("WEST texture is missing  or missing next param"
		, game);
	if (game->tex[TEX_EA].path == NULL)
		log_global_error("EAST texture is missing  or missing next param"
		, game);
	if (game->tex[TEX_S].path == NULL)
		log_global_error("SPRITE texture is missing or missing next param"
		, game);
}

void		check_game(t_game *game, t_map *map)
{
	if (game->res_x > DEFAULT_X || game->res_y > DEFAULT_Y)
	{
		game->res_x = DEFAULT_X;
		game->res_y = DEFAULT_Y;
	}
	check_tex(game);
	if (game->res_x < 100 || game->res_y < 100)
		log_global_error("Resolution is to small or incorrect", game);
	if (game->f < 0)
		log_global_error("Unvalid floor color or missing next param", game);
	if (game->c < 0)
		log_global_error("Unvalid ceiling color, or missing map", game);
	if (map->player_x == -1 || map->player_y == -1)
		log_global_error("Unvalid player position on map", game);
}
