#include "cub3D.h"


// int ft_raycasting_g(t_hold *hold)
// {
// 	float	dir[2];
// 	float	plane[2];
// 	float	rayDir[2];
// 	float	sideDist[2];
// 	float	deltaDist[2];
// 	int		mmap[2];
// 	int		step[2];
// 	float	camX;
// 	int idx;
// 	int hit;
// 	int side;
// 	debug("	ft_raycasting_g");

// 	dir[0] = cos(hold->pos_a);
// 	dir[1] = sin(hold->pos_a);
// 	plane[0] = cos(hold->pos_a - M_PI_2) * FOV / 100;
// 	plane[1] = sin(hold->pos_a - M_PI_2) * FOV / 100;
// 	idx = 0;
// 	while (idx < WIN_WIDTH - 1)
// 	{
// 		camX = 2 * idx / (float)WIN_WIDTH - 1;
// 		rayDir[0] = dir[0] + plane[0] * camX;
// 		rayDir[1] = dir[1] + plane[1] * camX;
// 		mmap[0] = hold->pix_x / hold->ppu;
// 		mmap[1] = hold->pix_y / hold->ppu;
// 		deltaDist[0] = sqrt(1 + (rayDir[1] * rayDir[1]) / (rayDir[0] * rayDir[0]));
// 		deltaDist[1] = sqrt(1 + (rayDir[0] * rayDir[0]) / (rayDir[1] * rayDir[1]));
// 		debug("prova");
// 		if (rayDir[0] < 0)
// 		{
// 			step[0] = -1;
// 			sideDist[0] = (hold->pix_x % hold->ppu) / (double)hold->ppu * deltaDist[0];
// 		}
// 		else
// 		{
// 			step[0] = 1;
// 			sideDist[0] = (1.0 - ((hold->pix_x % hold->ppu) / (double)hold->ppu)) * deltaDist[0];
// 		}
// 		debug("prova");
// 		if (rayDir[1] < 0)
// 		{
// 			step[1] = -1;
// 			sideDist[1] = (hold->pix_y % hold->ppu) / (double)hold->ppu * deltaDist[1];
// 		}
// 		else
// 		{
// 			step[1] = 1;
// 			sideDist[1] = (1.0 - ((hold->pix_y % hold->ppu) / (double)hold->ppu)) * deltaDist[1];
// 		}
// 		debug("prova");
// 		hit = 0;
// 		while (hit == 0)
// 		{
// 			if (sideDist[0] < sideDist[1])
// 			{
// 				sideDist[0] += deltaDist[0];
// 				mmap[0] += step[0];
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDist[1] += deltaDist[1];
// 				mmap[1] += step[1];
// 				side = 1;
// 			}
// 			if (hold->map[mmap[1]][mmap[0]] != EMPTY)
// 				hit = 1;
// 		}
// 		debug("qua\n");
// 		if (side == 0)
// 		{
// 			hold->hit[DIS][idx] = sideDist[0] - deltaDist[0];
// 			if (rayDir[0] > 0)
// 				hold->hit[WALL_ORIENTATION][idx] = e_wall_south;
// 			else
// 				hold->hit[WALL_ORIENTATION][idx] = e_wall_north;
// 		}
// 		else
// 		{
// 			hold->hit[DIS][idx] = sideDist[1] - deltaDist[1];
// 			if (rayDir[1] > 0)
// 				hold->hit[WALL_ORIENTATION][idx] = e_wall_east;
// 			else
// 				hold->hit[WALL_ORIENTATION][idx] = e_wall_west;
// 		}
// 		hold->hit[HIT_ANGLE][idx] = (int)(camX * 1000000);
// 		idx++;
// 	}
// 	return (0);	
// }


// int	ft_color_fade(t_point a, t_point z, t_point i, int color)
// {
// 	int	t;
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	prog;

// 	prog = (ft_abs(i.x - a.x) + ft_abs(i.y - a.y)) * 100 / (ft_abs(z.x - a.x) + ft_abs(z.y - a.y));
// 	if (prog > 100)
// 		return (ft_error("prog"));
// 	printf("prog %2d| ", prog);
// 	t = (0xFF * prog / 100);
// 	r = get_r(color);
// 	g = get_g(color);
// 	b = get_b(color);
// 	// printf("a_color 0x%X | ", a_color);
// 	// printf("t %d | ", t);
// 	// printf("r %X | ", r);
// 	// printf("g %X | ", g);
// 	// printf("b %X | ", b);
// 	// printf("color %X \n", create_trgb(t, r, g, b));
// 	return (create_trgb(t, r, g, b));
// }

