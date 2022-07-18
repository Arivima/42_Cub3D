# define IX 0 // to update together
# define IY 1 // to update together
# define HIT_ANGLE 2
# define DIS 3
# define WALL_ORIENTATION 4
# define MX 5
# define MY 6 // to delete
# define DOOR 7 // ok

	int		hit[8][WIN_WIDTH];
	float	hit_new[8][WIN_WIDTH];

	t_point_d	pl_w;
	t_point	pl_map;


	hold->hit_new[IX][idx] = rayDir.x;
	hold->hit_new[IY][idx] = rayDir.y;
    hold->hit[WALL_ORIENTATION][idx] = e_wall_south;



