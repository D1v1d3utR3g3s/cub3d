#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/*                                 clear_data                                 */
/* -------------------------------------------------------------------------- */
/* This function clear sthe different part generated with mlx (clean img,     */
/* clean window, close the connection to the X server and destroy windows,    */
/* free mlx pointer, the struct generated in mlx_init)                        */
/* Input :                                                                    */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	clear_data(t_mlx_data *mlx)
{
	if (mlx->grid.map)
		free(mlx->grid.map);
	if (!mlx->mlx_ptr)
		exit (1);
	if (mlx->img_ptr.mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr.mlx_img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit (1);
}