// probleme max int
// void	ft_line_bresenham_gradient(t_img *img, t_point a, t_point b, int color)
// {
// 	// debug("ft_line_bresenham_gradient");
// 	t_bres	bres;
// 	t_point	i;

// 	i = a;
// 	bres.dx = ft_abs(b.x - i.x);
// 	bres.sx = ft_sign(i.x, b.x);
// 	bres.dy = -ft_abs(b.y - i.y);
// 	bres.sy = ft_sign(i.y, b.y);
// 	bres.err = bres.dx + bres.dy;
// 	// printf("\n");
// 	while (i.x != b.x || i.y != b.y)
// 	{
// 		printf("color %d | ", color);
// 		color = ft_color_fade(a, b, i, color);
// 		printf("color %d\n", color);
// 		ft_mlx_pixel_put(img, i.x, i.y, color);
// 		bres.e2 = 2 * bres.err;
// 		if (bres.e2 >= bres.dy)
// 		{
// 			bres.err += bres.dy;
// 			i.x += bres.sx;
// 		}
// 		if (bres.e2 <= bres.dx)
// 		{
// 			bres.err += bres.dx;
// 			i.y += bres.sy;
// 		}
// 	}
// }

void	ft_draw_triangle(t_hold *hold, int x, int y, int r, int color)
{
	int xa, ya, xb, xc, yb, yc;
	xa = r / 2 * cos(ft_angle_reset_radian(hold->pos_a));
	ya = r / 2 * sin(ft_angle_reset_radian(hold->pos_a));
	xb = r / 2 * cos(ft_angle_reset_radian(hold->pos_a + 3 * M_PI / 4));
	yb = r / 2 * sin(ft_angle_reset_radian(hold->pos_a + 3 * M_PI / 4));
	xc = r / 2 * cos(ft_angle_reset_radian(hold->pos_a + 5 * M_PI / 4));
	yc = r / 2 * sin(ft_angle_reset_radian(hold->pos_a + 5 * M_PI / 4));


	ft_line_bresenham_color(hold->img, ft_point(x, y), ft_point(x + xa, y + ya), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xa, y + ya), ft_point(x + xb, y + yb), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xa, y + ya), ft_point(x + xc, y + yc), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xb, y + yb), ft_point(x + xc, y + yc), color);

	// int xi, yi, xmax, ymax;
	// printf("xa %f\n", xa += x);
	// printf("ya %f\n", ya += y);
	// printf("xb %f\n", xb += x);
	// printf("yb %f\n", yb += y);
	// printf("xc %f\n", xc += x);
	// printf("yc %f\n", yc += y);

	// printf("xi %d\n", xi = ft_min(ft_min(xa, xb), ft_min(xa, xc)));
	// printf("yi %d\n", yi = ft_min(ft_min(ya, yb), ft_min(ya, yc)));
	// printf("xmax %d\n", xmax = ft_max(ft_max(xa, xb), ft_max(xa, xc)));
	// printf("ymax %d\n", ymax = ft_max(ft_max(ya, yb), ft_max(ya, yc)));
	// while (yi <= ymax)
	// {
	// 	xi = ft_min(ft_min(xa, xb), ft_min(xa, xc));
	// 	int xac = (yi - ya) * (xc - xa) / (yc - ya) + xa;
	// 	int xab = (yi - ya) * (xb - xa) / (yb - ya) + xa;
	// 	int xbc = (yi - yb) * (xc - xb) / (yc - yb) + xb;
	// 	// printf("xi %d yi %d xab %d xac %d xbc %d\n", xi, yi, xab, xac, xbc);
	// 	while (xi <= xmax)
	// 	{
	// 	// int yab = (xi - xa) * (yc - ya) / (xc - xa) + ya;
	// 	// int yac = (xi - xa) * (yb - ya) / (xb - xa) + ya;
	// 	// int ybc = (xi - xb) * (yb - yb) / (xb - xb) + yb;
	// 	// printf("xi %d yi %d xab %d xac %d xbc %d | yab %d yac %d ybc %d\n", xi, yi, xab, xac, xbc, yab, yac, ybc);
	// 	int count = 0;
	// 	if (xi < xac)
	// 		count++;
	// 	if (xi < xab)
	// 		count++;				
	// 	if (xi < xbc)
	// 		count++;
	// 	if (count == 1)
	// 	{
	// 		printf("xi %d yi %d xab %d xac %d xbc %d\n", xi, yi, xab, xac, xbc);
	// 		ft_mlx_pixel_put(hold->img, xi, yi, ft_get_opposite_color(color));
	// 	}
	// 	// if (xi > ft())
	// 	// 	;
	// 		xi++;
	// 	}
	// 	yi++;
	// }
	// ft_mlx_pixel_put(hold->img, x + xa, y + ya, ft_get_opposite_color(color));
}


