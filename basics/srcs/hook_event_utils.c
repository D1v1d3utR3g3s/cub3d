#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	keys_wasd(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_W || keysym == XK_w)
	{
		mlx->player.px += mlx->player.dx;
		mlx->player.py += mlx->player.dy;
	}
	else if (keysym == XK_A || keysym == XK_a)
	{
		mlx->player.px += cos(mlx->player.pa - (M_PI / 2)) * 5;
		mlx->player.py += sin(mlx->player.pa - (M_PI / 2)) * 5;
	}
	else if (keysym == XK_S || keysym == XK_s)
	{
		mlx->player.px -= mlx->player.dx;
		mlx->player.py -= mlx->player.dy;
	}
	else if (keysym == XK_D || keysym == XK_d)
	{
		mlx->player.px += cos(mlx->player.pa + (M_PI / 2)) * 5;
		mlx->player.py += sin(mlx->player.pa + (M_PI / 2)) * 5;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* ************************************************************************** */
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
		mlx->player.pa -= 0.1;
		if (mlx->player.pa < 0)
			mlx->player.pa += 2 * M_PI;
		mlx->player.dx = cos(mlx->player.pa) * 5;
		mlx->player.dy = sin(mlx->player.pa) * 5;
	}
	else if (keysym == XK_Right)
	{
		mlx->player.pa += 0.1;
		if (mlx->player.pa > 2 * M_PI)
			mlx->player.pa -= 2 * M_PI;
		mlx->player.dx = cos(mlx->player.pa) * 5;
		mlx->player.dy = sin(mlx->player.pa) * 5;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
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