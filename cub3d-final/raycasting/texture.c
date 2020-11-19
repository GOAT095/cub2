/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:24:57 by anassif           #+#    #+#             */
/*   Updated: 2020/11/19 22:19:29 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	take_textures(t_game *game, t_tex *tex)
{
	int y;
	int x;

	if (!(tex->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		tex->path, &tex->width, &tex->height)))
		return (-1);
	if (!(tex->data = (int *)mlx_get_data_addr(tex->ptr,
		&tex->bpp, &tex->size_l, &tex->endian)))
		return (-1);
	y = -1;
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
			tex->tex[x][y] = (int)tex->data[y * tex->width + x];
	}
	return (1);
}

void		init_textute(t_game *game)
{
	if (take_textures(game, &game->tex[TEX_NO]) < 0)
		log_global_error("North texture is bad ", game);
	if (take_textures(game, &game->tex[TEX_SO]) < 0)
		log_global_error("south texture is bad", game);
	if (take_textures(game, &game->tex[TEX_WE]) < 0)
		log_global_error("westh texture is bad", game);
	if (take_textures(game, &game->tex[TEX_EA]) < 0)
		log_global_error("east texture is bad", game);
	if (take_textures(game, &game->tex[TEX_S]) < 0)
		log_global_error("sprite texture not Sepcfiead or bad", game);
}