// void	ft_draw_glow(t_hold *hold, t_point start, int size, int color)
// {
// 	t_point	end;
// 	float	angle;
// 	int		i;

// 	i = 0;
// 	while (i < 360)
// 	{
// 		angle = ft_to_radian(i);
// 		end.x = start.x + (size * cos(angle));
// 		end.y = start.y + (size * sin(angle));
// 		ft_line_bresenham_gradient(hold->img, start, end, color);
// 		ft_mlx_pixel_put(hold->img, end.x, end.y, RED);
// 		i++;
// 	}
// }

// # include "cub3D.h"

// int	ft_img_open(t_hold *hold, t_file *file, char *filename_list)
// {
// 	char	**arr;

// 	arr = ft_split(filename_list, '\n');

// 	ft_img_init(hold, file, arr);

// 	if (hold->file)
// 		mlx_put_image_to_window(hold->mlx, hold->win, hold->file->img, WIN_WIDTH / 2, WIN_HEIGHT / 2);
// 	else
// 		return (ft_error("failed image screening"));

// 	ft_free(arr);
// 	return (0);
// }


// int ft_filetype(char *filename)
// {
//     int     type;
//     enum    e_file_type;

//     type = ERR;
//     if (ft_strncmp(filename, "player", ft_strlen("player")) == 0)
//         type = e_file_player;
//     else if (ft_strncmp(filename, "sprite", ft_strlen("sprite")) == 0)
//         type = e_file_sprite;
//     else if (ft_strncmp(filename, "enemy", ft_strlen("enemy")) == 0)
//         type = e_file_enemy;
//     else if (ft_strncmp(filename, "ceiling", ft_strlen("ceiling")) == 0)
//         type = e_file_ceiling;
//     else if (ft_strncmp(filename, "floor", ft_strlen("floor")) == 0)
//         type = e_file_floor;
//     else if (ft_strncmp(filename, "texture", ft_strlen("texture")) == 0)
//         type = e_file_texture;
//     else if (ft_strncmp(filename, "frame", ft_strlen("frame")) == 0)
//         type = e_file_frame;
//     return (type);
// }

// int ft_img_init(t_hold *hold, t_file *head, char **arr)
// {
// 	int i;
// 	t_file	*file;

// 	i = -1;
// 	while (arr[++i])
// 	{
// 		file = (t_file *) malloc(sizeof(t_file));
// 		if (!file)
// 			return (ft_error("failure: malloc - init file"));
// 		file->img_name = ft_strdup(arr[i]);
// 		file->file_type = ft_filetype(arr[i]);
// 		// file->img_h = 20; // get size
// 		// file->img_w = 20;
// 		file->img = mlx_xpm_file_to_image(hold->mlx, file->img_name, &file->img_w, &file->img_h);
// 		printf("printing file %s\t%p\n", file->img_name, file->img);
// 		if (!file->img)
// 			return (ft_error("failed image upload"));
// 		if (i == 0)
// 			file->prev = NULL;
// 		file->next = NULL;
// 		if (arr[i + 1])
// 		{
//             file = file->next;
//         }
// 	}
// 	head = ft_go_to_top(file);
// 	return (0);
// }

// 	// printf("printing array\n");
// 	// int i = 0;
// 	// while (arr && arr[i])
// 	// {
// 	// 	printf("arr[%d]: %s\n", i, arr[i]);
// 	// 	i++;
// 	// }	

// // t_list	*go_to_end(t_list *list)
// // {
// // 	while (list->next)
// // 		list = list->next;
// // 	return (list);
// // }

// // t_list	*go_to_top(t_list *list)
// // {
// // 	while (list->prev)
// // 		list = list->prev;
// // 	return (list);
// // }