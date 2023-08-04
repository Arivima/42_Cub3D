/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <avilla-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:45 by avilla-m          #+#    #+#             */
/*   Updated: 2023/08/04 21:37:46 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES
# include "mlx.h"
# include "libft.h"
# include <unistd.h> // write, free, close, read
# include <math.h> // math lib
# include <sys/types.h> // open
# include <sys/stat.h> // open
# include <fcntl.h> // open
# include <stdio.h> // printf
# include <stdlib.h> // malloc, exit
# include <errno.h> // perror strerror

// DEFINES
// maths
# define _USE_MATH_DEFINES
# define M_2PI		6.28318530718				/* 2 pi		: 360 deg */
// # define M_PI		3.14159265358979323846	/* pi		: 180 deg */
// # define M_PI_2		1.57079632679489661923	/* pi/2		: 90 deg */
// # define M_PI_4		0.78539816339744830962	/* pi/4		: 45 deg */
# define M_PI_8 0.39269908169					/* pi/8		: 22.5 deg */
# define M_PI_16 0.19634954084					/* pi/16	: 11.25 deg */
# define M_PI_32 0.09817477042					/* pi/32	: 5.625 deg */
# define M_PI_64 0.04908738521 					/* pi/64	: 2.8125 deg */

// colors
# define BLACK (0x00000000)
# define WHITE (0x00FFFFFF)
# define RED (0x00FF0000)
# define GREEN (0x00008000)
# define YELLOW (0x00FFFF00)
# define BLUE (0x000000FF)
# define GREY (0x00B8B8B8)
# define RED_BERRY (0x00B8255F)
# define RED_POPPY (0x00EB3845)
# define GREEN_MINT (0x006ACCBC)
# define GREEN_TEAL (0x00158FAD)
# define BLUE_LIGHT (0x0096C3EB)
# define BLUE_BETTER (0x004373FF)
# define YELLOW_SUNNY (0x00FFCE30)
# define YELLOW_GOLD (0x00BBA14F)
// palette mandatory
# define GREY_DARK (0x002a2d34)
# define GREY_MIDDLE (0x0023262d)
# define GREY_LIGHT (0x00383c45)
# define GOLD_PALE (0x00b69352)
# define GOLD_LIGHT (0x00d3b977)
# define BROWN (0x00756341)
# define BLUE_GREY (0x003b444b)

# define BLANC_CASSE (0x00f2f2f1)
# define TAUPE (0x00d9bb9c)
# define BEIGE (0x00f1e2cc)
# define GOLD_WHITE (0x00f2d493)
# define PINK_GOLD (0x00e9d3c4)
# define WHITE_GREY (0x00dcdfde)

// keycodes
// # define KEYCODE_DELETE 51
# define KEYCODE_SPACE_BAR 49
# define KEYCODE_B 11
# define KEYCODE_ENTER 36
# define KEYCODE_CAM_LEFT 123
# define KEYCODE_CAM_RIGHT 124
# define KEYCODE_LEFT 2
# define KEYCODE_RIGHT 0
# define KEYCODE_DOWN 1
# define KEYCODE_UP 13
# define KEYCODE_ESC 53

// movement
# define MOVE_FORWARD 0
# define MOVE_BACKWARD 180
# define MOVE_LEFTWARD 90
# define MOVE_RIGHTWARD 270
# define ROTATE_LEFT (-1)
# define ROTATE_RIGHT 1
# define ROTATE_ANGLE (M_PI_8)

// MAP
# define EMPTY '0'
# define WALL '1'
# define DOOR_OPEN '2'
# define DOOR_CLOSED '3'
# define SPRITE '4'
# define ENEMY '5'
// TEXT
# define TEXT_START_X 20
# define TEXT_START_Y 20
# define COLOR_TEXT (GOLD_PALE)

