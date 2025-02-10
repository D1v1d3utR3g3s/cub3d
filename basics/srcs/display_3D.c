#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_3D_line(t_mlx_data *mlx, int beginX, int beginY, int endX, int endY, int col)
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
		else if (x > mlx->w)
			x =  mlx->w;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > mlx->h)
			y =  mlx->h;
		img_pix_put(&mlx->img_ptr, x, y, col);
		i++;
	}
}

void    draw3D(t_mlx_data *mlx, int r)
{
	float	lineH;
    float   offset;
    float   angle_offset;
	int		i;

    angle_offset = update_angle(mlx->player.pa, -mlx->ray.ra);
	lineH = (64 * 320) / (mlx->ray.dist_wall * cos(angle_offset));
	if (lineH > 320)
		lineH = 320;
	if (lineH < 0)
	{
		printf("no height\n");
		lineH = 0;
	}
    offset = 160 - lineH / 2;
	i = 0;
	while (i < 8)
	{
		draw_3D_line(mlx, 530 + 8 * r + i, 0 + offset, 530 + 8 * r + i, lineH + offset, mlx->ray.col_wall);
		i++;
	}
}