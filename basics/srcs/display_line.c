#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_point_line(t_mlx_data *mlx, int beginX, int beginY, int endX, int endY, int col)
{
	int	i;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float		nb_point;
	
	i = 0;
	nb_point = sqrt((endX - beginX) * (endX - beginX) + (endY - beginY) * (endY - beginY)) / 10;
	dx = (endX - beginX) / nb_point;
	dy = (endY - beginY) / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > mlx->grid.nb_tile_x * mlx->grid.w_tile)
			x =  mlx->grid.nb_tile_x * mlx->grid.w_tile;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > mlx->grid.nb_tile_y * mlx->grid.w_tile)
			y =  mlx->grid.nb_tile_y * mlx->grid.w_tile;
		img_pix_put(&mlx->img_ptr, x, y, col);
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_full_line(t_mlx_data *mlx, int beginX, int beginY, int endX, int endY, int col)
{
	int	i;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float		nb_point;
	
	i = 0;
	nb_point = sqrt((endX - beginX) * (endX - beginX) + (endY - beginY) * (endY - beginY));
	dx = (endX - beginX) / nb_point;
	dy = (endY - beginY) / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > mlx->grid.nb_tile_x * mlx->grid.w_tile)
			x =  mlx->grid.nb_tile_x * mlx->grid.w_tile;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > mlx->grid.nb_tile_y * mlx->grid.w_tile)
			y =  mlx->grid.nb_tile_y * mlx->grid.w_tile;
		img_pix_put(&mlx->img_ptr, x, y, col);
		i++;
	}
}