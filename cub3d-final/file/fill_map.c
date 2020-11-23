/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:11:06 by anassif           #+#    #+#             */
/*   Updated: 2020/11/23 18:08:39 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_numbers(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	i -= 1;
	if (i > 2)
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

void	fill_4(int player, int i, int j, t_game *game)
{
	i = 0;
	while (i < game->map.map_row)
	{
		j = 0;
		while (j < game->map.map_col)
		{
			if (ft_strcontaines(PLAYER_INIT_POS, game->map.map[i][j]))
			{
				game->map.player_dir = player_dir(game->map.map[i][j]);
				game->map.player_x = j + 0.5;
				game->map.player_y = i + 0.5;
				player++;
			}
			if (player > 1)
			{
				game->map.player_x = -1;
				game->map.player_y = -1;
			}
			if (game->map.map[i][j] == '2')
				init_sprite(game, j, i);
			j++;
		}
		i++;
	}
}

void	fill_3(int i, int j, t_game *game)
{
	int player;

	i = 0;
	while (i < game->map.map_row)
	{
		j = 0;
		while (j < game->map.map_col)
		{
			if (game->map.map[i][j] == ' ')
				game->map.map[i][j] = '1';
			if (!strchr(MAP_GAME, game->map.map[i][j])
			&& game->map.map[i][j] != ' ')
				log_global_error("map error", game);
			j++;
		}
		i++;
	}
	i = 0;
	player = 0;
	fill_4(player, i, j, game);
}

void	fill_2(int fd, int i, int j, t_game *game)
{
	char	*line;
	int		ret;

	ret = 0;
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		ft_memcpy(game->map.map[i], line, ft_strlen(line));
		i++;
		free(line);
	}
	ft_memcpy(game->map.map[i], line, ft_strlen(line));
	free(line);
	i = -1;
	while (game->map.map[++i])
	{
		j = 0;
		while (game->map.map[i][++j])
		{
			if ((game->map.map[i][j] == '0' || game->map.map[i][j] == '2'
			|| game->map.map[i][j] == 'S'
			|| game->map.map[i][j] == 'N' || game->map.map[i][j] == 'E'
			|| game->map.map[i][j] == 'W') && round_check(i, j, game))
				log_global_error("map error", game);
		}
	}
}
