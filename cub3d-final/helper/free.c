/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:24:05 by anassif           #+#    #+#             */
/*   Updated: 2020/11/23 22:35:15 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->map.map_row)
		free(game->map.map[i]);
	free(game->map.map);
	i = -1;
	while (++i < NB_TEXTURE)
	{
		mlx_destroy_image(game->mlx_ptr, game->tex[i].ptr);
		free(game->tex[i].path);
	}
	if (game->sprite)
		free_sprite(&game->sprite);
	mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game);
}

void	free_game(t_game *game)
{
	int i;

	if (game->map.map)
	{
		i = -1;
		while (++i < game->map.map_row)
			free(game->map.map[i]);
		free(game->map.map);
	}
	free(game);
}

void	free_sprite(t_sprite **begin)
{
	t_sprite	*sp;
	t_sprite	*next;

	sp = *begin;
	while (sp)
	{
		next = sp->next;
		free(sp);
		sp = next;
	}
	*begin = NULL;
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