# define GREY_DARK (0x002a2d34)
# define GREY_MIDDLE (0x0023262d)
# define GREY_LIGHT (0x00383c45)
# define GOLD_PALE (0x00b69352)
# define GOLD_LIGHT (0x00d3b977)
# define BROWN (0x00756341)
# define BLUE_GREY (0x003b444b)

# define BLANC_CASSE (0x00f2f2f1)
# define TAUPE (0x00d9bb9c)
# define BEIGE (0x00f1e2cc)
# define GOLD_WHITE (0x00f2d493)
# define PINK_GOLD (0x00e9d3c4)
# define WHITE_GREY (0x00dcdfde)
// 2D
# define START_2D_X 20
# define START_2D_Y 30
# define MAX_2D_LEN 400 //  sets maximum size of 2Dmap
# define COLOR_VOID RED_BERRY
# define COLOR_EMPTY GREY_DARK
# define COLOR_BORDER GOLD_PALE
# define COLOR_WALLS GOLD_PALE

# define COLOR_DOORS GOLD_LIGHT
# define COLOR_PLAYER RED_POPPY
# define COLOR_ENEMY BLACK
# define COLOR_SPRITE WHITE_GREY
# define COLOR_RAYCASTING BLANC_CASSE
# define COLOR_WALL_NORTH (PINK_GOLD)
# define COLOR_WALL_SOUTH (BEIGE)
# define COLOR_WALL_EAST (TAUPE)
# define COLOR_WALL_WEST (WHITE_GREY)
# define COLOR_WALL_ANGLE (GOLD_WHITE)

// 3D
# define START_3D_X 	0
# define START_3D_Y 	0
# define END_3D_Y 		(WIN_HEIGHT)
# define MAX_3D_WALL 	(WIN_HEIGHT)

// RAYCASTING hit point storage 
// (hold.hit[i][WIN_WIDTH])
# define IX 0
# define IY 1
# define DIS 2
# define WALL_ORIENTATION 3
# define DOOR 4

enum	e_wall_orientation
{
	e_wall_north,
	e_wall_east,
	e_wall_south,
	e_wall_west,
	e_wall_angle,
	e_wall_other,
};

// custom project settings
# define NAME "Cub3D"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOV 1.15192 // = 66 degree
# define FOV_D 66
# define FOV_R 0.66
# define ERR -1
# define DEBUG 0

// here we add only files from folder ./sprites/ that we will need to use
# define IMG_FILES "\
files/door_00.xpm\n\
files/door_earth.xpm\n\
files/door_moon.xpm\n\
files/background_earth.xpm\n\
files/background_moon.xpm\n\
files/wall_earth.xpm\n\
files/wall_moon.xpm\n\
files/screen_win_mandatory.xpm\n\
files/screen_lost_mandatory.xpm\n\
files/animation/animation_00_00.xpm\n\
files/animation/animation_00_01.xpm\n\
files/animation/animation_00_02.xpm\n\
files/animation/animation_00_03.xpm\n\
files/animation/animation_00_04.xpm\n\
files/animation/animation_01_00.xpm\n\
files/animation/animation_01_01.xpm\n\
files/animation/animation_01_02.xpm\n\
files/animation/animation_01_03.xpm\n\
files/animation/animation_01_04.xpm\n\
files/animation/animation_01_05.xpm\n\
files/animation/animation_01_06.xpm\n\
files/animation/animation_01_07.xpm\n\
files/animation/animation_01_08.xpm\n\
files/animation/animation_02_00.xpm\n\
files/animation/animation_02_01.xpm\n\
files/animation/animation_02_02.xpm\n\
files/animation/animation_02_03.xpm\n\
files/animation/animation_02_04.xpm\n\
files/animation/animation_03.xpm\n\
files/animation/animation_04_00.xpm\n\
files/animation/animation_04_01.xpm\n\
files/animation/animation_04_02.xpm\n\
files/animation/animation_04_03.xpm\n\
files/animation/animation_04_04.xpm\n\
files/animation/animation_04_05.xpm\n\
files/animation/animation_04_06.xpm\n\
files/animation/animation_04_07.xpm\n\
files/animation/animation_04_08.xpm\n\
files/animation/animation_04_09.xpm\n\
files/animation/animation_04_10.xpm\n\
files/animation/animation_04.xpm\n"

