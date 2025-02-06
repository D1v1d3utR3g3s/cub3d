#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/*                                img_pix_put                                 */
/* -------------------------------------------------------------------------- */
/* This function clear the different part generated with mlx (this contained  */
/*  the mlx pointer, the window as well as the image )                        */
/* Input :                                                                    */
/*  - t_mlx_img *img : a pointer to a structure used for mlx images           */
/*  - int x : the x coordinate of the pixel                                   */
/*  - int y : the y coordinate of the pixel                                   */
/*  - int col : the color that we desire for the pixel                        */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	img_pix_put(t_mlx_img *img, int x, int y, int col)
{
	int		offset;
	char	*pix_dest;

	offset = (y * img->line_len + x * (img->bpp / 8));
	pix_dest = img->addr + offset;
	*(unsigned int *)pix_dest = col;
}

/* ************************************************************************** */
/*                                 encode_rgb                                 */
/* -------------------------------------------------------------------------- */
/* This function converts a RGB value into an integer                         */
/* Input :                                                                    */
/*  - u_int8_t red : the Red value of the color wanted                        */
/*  - u_int8_t green : the Green value of the color wanted                    */
/*  - u_int8_t blue : the Blue value of the color wanted                      */
/* Return :                                                                   */
/*  - int the integer that correspond to the color defined with RGB           */
/* ************************************************************************** */
int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	is_near_player(t_pix pix, t_player player)
{
	if ((player.px >= pix.x - 2) && (player.px <= pix.x + 2))
	{
		if ((player.py >= pix.y - 2) && (player.py <= pix.y + 2))
			return (1);
	}
	return (0);
}

// void	draw_map2D(t_grid *grid)
// {
// 	int	x;
// 	int	y;
// 	int	x0;
// 	int	y0;

// 	y = 0;
// 	while (y < grid->nb_tile_y)
// 	{
// 		x = 0;
// 		while (x < grid->nb_tile_x)
// 		{
// 			if (grid[y * grid->nb_tile_x + x] == 1)
// 				wall_col = white;
// 			else
// 				wall_col = bkground;
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	wall_col(t_pix *pix, t_grid *grid, int black, int white)
{
	int	case_x;
	int	case_y;
	int	grey;

	grey = encode_rgb(125, 125, 125);
	case_x = pix->x / grid->w_tile;
	case_y = pix->y / grid->w_tile;
	pix->col = black;
	if (pix->x % grid->w_tile == 0 || pix->y % grid->w_tile == 0)
		pix->col = grey;
	else if (grid->map[case_y * grid->nb_tile_x + case_x] == 1)
		pix->col = white;
	if (grid->map[case_y * grid->nb_tile_x + case_x] != 0 && grid->map[case_y * grid->nb_tile_x + case_x] != 1)
		printf("ERROR\n");

}

void	full_img(t_mlx_data *mlx)
{
	t_pix	pix;
	int		black;
	int		white;
	int		green;

	black = encode_rgb(0, 0, 0);
	white = encode_rgb(255, 255, 255);
	green = encode_rgb(0, 255, 0);
	pix.y = 0;
	while (pix.y < mlx->h)
	{
		pix.x = 0;
		while (pix.x < mlx->w)
		{
			wall_col(&pix, &mlx->grid, black, white);
			if (is_near_player(pix, mlx->player))
            {
				pix.col = green;
            }
			img_pix_put(&mlx->img_ptr, pix.x, pix.y, pix.col);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.mlx_img,
		0, 0);
}