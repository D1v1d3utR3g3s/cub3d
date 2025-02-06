#include "../includes/mlxBasic.h"


void	keys_wasd(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_W || keysym == XK_w)
		mlx->player.py -= 5;
	else if (keysym == XK_A || keysym == XK_a)
		mlx->player.px -= 5;
	else if (keysym == XK_S || keysym == XK_s)
		mlx->player.py += 5;
	else if (keysym == XK_D || keysym == XK_d)
		mlx->player.px += 5;
}

int	is_key_wasd(int	keysym)
{
	if (keysym == XK_W || keysym == XK_w)
		return (1);
	if (keysym == XK_A || keysym == XK_a)
		return (1);
	if (keysym == XK_S || keysym == XK_s)
		return (1);
	if (keysym == XK_D || keysym == XK_d)
		return (1);
	return (0);
}

void	keys_array(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Up)
	{
		mlx->player.px += mlx->player.dx;
		mlx->player.py += mlx->player.dy;
	}
	else if (keysym == XK_Down)
	{
		mlx->player.px -= mlx->player.dx;
		mlx->player.py -= mlx->player.dy;
	}
	else if (keysym == XK_Left)
	{
		mlx->player.angle -= 0.1;
		if (mlx->player.angle < 0)
			mlx->player.angle += 2 * M_PI;
		mlx->player.dx = cos(mlx->player.angle) * 5;
		mlx->player.dy = sin(mlx->player.angle) * 5;
	}
	else if (keysym == XK_Right)
	{
		mlx->player.angle += 0.1;
		if (mlx->player.angle > 2 * M_PI)
			mlx->player.angle -= 2 * M_PI;
		mlx->player.dx = cos(mlx->player.angle) * 5;
		mlx->player.dx = sin(mlx->player.angle) * 5;
	}
}

int	is_key_array(int keysym)
{
	if (keysym == XK_Up)
		return (1);
	if (keysym == XK_Down)
		return (1);
	if (keysym == XK_Left)
		return (1);
	if (keysym == XK_Right)
		return (1);
	return (0);
}

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