// here we identify any file listed above, in the same order
enum	e_picture_list
{
	e_PIC_DOOR_00,
	e_PIC_DOOR_EARTH,
	e_PIC_DOOR_MOON,
	e_PIC_BACKGROUND_EARTH,
	e_PIC_BACKGROUND_MOON,
	e_PIC_WALL_EARTH,
	e_PIC_WALL_MOON,
	e_PIC_WIN_00,
	e_PIC_LOST_00,
	e_PIC_ANIMATION_00_00,
	e_PIC_ANIMATION_00_01,
	e_PIC_ANIMATION_00_02,
	e_PIC_ANIMATION_00_03,
	e_PIC_ANIMATION_00_04,
	e_PIC_ANIMATION_01_00,
	e_PIC_ANIMATION_01_01,
	e_PIC_ANIMATION_01_02,
	e_PIC_ANIMATION_01_03,
	e_PIC_ANIMATION_01_04,
	e_PIC_ANIMATION_01_05,
	e_PIC_ANIMATION_01_06,
	e_PIC_ANIMATION_01_07,
	e_PIC_ANIMATION_01_08,
	e_PIC_ANIMATION_02_00,
	e_PIC_ANIMATION_02_01,
	e_PIC_ANIMATION_02_02,
	e_PIC_ANIMATION_02_03,
	e_PIC_ANIMATION_02_04,
	e_PIC_ANIMATION_03_00,
	e_PIC_ANIMATION_04_00,
	e_PIC_ANIMATION_04_01,
	e_PIC_ANIMATION_04_02,
	e_PIC_ANIMATION_04_03,
	e_PIC_ANIMATION_04_04,
	e_PIC_ANIMATION_04_05,
	e_PIC_ANIMATION_04_06,
	e_PIC_ANIMATION_04_07,
	e_PIC_ANIMATION_04_08,
	e_PIC_ANIMATION_04_09,
	e_PIC_ANIMATION_04_10,
	e_PIC_ANIMATION_05_00,
};

// game level
# define LEVEL_MANDATORY 0
# define LEVEL_OPENING 1
# define LEVEL_EARTH 2
# define LEVEL_TRANSITION 3
# define LEVEL_MOON 4
# define LEVEL_ENDING_LOST 5
# define LEVEL_ENDING_WIN 6
# define LEVEL_CREDITS 7
# define LEVEL_TEXT "42 CUB3D MANDATORY PART | PRESS 'SPACE' TO ENTER BONUS PART#\
42 CUB3D BONUS | THE TALES OF PRINCESS KAGUYA\nPRESS 'SPACE' TO START#\
EARTH LEVEL | PRESS 'SPACE' TO SKIP TO NEXT LEVEL#\
LEVEL 1 COMPLETED\nPRESS 'SPACE' TO NEXT LEVEL#\
MOON LEVEL | PRESS 'SPACE' TO SKIP TO NEXT LEVEL#\
YOU HAVE LOST ...| PRESS 'SPACE' TO START AGAIN#\
YOU HAVE WON ! | PRESS 'SPACE' TO START AGAIN#\
THANK YOU FOR PLAYING THE TALES OF PRINCESS KAGUYA\nCREDITS \
AVILLA-M GDI-LORE\nPRESS 'SPACE' TO START AGAIN"

// orientation
# define NO 0
# define WE 1
# define SO 2
# define EA 3
// STRUCTURES

typedef struct s_point
{
	int		x;
	int		y;
}				t_pt;

typedef struct s_point_d
{
	float	x;
	float	y;
}				t_pt_d;

typedef struct s_vec3
{
	int		r;
	int		g;
	int		b;
}		t_vec3;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_tex
{
	int		charged;
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bp;
	int		sl;
	int		en;
}			t_tex;

