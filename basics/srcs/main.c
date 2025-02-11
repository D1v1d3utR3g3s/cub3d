/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:01 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 16:30:29 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static void	display_error(const char *error_msg)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	else
		write(2, "Error\n", 6);
}

int	main(const int argc, const char **argv)
{
	char		*file_path;
	t_c3d_data	c3d;
	int			result;

	c3d.size_map = 64;
	c3d.grid.map = NULL;
	if (parse_c3d_args(&file_path, argc, argv) != 0)
		return (1);
	result = init_c3d_data(&c3d, file_path);
	if (file_path)
	{
		free(file_path);
		file_path = NULL;
	}
	if (result == 1)
		return (display_error(c3d.error_msg), clear_data(&c3d), 1);
	init_player(&c3d.player);
	init_grid(&c3d);
	full_img(&c3d);
	hook_event(&c3d);
	mlx_loop(c3d.mlx_ptr);
	clear_data(&c3d);
	return (0);
}
