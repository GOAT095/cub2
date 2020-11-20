/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:20:27 by anassif           #+#    #+#             */
/*   Updated: 2020/11/20 17:27:29 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../libft/libft.h"
# define DEFAULT_X 2560
# define DEFAULT_Y 1395
# define MAP_GAME "012NSEW"
# define PLAYER_INIT_POS "NSEW"
# define TILE_SIZE 1
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define SPACE 49
# define SHIFHT 257
# define L_AROW 123
# define R_AROW	124
# define MOVE_SPEED 0.13
# define ROTATE_SPEED 2.7
# define FOV 60
# define RUN_SPEED 0.131
# define RUN_ROTATE_SPEED 2.72
# define STRAF_FACTOR 2
# define NB_TEXTURE 5
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4
# define TEXTURE_SIZE 663
# define FAC_UP 0
# define FAC_DOWN 1
# define FAC_LEFT 2
# define FAC_RIGHT 3

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_bitmap
{
	unsigned int	file_size;
	unsigned int	pd_offset;
	unsigned int	header_size;
	unsigned int	image_width;
	unsigned int	image_height;
	unsigned int	image_size;
	unsigned short	planes;
	unsigned short	bpp;
	int				width_in_bytes;
}				t_bitmap;

typedef struct	s_tex
{
	int		tex[2500][2500];
	char	*path;
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
}				t_tex;

typedef struct	s_ray
{
	float		angle;
	float		wall_x;
	float		wall_y;
	float		dist;
	int			is_vert;
	int			face_ud;
	int			face_lr;
	int			stip_height;
	int			wall_content;
}				t_ray;

typedef struct	s_map
{
	char		**map;
	int			map_row;
	int			map_col;
	float		player_x;
	float		player_y;
	float		player_dir;
}				t_map;

typedef struct	s_player
{
	float		x;
	float		y;
	int			turn_dir_r;
	int			turn_dir_l;
	int			walk_dir_u;
	int			walk_dir_d;
	int			straf_r;
	int			straf_l;
	float		rotate_angle;
	float		move_speed;
	float		rotate_speed;

}				t_player;

typedef struct	s_sprite
{
	float			x;
	float			y;
	float			dist;
	int				texture;
	struct s_sprite *next;
}				t_sprite;

typedef struct	s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				res_x;
	int				res_y;
	int				f;
	int				c;
	float			fov;
	int				save;
	int				num_sprite;
	struct s_map	map;
	struct s_player player;
	t_img			img;
	t_sprite		*sprite;
	t_ray			ray[DEFAULT_X];
	t_tex			tex[NB_TEXTURE];
}				t_game;

void			check_game(t_game *game, t_map *map);
void			read_file_game(char *file, char *save, t_game *game);
int				parse_file_game(int fd, char *line, t_game *game, char *file);
int				keys_set(t_game *game);
int				loop_game(t_game *game);
void			screen_shot(t_game *game);
void			init_sprite(t_game *game, int x, int y);
void			init_textute(t_game *game);
void			generete_sprite(t_game *game, t_player *player);
void			caste_all_ray(t_game *game, t_player *player);
void			ft_reander_wall(t_game *game, t_player *player);
t_game			*game_initialization(void);
int				is_sprite(t_map *map, float x, float y);
int				is_wall(t_map *map, float x, float y);
void			ft_print_map(t_game *game);
void			error_global(t_game *game);
void			error_global_close_fd(int fd, t_game *game);
void			free_all(t_game *game);
void			free_game(t_game *game);
void			free_sprite(t_sprite **begin);
void			init_player_on_map(t_map *map, t_player *player);
void			player_movement(t_map *map, t_player *player);
t_ray			inisialize_ray(t_ray ray, float ray_angle);
void			log_global_error(char *s, t_game *game);
void			render_player(t_game *game, t_player *player);
void			render_map(t_game *game, t_map *map);
void			free_split(char **split);
int				ft_isallnumber(char *split);
int				round_check(int i, int j, t_game *game);
void			render_ray(t_game *game);
int				ft_strcontaines(char *set, char c);
float			norm_angle(float angle);
float			dist_point(float x1, float y1, float x2, float y2);
float			deg_to_rad(float deg);
float			rad_to_deg(float rad);
void			create_bmp(t_game *game);
int				player_dir(char cord);
char			*read_path(char *line);
void			read_resolution(char *line, t_game *game);
int				check_floor_ceilling(char **split);
int				read_floor_ceiling(char *line);
void			fill_4(int player, int i, int j, t_game *game);
void			fill_3(int i, int j, t_game *game);
void			fill_2(int fd, int i, int j, t_game *game);
#endif
