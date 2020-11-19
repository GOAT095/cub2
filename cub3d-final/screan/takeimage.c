/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeimage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:25:13 by anassif           #+#    #+#             */
/*   Updated: 2020/11/19 23:15:10 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_all_data(t_game *game, t_bitmap *bmp)
{
	bmp->pd_offset = 54;
	bmp->header_size = 40;
	bmp->image_width = game->res_x;
	bmp->image_height = game->res_y;
	bmp->bpp = 24;
	bmp->width_in_bytes = ((bmp->image_width * bmp->bpp + 31) / 23) * 4;
	bmp->planes = 1;
	bmp->image_size = bmp->width_in_bytes * bmp->image_height;
	bmp->file_size = 54 + bmp->image_size;
}

static void	set_header(unsigned char *buffer, t_bitmap *bmp)
{
	ft_memcpy(buffer, "BM", 2);
	ft_memcpy(buffer + 2, &(bmp->file_size), 4);
	ft_memcpy(buffer + 10, &(bmp->pd_offset), 4);
	ft_memcpy(buffer + 14, &(bmp->header_size), 4);
	ft_memcpy(buffer + 18, &(bmp->image_width), 4);
	ft_memcpy(buffer + 22, &(bmp->image_height), 4);
	ft_memcpy(buffer + 26, &(bmp->planes), 2);
	ft_memcpy(buffer + 28, &(bmp->bpp), 2);
	ft_memcpy(buffer + 34, &(bmp->image_size), 4);
}

static void	fill_buff(int fd, t_game *game)
{
	int xy[2];
	int x2;

	xy[1] = game->res_y;
	while (--xy[1] >= 0)
	{
		xy[0] = game->res_x;
		x2 = 0;
		while (--xy[0] >= 0)
		{
			write(fd, &game->img.data[xy[1] * game->res_x + x2], 3);
			x2++;
		}
	}
}

void		create_bmp(t_game *game)
{
	int				fd;
	t_bitmap		bmp;
	unsigned char	header[54];

	loop_cub3d(game);
	init_all_data(game, &bmp);
	fd = open("image.bmp", O_RDWR | O_CREAT, 500);
	set_header(header, &bmp);
	write(fd, header, 54);
	fill_buff(fd, game);
	close(fd);
	free_all(game);
}
