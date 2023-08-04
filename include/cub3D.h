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
# define COLOR_TEXT (BLACK)
// 2D
# define START_2D_X 20
# define START_2D_Y 30
# define MAX_2D_LEN 400 //  sets maximum size of 2Dmap
# define COLOR_EMPTY BLACK
# define COLOR_BORDER WHITE
# define COLOR_WALLS WHITE
# define COLOR_DOORS RED
# define COLOR_PLAYER RED_POPPY
# define COLOR_RAYCASTING WHITE
# define COLOR_ENEMY RED_POPPY
# define COLOR_SPRITE GREEN_TEAL
// 3D
# define MARGIN 		0 // y margin around top and bottom
# define START_3D_X 	0
# define START_3D_Y 	(MARGIN)
# define END_3D_Y 		(WIN_HEIGHT - MARGIN)
# define MAX_3D_WALL 	(END_3D_Y - START_3D_Y)
# define MIN_3D_WALL 	(0.1 * MAX_3D_WALL)
# define COLOR_WALL_NORTH (YELLOW_SUNNY)
# define COLOR_WALL_SOUTH (RED_POPPY)
# define COLOR_WALL_EAST (BLUE_BETTER)
# define COLOR_WALL_WEST (GREEN_MINT)
# define COLOR_WALL_ANGLE (WHITE)
// RAYCASTING hit point storage 
// (hold.hit[i][WIN_WIDTH])
# define IX 0
# define IY 1
# define HIT_ANGLE 2
# define DIS 3
# define WALL_ORIENTATION 4
# define MX 5
# define MY 6
# define DOOR 7

enum	e_wall_orientation
{
	e_wall_north,
	e_wall_south,
	e_wall_east,
	e_wall_west,
	e_wall_angle,
	e_wall_other,
};

// custom project settings
# define NAME "Cub3D"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_HYPOTHENUSE ((int) sqrt(pow(WIN_HEIGHT, 2) + pow(WIN_WIDTH, 2)))
# define FOV 1.15192 // = 66 degree
# define ERR -1
# define FLAG -1
# define DEBUG 0

// here we add only files from folder ./sprites/ that we will need to use
# define IMG_FILES "\
files/player_heart.xpm\n\
files/player_moon.xpm\n\
files/ceiling_earth2.xpm\n\
files/ceiling_moon.xpm\n\
files/floor_wood.xpm\n\
files/floor_moon.xpm\n\
files/animation_00.xpm\n\
files/animation_01.xpm\n\
files/animation_02_00.xpm\n\
files/animation_02_01.xpm\n\
files/animation_02_02.xpm\n\
files/animation_02_03.xpm\n\
files/animation_02_04.xpm\n\
files/animation_03.xpm\n\
files/animation_04.xpm\n"

// here we identify any file listed above, in the same order
enum	e_picture_list
{
	e_PIC_PLAYER,
	e_PIC_PLAYER_MOON,
	e_PIC_CEILING_EARTH,
	e_PIC_CEILING_MOON,
	e_PIC_FLOOR_EARTH,
	e_PIC_FLOOR_MOON,
	e_PIC_ANIMATION_00_00,
	e_PIC_ANIMATION_01_00,
	e_PIC_ANIMATION_02_00,
	e_PIC_ANIMATION_02_01,
	e_PIC_ANIMATION_02_02,
	e_PIC_ANIMATION_02_03,
	e_PIC_ANIMATION_02_04,
	e_PIC_ANIMATION_03_00,
	e_PIC_ANIMATION_04_00,
	e_PIC_ANIMATION_05_00,
	// e_PIC_DOOR_MOON,
	// e_PIC_DOOR_EARTH,
	// e_PIC_SPRITE_GLOW,
	// e_PIC_SPRITE_BIRD,
	// e_PIC_SPRITE_FLOWER,
	// e_PIC_SPRITE_INSECT,
	// e_PIC_SPRITE_PEOPLE1,
	// e_PIC_SPRITE_PEOPLE2,
	// e_PIC_FRAME,
	// e_PIC_SCREEN_01,
	// e_PIC_ANIMATION_01_00,
	// e_PIC_ANIMATION_01_01,
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
THANK YOU FOR PLAYING THE TALES OF PRINCESS KAGUYA\nCREDITS AVILLA-M GDI-LORE\nPRESS 'SPACE' TO START AGAIN"

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
}				t_point;

