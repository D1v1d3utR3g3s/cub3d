#include "../includes/mlxBasic.h"

static int	init_hor_intersect(t_mlx_data *mlx)
{
	t_ray	*ray;

	ray = &(mlx->ray);
	ray->ry = (((int)mlx->player.py >> 6) << 6) - 0.0001;
	if (face_down(ray->ra))
		ray->ry += 64.0001;
	ray->rx = mlx->player.px + (ray->ry - mlx->player.py) / tan(ray->ra);
	ray->dy = 64;
	if (!face_down(ray->ra))
		ray->dy *= -1;
	ray->dx = ray->dy / tan(ray->ra);
	if ((!face_right(ray->ra) && ray->dx > 0) || (face_right(ray->ra) && ray->dx < 0))
		ray->dx *= -1;
	if (ray->ra == 0 || ray->ra == M_PI) // looking left or right
	{
		ray->ry = mlx->player.py;
		ray->rx = mlx->player.px;
		return (8);
	}
	return (0);
}

static void	hor_intersect(t_mlx_data *mlx)
{
	int	dof;
	int	mx, my, mp;
	t_ray	*ray;

	ray = &(mlx->ray);
	dof = init_hor_intersect(mlx);
	while (dof < 8)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		mp = my * mlx->grid.nb_tile_x + mx;
		// hit wall
		if (mp > 0 && (mp < mlx->grid.nb_tile_x * mlx->grid.nb_tile_y) && (mlx->grid.map[mp] == 1))
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dh = calc_d(mlx->player.px, mlx->player.py, ray->hx, ray->hy, ray->ra);
			dof = 8;
		}
		else
		{
			ray->rx += ray->dx;
			ray->ry += ray->dy;
			dof++;
		}
	}
}

static int	init_ver_intersect(t_mlx_data *mlx)
{
	t_ray	*ray;

	ray = &(mlx->ray);
	ray->rx = (((int)mlx->player.px >> 6) << 6) - 0.0001;
	if (face_right(ray->ra))
		ray->rx += 64.0001;
	ray->ry = mlx->player.py + (ray->rx - mlx->player.px) * tan(ray->ra);
	ray->dx = 64;
	if (!face_right(ray->ra))
		ray->dx *= -1;
	ray->dy = ray->dx * tan(ray->ra);
	if ((!face_down(ray->ra) && ray->dy > 0) || (face_down(ray->ra) && ray->dy < 0))
		ray->dy *= -1;
	if (ray->ra ==  M_PI / 2 || ray->ra == 3 * M_PI / 2) // looking left or right
	{
		ray->ry = mlx->player.py;
		ray->rx = mlx->player.px;
		return (8);
	}
	return (0);
}

static void	ver_intersect(t_mlx_data *mlx)
{
	int	dof;
	int	mx, my, mp;
	t_ray	*ray;

	ray = &(mlx->ray);
	dof = init_ver_intersect(mlx);
	while (dof < 8)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		mp = my * mlx->grid.nb_tile_x + mx;
		// hit wall
		if (mp > 0 && (mp < mlx->grid.nb_tile_x * mlx->grid.nb_tile_y) && (mlx->grid.map[mp] == 1))
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dv = calc_d(mlx->player.px, mlx->player.py, ray->vx, ray->vy, ray->ra);
			dof = 8;
		}
		else
		{
			ray->rx += ray->dx;
			ray->ry += ray->dy;
			dof++;
		}
	}
}

static void	nearest_intersect(t_mlx_data *mlx)
{
	t_ray	*ray;

	ray = &(mlx->ray);
	if ((ray->dh == -1) && (ray->dv == -1))
	{
		ray->rx = mlx->player.px;
		ray->ry = mlx->player.py;
	}
	else if ((ray->dh == -1) || ((ray->dv != -1) && (ray->dv <= ray->dh)))
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dist_wall = ray->dv;
		if (face_right(ray->ra))
			ray->col_wall = encode_rgb(67, 97, 117);//encode_rgb(139, 69, 19);
		else
			ray->col_wall = encode_rgb(112, 128, 144);//encode_rgb(160, 82, 45);
//		ray->col_wall = encode_rgb(255 * 0.9, 0, 0);
	}
	else if ((ray->dv == -1) || (((ray->dh != -1) && ray->dh < ray->dv)))
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
		ray->dist_wall = ray->dh;
		if (face_down(ray->ra))
			ray->col_wall = encode_rgb(122, 127, 128);//encode_rgb(205, 133, 63);
		else
			ray->col_wall = encode_rgb(176, 196, 222);//encode_rgb(244, 164, 96);
//		ray->col_wall = encode_rgb(255 * 0.7, 0, 0);
	}
/*	if (ray->dh == -1)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
	}
	else if (ray->dv == -1)
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
	}
	else if (ray->dv <= ray->dh)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
	}
	else if (ray->dv > ray->dh)
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
	}
	else
	{
		ray->rx = mlx->player.px;
		ray->ry = mlx->player.py;
	}*/
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_ray(t_mlx_data *mlx)
{
	int		col;

	hor_intersect(mlx);
	ver_intersect(mlx);
	nearest_intersect(mlx);
	col = encode_rgb(255, 0, 0);
	draw_full_line(mlx, mlx->player.px, mlx->player.py, mlx->ray.rx, mlx->ray.ry, col);
}
