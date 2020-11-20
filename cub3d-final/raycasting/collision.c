/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:24:40 by anassif           #+#    #+#             */
/*   Updated: 2020/11/20 23:24:50 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		player_dir(char cord)
{
	if (cord == 'N')
		return (270);
	else if (cord == 'W')
		return (180);
	else if (cord == 'S')
		return (90);
	else if (cord == 'E')
		return (0);
	return (-1);
}

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		is_sprite(t_map *map, float x, float y)
{
	int row;
	int col;

	row = floor(y / TILE_SIZE);
	col = floor(x / TILE_SIZE);
	if (map->map[row][col] == '2')
		return (1);
	return (0);
}

int		is_wall(t_map *map, float x, float y)
{
	int row;
	int col;

	row = floor(y / TILE_SIZE);
	col = floor(x / TILE_SIZE);
	if (row < 0 || col < 0)
		return (0);
	if (map->map[row][col] == '1')
		return (1);
	return (0);
}
