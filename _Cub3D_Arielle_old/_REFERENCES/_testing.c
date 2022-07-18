#include "fdf.h"
#include <stdio.h>

// tests
// void	put_map(t_img *img, t_map ***map, t_draw *draw, int color);
void	print_env(t_env *env, t_img *img);
void	test_line_star(void *img);
void	test_line_star_color(void *img);
void	test_print_map(t_map **map, t_draw *draw);
void	test_update_map(t_map ***map);
int		ft_random_bolean(void);
void	map_print(t_map **map, int height, int width);

void	print_env(t_env *env, t_img *img)
{
	ft_printf("Printing environment-----------------\n");
	ft_printf("// MLX\n");
	ft_printf("| mlx : %p \n| win : %p \n", env->mlx, env->win);
	ft_printf("\n");
	ft_printf("// IMG\n");
	ft_printf("| img.img : %p \n", img->img);
	ft_printf("| img.addr : |%s|%p|\n",img->addr, img->addr);
	ft_printf("| img.bits_per_pixel : %d \n", img->bits_per_pixel);
	ft_printf("| img.line_length : %d \n", img->line_length);
	ft_printf("| img.endian : %d \n", img->endian);
	ft_printf("\n");
	ft_printf("// DRAW\n");
	ft_printf("| env->draw->height : %d \n", env->draw->height);
	ft_printf("| env->draw->width : %d \n", env->draw->width);
	ft_printf("| env->draw->map_diag : %d \n", env->draw->map_diag);
	ft_printf("| env->draw->scale_width : %d \n", env->draw->scale_width);
	ft_printf("| env->draw->scale_height : %d \n", env->draw->scale_height);
	ft_printf("| env->draw->scale : %d \n", env->draw->scale);
	ft_printf("| env->draw->map_width : %d \n", env->draw->map_width);
	ft_printf("| env->draw->map_height : %d \n", env->draw->map_height);
	ft_printf("| env->draw->map_hypothenuse : %d \n", env->draw->map_hypothenuse);
	printf("| env->draw->angle : %f \n", env->draw->angle);
	ft_printf("// DEFINES\n");
	ft_printf("| WIN_NAME %s\n", WIN_NAME);
	ft_printf("| WIN_WIDTH %d ", WIN_WIDTH);
	ft_printf("| WIN_HEIGHT %d\n", WIN_HEIGHT);
	ft_printf("| MARGIN %d\n", MARGIN);
	ft_printf("| MENU_WIDTH %d ", MENU_WIDTH);
	ft_printf("| MENU_HEIGHT %d\n", MENU_HEIGHT);
	ft_printf("| MENU_X0 %d ", MENU_X0);
	ft_printf("| MENU_Y0 %d\n", MENU_Y0);
	ft_printf("| MENU_X1 %d ", MENU_X1);
	ft_printf("| MENU_Y1 %d\n", MENU_Y1);
	ft_printf("| ZONE_WIDTH %d ", ZONE_WIDTH);
	ft_printf("| ZONE_HEIGHT %d\n", ZONE_HEIGHT);
	ft_printf("| ZONE_X0 %d ", ZONE_X0);
	ft_printf("| ZONE_Y0 %d\n", ZONE_Y0);
	ft_printf("| ZONE_X1 %d ", ZONE_X1);
	ft_printf("| ZONE_Y1 %d\n", ZONE_Y1);
	ft_printf("| ZONE_XC %d", ZONE_XC);
	ft_printf("| ZONE_YC %d\n", ZONE_YC);

	// ft_printf("| MAP_ROWS %d ", MAP_ROWS);
	// ft_printf("| MAP_COLS %d", MAP_COLS);
	// ft_printf("| MAP_DIAG %d\n", MAP_DIAG);
	// ft_printf("| SCALE_WIDTH %d", SCALE_WIDTH);
	// ft_printf("| SCALE_HEIGHT %d", SCALE_HEIGHT);
	// ft_printf("| SCALE %d\n", SCALE);
	// ft_printf("| MAP_WIDTH %d", MAP_WIDTH);
	// ft_printf("| MAP_HEIGHT %d", MAP_HEIGHT);
	// ft_printf("| MAP_HYPOTHENUSE %d\n\n", MAP_HYPOTHENUSE);

	ft_printf("| MENU_COLOR %X\n", MENU_COLOR);
	ft_printf("| MENU_TXT %s\n", MENU_TXT);
	ft_printf("----------------------------------------\n\n", MENU_TXT);

}