typedef struct s_bres
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	ab;
	int	ai;
}				t_bres;

typedef struct s_ray
{
	t_pt_d	delta_dist;
	t_pt_d	side_dist;
	t_pt_d	ray_dir;
	t_pt	step;
	int		side;
}		t_ray;

typedef struct s_sprite
{
	float	x;
	float	y;
	int		n_spr;
	int		type;
	float	dis;
}			t_sprite;

typedef struct s_render
{
	t_pt_d		trasf;
	t_pt		sprite_screen;
	t_pt		sprite_size;
	t_pt		draw_start;
	t_pt		draw_end;
	t_sprite	*sprite;
}				t_render;

typedef struct s_hold
{
	int			fd;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_tex		**tex;
	t_tex		**pics;
	int			floor;
	int			ceiling;
	int			dir[4][2];
	int			game_level;
	int			f_game_over;
	int			counter_sprite;
	char		**map;
	char		**storedmap;
	int			map_w;
	int			map_h;
	int			pos_x;
	int			pos_y;
	float		pos_a;
	int			ppu;
	int			pix_x;
	int			pix_y;
	t_pt_d		pl_w;
	t_pt		pl_map;
	float		hit[5][WIN_WIDTH];
	void		*mlx;
	void		*win;
	int			w_width;
	int			w_height;
	char		*w_name;
	t_img		*img;
	int			mouse_block;
	t_pt		mouse_start;
	int			gif_block;
	int			gif_start;
	int			gif_end;
	int			git_iter;
	int			gif_frame;
	int			pause_game;
	t_sprite	**sprites;
	t_tex		**tex_sprite;
	t_vlist		*sprite_list;
	int			bonus_start;
	int			afplay_pid;
}				t_hold;

// PROTOTYPES

// PARSING & INIT
int		parsing(int ac, char **av, t_hold *hold);
int		ft_parse_arguments(t_hold *hold);
int		is_valid_path(char *path);
int		ft_preparse_map(t_hold *hold, t_vlist **preparse);
int		ft_parse_map(t_hold *hold, t_vlist *preparse);
int		ft_check_map(t_hold *hold);
// init
int		check_arg(int ac, char **av, t_hold *hold);
int		init_holder(t_hold *hold);

// init
int		ft_init(t_hold *hold);
int		ft_init_holder(t_hold *hold);
int		ft_init_mlx_win_img(t_hold *hold);
float	ft_init_angle_direction(int c);
int		ft_init_2D_map(t_hold *hold);
// init_map
int		ft_init_map_pt(t_hold *hold);

// EXECUTION
int		ft_execution(t_hold *hold);
int		ft_put_world(t_hold *hold);
int		ft_mlx_put_new_img(t_hold *hold);
int		ft_put_display(t_hold *hold);
int		ft_put_text(t_hold *hold);
//		raycasting
int		ft_raycasting(t_hold *hold);
int		ft_line_bresenham_hit(t_hold *hold, t_pt a, t_pt b, int j);
int		ft_store_hit_data(t_hold *hold, t_pt a, t_pt i, int j);
int		ft_store_orientation(t_hold *hold, t_pt i, int j);
int		ft_get_wall_color(t_hold *hold, int i);
int		ft_line_hit(t_hold *hold, t_pt_d pos, t_pt map, int idx);
//		2D map
int		ft_put_2dmap(t_hold *hold);
int		ft_get_color_2d(t_hold *hold, t_pt i, t_pt n);
int		ft_2dmap_map(t_hold *hold);
int		ft_2dmap_raycasting(t_hold *hold);
int		ft_2dmap_player(t_hold *hold);
void	ft_line_bresenham_color_map(t_img *img, t_hold *hold, int ix, int clr);

