#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/*                                key_handler                                 */
/* -------------------------------------------------------------------------- */
/* This function defines what will happened when some specifics key are       */
/* pressed (Esc, arrows, and in my case '+' and '-' as well as Space)         */
/* Inputs :                                                                   */
/*  - int keysym : abstract representation of the key (regardless hardware)   */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	key_handler(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
	{
		clear_data(mlx);
		exit (1);
	}
	if (is_key_wasd(keysym))
	{
		keys_wasd(keysym, mlx);
		full_img(mlx);
	}
	if (is_key_array(keysym))
	{
		keys_array(keysym, mlx);
		full_img(mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                               close_handler                                */
/* -------------------------------------------------------------------------- */
/* This function links the close the window in a clean way when the cross     */
/* button is clicked                                                          */
/* Inputs :                                                                   */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	close_handler(t_mlx_data *mlx)
{
	clear_data(mlx);
	exit(1);
	return (0);
}

/* ************************************************************************** */
/*                                 hook_event                                 */
/* -------------------------------------------------------------------------- */
/* This function links an action to an event (key, mouse, button)             */
/* Inputs :                                                                   */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	hook_event(t_mlx_data *mlx)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, key_handler, mlx);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, mlx);
}