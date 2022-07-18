/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//includes
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <fcntl.h>

//defines
# define _USE_MATH_DEFINES

// window and display
# define WIN_NAME "fdf"
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1000
# define COLOR_INIT BLUE

# define MARGIN	60 //(WIN_WIDTH / 30)

# define MENU_WIDTH 405 //(((WIN_WIDTH - 3 * MARGIN) * 1 / 4))
# define MENU_HEIGHT 880 //(WIN_HEIGHT - 2 * MARGIN)
# define MENU_X0 60 // (MARGIN)
# define MENU_Y0 60 // (MARGIN)
# define MENU_X1 456 // (MENU_X0 + MENU_WIDTH)
# define MENU_Y1 940 // (MENU_Y0 + MENU_HEIGHT)

# define ZONE_WIDTH 1215 //((WIN_WIDTH - 3 * MARGIN - MENU_WIDTH))
# define ZONE_HEIGHT 880 //(WIN_HEIGHT - 2 * MARGIN)
# define ZONE_X0 525 // (MENU_X1 + MARGIN)
# define ZONE_Y0 60 // (MARGIN)
# define ZONE_X1 1740 // (WIN_WIDTH - MARGIN)
# define ZONE_Y1 940 //(ZONE_Y0 + ZONE_HEIGHT)
# define ZONE_XC 1132 // (ZONE_X0 + ZONE_WIDTH / 2)
# define ZONE_YC 500 //(ZONE_Y0 + ZONE_HEIGHT / 2)

// perspectives
# define ISOMETRIC 0.523599 // (30 * M_PI / 180) 
# define ISOMETRIC_2_1 0.46373398 // (26.57 * M_PI / 180) 
# define CAVALIER 0.785398 // (45 * M_PI / 180)

# define ROTATION 1.5708 // (90 * M_PI / 180)

// colors
# define BLACK (0x00000000)
# define WHITE (0x00FFFFFF)
# define RED (0x00FF0000)
# define GREEN (0x00008000)
# define YELLOW (0x00FFFF00)
# define BLUE (0x000000FF)

// KEYCODES
# define KEYCODE_SPACE_BAR 49
# define KEYCODE_C 8
# define KEYCODE_Z 6
# define KEYCODE_ENTER 36
# define KEYCODE_DELETE 51
# define KEYCODE_PLUS 34
# define KEYCODE_MINUS 31
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_DOWN 125
# define KEYCODE_UP 126
# define KEYCODE_ESC 53

# define MOVEMENT_STEP 100

// menu texte
# define MENU_COLOR WHITE
# define MENU_TXT "\n \
\nFDF ----------------------------\
\nThis project is about creating \
\na simplified 3D graphic \
\nrepresentation of a relief \
\nlandscape.\
\n \
\n \
\nBONUS OPTIONS ------------------\
\nZoom in               | 'i' \
\nZoom out              | 'o' \
\nRotate                | Space bar \
\nMove                  | arrows \
\nChange projection     | 'Enter' \
\nReset to default      | 'Del' \
\nChange colors         | 'c' \
\nQuit                  | 'ESC'"

//structures
typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_draw
{
	int		height;
	int		width;
	int		map_diag;
	int		scale_width;
	int		scale_height;
	int		scale;
	int		map_width;
	int		map_height;
	int		map_hypothenuse;
	float	angle;
	int		projection;
	t_point	offset;
}				t_draw;

typedef struct s_map
{
	int		z;
	int		pix_x;
	int		pix_y;
	int		color;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_map	**map;
	t_img	*img;
	t_draw	*draw;
}				t_env;

typedef struct s_bres
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_bres;

// INITIALIZATION
void	init_mlx_and_img(t_env *env);
void	init(t_env *env);
void	reset_to_default(t_env *env);
void	update_settings(t_env *env);

// PARSING
int		word_counter(const char *line, const char chr);
void	get_mapdim(char *file_name, int *height, int *width);
t_map	**map_alloc(int height, int width);
void	put_value(t_map *row, char *line);
t_map	**map_create(char *file_name, int height, int width);
t_map	**parse(char *file_name, int *height, int *width);

// PIXEL MANIPULATION
void	init_pixels(t_map ***map, t_draw *draw);
void	update_pixels(t_map ***map, t_draw *draw, \
void (*f)(t_map ***, int, int, t_draw *));
void	scale(t_map ***map, int x, int y, t_draw *draw);
void	projection(t_map ***map, int x, int y, t_draw *draw);
void	align_to_display(t_map ***map, int x, int y, t_draw *draw);

// bonus
void	rotation(t_map ***map, int x, int y, t_draw *draw);
void	zoom(t_env *env, float value);
void	change_projection(t_env *env);
void	color_update(t_map ***map, int x, int y, t_draw *draw);
void	reset_pixel(t_env *env);
void	move_up(t_map ***map, int x, int y, t_draw *draw);
void	move_down(t_map ***map, int x, int y, t_draw *draw);
void	move_left(t_map ***map, int x, int y, t_draw *draw);
void	move_right(t_map ***map, int x, int y, t_draw *draw);

// DRAW
void	put_img(t_env *env);
void	put_map_color(t_img *img, t_map ***map, t_draw *draw);
void	put_display(t_img *img);
void	put_background(t_img *img, t_point a, t_point b, int color);
void	put_frame(t_img *img, t_point a, t_point b, int color);
void	put_menu_txt(t_env *mlx);

// DRAW UTILS
void	my_mlx_pixel_put(t_img *img, t_point a, int color);
int		ft_sign(int x, int y);
void	ft_line_bresenham_map(t_img *img, t_map a, t_map b);
void	ft_line_bresenham(t_img *img, t_point a, t_point b, int color);

// COLORS UTILS
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		color_fade(t_map a, t_map z, t_map i);
int		get_opposite_color(int color);

//EVENTS
int		key_hook(int keycode, t_env *env);
int		key_hook_2(int keycode, t_env *env);
void	ft_event(t_env *env, void (*f)(t_map ***, int, int, t_draw *));

// UTILS
t_point	ft_point(int x, int y);
t_point	ft_pix_lowest(t_map ***map, t_draw *draw);
t_point	ft_pix_highest(t_map ***map, t_draw *draw);
t_point	ft_pix_leftest(t_map ***map, t_draw *draw);
t_point	ft_pix_rightest(t_map ***map, t_draw *draw);
t_point	ft_distance(t_map ***map, t_draw *draw);

// EXIT
int		exit_fdf(t_env *env);
void	free_split(char **l_split);
void	map_free(t_map **map, int height);

#endif