void	test_line_star(void *img)
{
	int x0, y0, xi, yi, jump_x, jump_y, i;
	int branch = 2;
	x0 = ZONE_XC; y0 = ZONE_YC;
	xi = -(ZONE_WIDTH / 2); yi = -(ZONE_HEIGHT / 2); 
	jump_x = ZONE_WIDTH / branch; jump_y = ZONE_HEIGHT / branch;
	int color = GREEN;
	i = 0;
	while (i <= branch)
	{
		color += 8 ;
		ft_line_bresenham(img, ft_point(x0, y0), ft_point(x0 + xi, y0 + yi), color++);
		if (i < branch)
			xi += jump_x;
		i++;
	}
	i = 0;
	while (i <= branch)
	{
		color += 8 ;
		ft_line_bresenham(img, ft_point(x0, y0), ft_point(x0 + xi, y0 + yi), color++);
		if (i < branch)
			yi += jump_y;
		i++;
	}	
	i = 0;
	while (i <= branch)
	{
		color += 8 ;
		ft_line_bresenham(img, ft_point(x0, y0), ft_point(x0 + xi, y0 + yi), color++);
		if (i < branch)
			xi -= jump_x;
		i++;
	}
	i = 0;
	while (i <= branch)
	{
		color += 8 ;
		ft_line_bresenham(img, ft_point(x0, y0), ft_point(x0 + xi, y0 + yi), color++);
		if (i < branch)
			yi -= jump_y;
		i++;
	}
}

void	test_line_star_color(void *img)
{
	int branch = 2;
	t_point jump = ft_point(ZONE_WIDTH / branch, ZONE_HEIGHT / branch);
	t_point center = ft_point(ZONE_XC, ZONE_YC);
	t_point radius = ft_point(ZONE_WIDTH / 2, ZONE_HEIGHT / 2);
	t_point color = ft_point(GREEN, BLUE);
	int xi, yi;
	xi = -radius.x; yi = -radius.y; 
	int i = 0;
	while (i <= branch)
	{
		// color.y += 8 ;
		ft_line_bresenham_map(img, center, ft_point(center.x + xi, center.y + yi), color);
		if (i < branch)
			xi += jump.x;
		i++;
	}
	i = 0;
	while (i <= branch)
	{
		// color.y += 8 ;
		ft_line_bresenham_map(img, center, ft_point(center.x + xi, center.y + yi), color);
		if (i < branch)
			yi += jump.y;
		i++;
	}	
	i = 0;
	while (i <= branch)
	{
		// color.y += 8 ;
		ft_line_bresenham_map(img, center, ft_point(center.x + xi, center.y + yi), color);
		if (i < 10)
			xi -= jump.x;
		i++;
	}
	i = 0;
	while (i <= branch)
	{
		// color.y += 8 ;
		ft_line_bresenham_map(img, center, ft_point(center.x + xi, center.y + yi), color);
		if (i < branch)
			yi -= jump.y;
		i++;
	}
}

void	test_print_map(t_map **map, t_draw *draw)
{
	int x, y, i;
	y = 0; i = 0;
	ft_printf("printing map ...\n");
	ft_printf("x %5d,  y %5d, x*y = %5d\n", draw->width, draw->height, draw->width * draw->height);
	ft_printf("          | ");
	i = 0;
	while (i < draw->width)
		ft_printf("       x = %5d        | ", i++);
	ft_printf("\n");
	while (y < draw->height)
	{
		x = 0;
		ft_printf("y : %5d |\n", y);
		while(x < draw->width)
		{
			// ft_printf("(x%d , y%d) z%5d, 0x%6X|", x, y, map[y][x].z, map[y][x].color);
			ft_printf(" (x%-3d , y%-3d) x%5d, y%5d, z%5d, 0x%6X |", x, y, map[y][x].pix_x, map[y][x].pix_y, map[y][x].z, map[y][x].color);
			x++;
			i++;
			if (!(i % 5))
			ft_printf("\n");
		}
		ft_printf("\n");
		y++;
	}
}
// ametta
void	map_print(t_map **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putnbr_fd(map[i][j].z, 1);
			write(1, ",", 1);
			ft_putnbr_base(map[i][j].color, 16);
			write(1, "\t", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}



// // for testing
// put_frame(img, ft_point(ZONE_X0, ZONE_Y0), ft_point(ZONE_X0 + ZONE_WIDTH/2, ZONE_Y0 + ZONE_HEIGHT/2), WHITE);
// put_frame(img, ft_point(ZONE_X0 + ZONE_WIDTH/2, ZONE_Y0 + ZONE_HEIGHT/2), ft_point(ZONE_X1, ZONE_Y1), WHITE);
// put_frame(img, ft_point(ZONE_X0 + ZONE_WIDTH/2, ZONE_Y0), ft_point(ZONE_X1, ZONE_Y0 + ZONE_HEIGHT/2), WHITE);
// put_frame(img, ft_point(ZONE_X0, ZONE_Y0 + ZONE_HEIGHT/2), ft_point(ZONE_X0 + ZONE_WIDTH/2, ZONE_Y1), WHITE);







