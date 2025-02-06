#include "../includes/mlxBasic.h"

int	init_player(t_player *player)
{
	player->px = 300;
	player->py = 300;
	player->angle = 3 * M_PI / 2;
	player->dx = cos(player->angle) * 5;
	player->dy = sin(player->angle) * 5;
	return (0);
}

int *transpose_map(char *map)
{
    int *tmp;
    int i;

    i = 0;
    tmp = NULL;
    tmp = (int *)malloc(sizeof(int) * strlen(map));
    // check prior to this function or right after if == NULL
    if (!map || !map[0])
        return (NULL);
    while (map[i])
    {
        tmp[i] = map[i] - '0';
        i++;
    }
    return (tmp);
}

/*	1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1*/
int	init_grid(t_mlx_data *mlx)
{
	mlx->grid.nb_tile_x = 8;
	mlx->grid.nb_tile_y = 8;
	mlx->grid.w_tile = 64;
    char *map;
    map = "11111111\
10010001\
10100001\
11000111\
11110011\
10010101\
10000111\
11111111";
	mlx->grid.map = transpose_map(map);
    return (0);
}

/* ************************************************************************** */
/*                                 init_image                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx image datas needed for creating a  */
/* new mlx compatible image (new image instance pointer, memory address of    */
/* the given image)                                                           */
/* Input :                                                                    */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
int	init_image(t_mlx_data *mlx)
{
	mlx->img_ptr.mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->w, mlx->h);
	if (mlx->img_ptr.mlx_img == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		printf("ERROR - with the mlx image generation\n");
		return (1);
	}
	mlx->img_ptr.addr = mlx_get_data_addr(mlx->img_ptr.mlx_img,
			&mlx->img_ptr.bpp, &mlx->img_ptr.line_len, &mlx->img_ptr.endian);
	return (0);
}

/* ************************************************************************** */
/*                                init_window                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx window datas needed for creating   */
/* a window (new window instance pointer, size, title)                        */
/* Input :                                                                    */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
int	init_window(t_mlx_data *mlx)
{
	mlx->w = 512; 
	mlx->h = 512;
	mlx->title = "Test Ray Tracing";
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w,
			mlx->h, mlx->title);
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		printf("ERROR - with the mlx window generation\n");
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                               init_mlx_data                                */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx datas needed for having a display  */
/* (this contained the mlx pointer, the window - with height, width, title-   */
/* and it's pointer as well as the image - with pointer and address)          */
/* Input :                                                                    */
/*  - t_mlx_data *mlx : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/* ************************************************************************** */
int	init_mlx_data(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		printf("ERROR - with the mlx initialisation\n");
		exit (1);
	}
	if (init_window(mlx) == 1)
		exit (1);
	if (init_image(mlx) == 1)
		exit (1);
	return (0);
}