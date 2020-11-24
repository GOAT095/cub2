/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:23:56 by anassif           #+#    #+#             */
/*   Updated: 2020/11/24 23:58:37 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(char *file, int fd, int ret, t_game *game)
{
	char	*line;
	char	*x;
	int		i;
	int		j;

	i = 2;
	j = 2;
	close(fd);
	fd = open(file, O_RDONLY);
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		x = ft_strtrim(line, " ");
		if (x[0] == '1')
		{
			ft_memcpy(game->map.map[i++], line, ft_strlen(line));
			free(line);
			break ;
		}
		free(line);
		free(x);
	}
	free(x);
	fill_2(fd, i, j, game);
	fill_3(i, j, game);
}

void	get_big_2(int i, int j, t_game *game)
{
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.map_row + 3));
	while (i < game->map.map_row)
	{
		j = 0;
		game->map.map[i] = (char *)malloc(game->map.map_col + 3);
		while (j < game->map.map_col)
		{
			game->map.map[i][j] = ' ';
			j++;
		}
		game->map.map[i][j] = '\0';
		i++;
	}
	game->map.map[i] = NULL;
}

int		get_big_line(int fd, char *line, char *file, t_game *game)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	game->map.map_row = 1;
	game->map.map_col = ft_strlen(line);
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		game->map.map_col = ((int)ft_strlen(line) > game->map.map_col
		? ft_strlen(line) : game->map.map_col);
		game->map.map_row++;
		free(line);
	}
	free(line);
	game->map.map_row++;
	game->map.map_row += 2;
	game->map.map_col += 2;
	get_big_2(i, j, game);
	fill_map(file, fd, ret, game);
	return (0);
}

void	ft_compare(char *line, t_game *game)
{
	if (*line == 'R')
		read_resolution(line, game);
	else if (line[0] == 'N' && line[1] == 'O')
		game->tex[TEX_NO].path = read_path(&line[2], game);
	else if (line[0] == 'S' && line[1] == 'O')
		game->tex[TEX_SO].path = read_path(&line[2], game);
	else if (line[0] == 'W' && line[1] == 'E')
		game->tex[TEX_WE].path = read_path(&line[2], game);
	else if (line[0] == 'E' && line[1] == 'A')
		game->tex[TEX_EA].path = read_path(&line[2], game);
	else if (line[0] == 'S')
		game->tex[TEX_S].path = read_path(&line[1], game);
	else if (*line == 'F')
		game->f = read_floor_ceiling(&line[1], game);
	else if (*line == 'C')
		game->c = read_floor_ceiling(&line[1], game);
	else if (!check_input(line))
		log_global_error("invalide paremetre", game);
	if (game->params > 8)
		log_global_error("there is a duplicate paremeter", game);
}

int		parse_file_game(int fd, char *line, t_game *game, char *file)
{
	int		ret;
	char	*x;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_compare(line, game);
		x = ft_strtrim(line, " ");
		if (x && x[0] == '1')
		{
			get_big_line(fd, line, file, game);
			free(x);
			break ;
		}
		free(x);
		free(line);
	}
	free(line);
	if (ret == 0)
		log_global_error("the cub file is empty !!!!!", game);
	return (ret);
}
