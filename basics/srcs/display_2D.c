#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
int	is_near_player(t_pix pix, t_player player)
{
	if ((player.px >= pix.x - 2) && (player.px <= pix.x + 2))
	{
		if ((player.py >= pix.y - 2) && (player.py <= pix.y + 2))
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
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
