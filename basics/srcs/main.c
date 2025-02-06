#include "../includes/mlxBasic.h"

int	main(void)
{
	t_mlx_data	mlx;
    mlx.size_map = 64;

	init_mlx_data(&mlx);
	init_player(&mlx.player);
	init_grid(&mlx);

    full_img(&mlx);
	hook_event(&mlx);
	mlx_loop(mlx.mlx_ptr);
    
	clear_data(&mlx);
	return (0);
}