typedef struct s_vec3
{
	int r;
	int g;
	int b;
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

typedef struct s_hold
{
    int 	fd;
	// path to textures
    char 	*no;
    char 	*so;
    char 	*we;
    char	*ea;
	// textures
	t_tex	**tex;
	t_tex	**pics;
	// colors
	int		floor;
	int		ceiling;
	// directions, used in parsing only
	int		dir[4][2];
	// game level
	int		game_level;
	// int		counter_sprite;
	int		f_game_over;
	// map
	char	**map; // map[row][col]
	int		map_w; // nb of cols
	int		map_h; // nb of rows
	int		pos_x; // initial player position, useful only for init
	int		pos_y; // initial player position, useful only for init
	float	pos_a; // angle of player, updated with ft_rotate, in rad
	// 2D map_px
	int		ppu; // pixel per unit (point)
	int		pix_w; // width of the 2Dmap
	int		pix_h; // height of the 2Dmap
	int		pix_H; // hypothenuse of the 2Dmap
	int		pix_x; // x position of player on screen
	int		pix_y; // y position of player on screen
	int		hit[8][WIN_WIDTH];
	// mlx
	void	*mlx;
	void	*win;
    int     w_width;
    int     w_height;
    char	*w_name;
	// structures
	t_img	*img;
}				t_hold;

// PROTOTYPES

// PARSING & INIT
int     parsing(int ac, char **av, t_hold *hold);
int		ft_parse_arguments(t_hold *hold);
int     is_valid_path(char *path);
int		ft_preparse_map(t_hold *hold, t_vlist **preparse);
int		ft_parse_map(t_hold *hold, t_vlist *preparse);
int		ft_check_map(t_hold *hold);
// init
int     check_arg(int ac, char **av, t_hold *hold);
int     init_holder(t_hold *hold);

// init
int		ft_init(t_hold *hold);
int		ft_init_holder(t_hold *hold);
int 	ft_init_mlx_win_img(t_hold *hold);
float	ft_init_angle_direction(int c);
int		ft_init_2D_map(t_hold *hold);
// init_map
int 	ft_init_map_pt(t_hold *hold);

// EXECUTION
int		ft_execution(t_hold *hold);
int		ft_put_world(t_hold *hold);
int		ft_mlx_put_new_img(t_hold *hold);
int		ft_put_display(t_hold *hold);
int		ft_put_text(t_hold *hold);
//		raycasting
int		ft_raycasting(t_hold *hold);
int		ft_line_bresenham_hit(t_hold *hold, t_point a, t_point b, int j);
int		ft_store_hit_data(t_hold *hold, t_point a, t_point i, int j);
int		ft_store_orientation(t_hold *hold, t_point i, int j);
int		ft_get_wall_color(t_hold *hold, int i);
//		2D map
int		ft_put_2dmap(t_hold *hold);
int		ft_get_color_2d(t_hold *hold, t_point i, t_point n);
int		ft_2dmap_map(t_hold *hold);
int		ft_2dmap_raycasting(t_hold *hold);
int		ft_2dmap_player(t_hold *hold);
//		3D map
int		ft_put_walls(t_hold *hold);
int		ft_put_background(t_hold *hold);
int		ft_put_background_bonus(t_hold *hold);
int		ft_put_background_mandatory(t_hold *hold);
//		textures
void 	ft_open_texture(t_hold *hold, char *path, int type);
int		ft_get_tex_color(t_point pt, t_tex *tex);
t_tex	*ft_get_wall_texture(t_hold *hold, int i);
void	ft_line_bresenham_tex(t_hold *hold, int idx, int wall_height, t_tex *tex);
//		files
int		ft_init_files(t_hold *hold);
int		ft_open_all_files(t_hold *hold);
int		ft_open_picture(t_hold *hold, char *path, int i);
int		ft_put_picture(t_hold *hold, int picture_id, t_point pix);
int		ft_put_gif(t_hold *hold, int frame_start, int frame_next);
//		 events
int		ft_set_mlx_loop(t_hold *hold);
int		ft_key_hook(int keycode, t_hold *hold);
int		ft_event(int keycode, t_hold *hold);
int		ft_event_world(int keycode, t_hold *hold);
int 	ft_event_bonus(t_hold *hold);

int		ft_is_world(t_hold *hold);
int		ft_reset_world(t_hold *hold);
int		ft_move(t_hold *hold, int angle);
int		ft_rotate(t_hold *hold, int direction);
int		ft_open_door_front(t_hold *hold);
// bonus
int		ft_execution_bonus(t_hold *hold);
int		ft_level_opening(t_hold *hold);
int		ft_level_transition(t_hold *hold);
int		ft_level_ending_lost(t_hold *hold);
int		ft_level_ending_win(t_hold *hold);

int		ft_level_credits(t_hold *hold);
int		ft_level_earth(t_hold *hold);
int		ft_level_moon(t_hold *hold);

// UTILS
// 		angles
float	ft_to_radian(float angle);
float	ft_to_degree(float angle);
float	ft_angle_reset_radian(float angle);
float	ft_angle_reset_degree(float angle);
//		Draw 
int		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_sign(int x, int y);
void	ft_line_bresenham_color(t_img *img, t_point a, t_point b, int color);
//		colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

int		ft_get_opposite_color(int color);
int		ft_get_img_color(t_img *img, t_point pt);
//		draw shapes
void	ft_draw_circle(t_hold *hold, t_point pt, int r, int color);
void	ft_draw_triangle(t_hold *hold, int x, int y, int r, int color);
void	ft_draw_square(t_img *img, int x, int y, int r, int color);
//		point translation
t_point	ft_point(int x, int y);
int		ft_to_pxl(t_hold *hold, int pt);
int		ft_to_pt(t_hold *hold, int pxl);
int		ft_to_world_x(t_hold *hold, int pxl);
int		ft_to_world_y(t_hold *hold, int pxl);

int		ft_is_point_on_map(t_hold *hold, t_point point, int place);
// 		other
void	debug(char *str);
int		ft_isnumber(char *str);
int		ft_parse_color(char *str);
int		ft_is_line_empty(char *str);
void	ft_add_new_string_to_list(t_vlist **lst, char *str);

// ERROR & EXIT
//		error
int	    ft_error( char *msg);
char	*ft_error_null(char *msg);
// 		exit
int		ft_exit(t_hold *hold, int status);
int		ft_free_at_exit(t_hold *hold);
int		ft_free(void *obj);

#endif
