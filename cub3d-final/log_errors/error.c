/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:24:22 by anassif           #+#    #+#             */
/*   Updated: 2020/11/22 19:33:33 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	log_global_error(char *s, t_game *game)
{
	ft_putstr_fd("\033[1;31mERROR\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	error_global(t_game *game)
{
	ft_putstr_fd(strerror(errno), 2);
	free_game(game);
	exit(EXIT_FAILURE);
}

void	error_global_close_fd(int fd, t_game *game)
{
	ft_putstr_fd(strerror(errno), 2);
	close(fd);
	free_game(game);
	exit(EXIT_FAILURE);
}
