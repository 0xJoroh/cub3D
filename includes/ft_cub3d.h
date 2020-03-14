/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:49:37 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/14 01:51:04 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include "../src/libft/libft.h"

# define BUFFER_SIZE 128
# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define SIZE 64
# define PLAYER_SPEED 15
# define ROTATION_ANGLE 4
# define FOV_ANGLE 60 * (M_PI / 180)

typedef struct		s_sprite
{
	int				id;
	float			x;
	float			y;
	float			distance;
	struct s_sprite *next;
}					t_sprite;

typedef struct		s_bmp
{
	int				width;
	int				height;
	int				bitcount;
	int				width_in_bytes;
	int				imagesize;
	int				bmp_size;
	int				bfoffbits;
	int				filesize;
	int				bi_planes;
	unsigned char	header[54];
}					t_bmp;

typedef	struct		s_texture
{
	void			*xpm_ptr[10];
	int				*data[10];
	int				width[10];
	int				height[10];
	int				bpp;
	int				size_l;
	int				endian;
}					t_texture;

typedef	struct		s_ray
{
	int				is_down;
	int				is_up;
	int				is_right;
	int				is_left;
	float			distance;
	float			angle;
	int				wall_hit;
	float			x_offset;
	float			y_offset;
	float			y;
	float			x;
}					t_ray;

typedef	struct		s_key
{
	int				left;
	int				right;
	int				forward;
	int				backward;
	int				crouch;
	int				quit;
	int				left_view;
	int				right_view;
	int				up_view;
	float			up_angle;
}					t_key;

typedef struct		s_conf
{
	int				r[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**grid;
	unsigned long	f;
	unsigned long	c;
}					t_conf;

typedef struct		s_player
{
	float			x;
	float			y;
}					t_player;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

struct				s_map
{
	char			*scene;
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	char			*line;
	int				grid_width;
	int				grid_height;
	int				sprites;
	int				life_bar;
	t_conf			conf;
	t_player		player;
	t_img			img;
	t_key			key;
	t_ray			ray;
	t_texture		texture;
	t_bmp			bmp;
}					g_map;

t_sprite			**g_sprites;
int					g_sprite_texture;
double				*g_zbuffer;

int					get_next_line(int fd, char **line);
void				setup(char *scene);
void				ft_puterror(char *msg);
int					quit();
void				set_grid();
char				*check_scene(char *scene);
int					check_reso(char c, int res);
void				check_conf();
int					loop_hook();
int					key_releas(int keycode);
int					key_press(int keycode);
float				raycast(float angle);
int					collision(float x, float y, char c);
float				normalize_angle(float angle);
float				radtodeg(float rad);
float				degtorad(float deg);
void				draw_walls(float x, float y, float height, int nbr);
void				draw_floor(float x, float y, int color);
void				draw_ceiling(float x, float end, int color);
void				bmp(const char *argv);
void				draw();
int					grid_width(char *str);
void				textures_init(void);
int					get_player(char c, int x, int y);
void				freeing(char **words);
void				set_conf(void);
float				distance(float x1, float y1, float x2, float y2);
void				sort_sprite();
void				add_sprite(t_sprite **alst, t_sprite *new);
t_sprite			*new_sprite(float x, float y, float distance, char c);
void				generete_sprite();
void				ray_init(float angle);
int					shadow(int color);
int					surounded_walls(int x, int y);
void				render_lifebar(float x, float y, int width, int height);
void				check_collision(void);

#endif