//		3D map
int		ft_put_walls(t_hold *hold);
int		ft_put_background(t_hold *hold);
int		ft_put_background_bonus(t_hold *hold);
int		ft_put_background_mandatory(t_hold *hold);
int		ft_put_sprite(t_hold *hold);
//		textures
int		ft_open_texture(t_hold *hold, char *path, int type);
int		ft_get_tex_color(t_pt pt, t_tex *tex);
t_tex	*ft_get_wall_texture(t_hold *hold, int i);
void	ft_line_bresenham_tex(t_hold *hold, int idx, int wall_h, t_tex *tex);
void	ft_line_tex(t_hold *hold, int idx, t_pt wall, t_tex *tex);
int		ft_open_sprite(t_hold *hold, char *path, int idx);
t_vlist	*ft_new_sprite(t_pt_d pos, int type);
int		ft_check_enemy_coll(t_hold *hold);
//		files
int		ft_init_files(t_hold *hold);
int		ft_open_all_files(t_hold *hold);
int		ft_open_picture(t_hold *hold, char *path, int i);
int		ft_put_picture(t_hold *hold, int picture_id, t_pt pix);
int		ft_put_gif(t_hold *hold, int frame_start, int frame_next);
int		ft_render_gif(t_hold *hold);
t_pt_d	ft_ren_start(t_hold *hold, t_sprite *sprite);
int		ft_render_sprite(t_hold *hold, t_sprite *sprite);

// int		ft_put_gif_new(t_hold *hold, int frame_start, int frame_next);
//		 events
int		ft_set_mlx_loop(t_hold *hold);
int		ft_key_hook(int keycode, t_hold *hold);
int		ft_event(int keycode, t_hold *hold);
int		ft_event_world(int keycode, t_hold *hold);
int		ft_event_bonus(t_hold *hold);

int		ft_is_world(t_hold *hold);
int		ft_reset_world(t_hold *hold);
int		ft_move(t_hold *hold, int angle);
int		ft_rotate(t_hold *hold, int direction);
int		ft_open_door_front(t_hold *hold);
int		ft_get_mouse(int button, int x, int y, t_hold *hold);
int		ft_trasl(int x, int y, t_hold *hold);
int		ft_unlock(int button, int x, int y, t_hold *hold);
// bonus
int		ft_execution_bonus(t_hold *hold);
int		ft_level_opening(t_hold *hold);
int		ft_level_transition(t_hold *hold);
int		ft_level_ending_lost(t_hold *hold);
int		ft_level_ending_win(t_hold *hold);

int		ft_level_credits(t_hold *hold);
int		ft_level_earth(t_hold *hold);
int		ft_level_moon(t_hold *hold);
// floor
void	ft_floor_cast(t_hold *hold, t_tex *tex);
// UTILS
// 		angles
float	ft_to_radian(float angle);
float	ft_to_degree(float angle);
float	ft_angle_reset_radian(float angle);
float	ft_angle_reset_degree(float angle);
//		Draw 
int		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_sign(int x, int y);
void	ft_line_bresenham_color(t_img *img, t_pt a, t_pt b, int color);
//		colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

int		ft_get_opposite_color(int color);
int		ft_get_img_color(t_img *img, t_pt pt);
//		point translation
t_pt	ft_point(int x, int y);
int		ft_to_pxl(t_hold *hold, int pt);
int		ft_to_pt(t_hold *hold, int pxl);
int		ft_to_world_x(t_hold *hold, int pxl);
int		ft_to_world_y(t_hold *hold, int pxl);

int		ft_is_point_on_map(t_hold *hold, t_pt point, int place);
//		other
void	debug(char *str);
int		ft_isnumber(char *str);
int		ft_parse_color(char *str);
int		ft_is_line_empty(char *str);
void	ft_add_new_string_to_list(t_vlist **lst, char *str);

// ERROR & EXIT
//		error
int		ft_error( char *msg);
char	*ft_error_null(char *msg);
//		exit
int		ft_exit(t_hold *hold, int status);
int		ft_free_at_exit(t_hold *hold);
int		ft_free(void *obj);

#endif
