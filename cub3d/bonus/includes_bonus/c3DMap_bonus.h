/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DMap_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:04:06 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:56:42 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DMAP_H
# define C3DMAP_H

# include "c3DMlx_bonus.h"

typedef struct s_maze
{
	int		nb_col;
	int		nb_line;
	int		w_tile;
	char	*map;
}	t_maze;

typedef struct s_map_col
{
	t_mlx_img	tex_no;
	t_mlx_img	tex_so;
	t_mlx_img	tex_we;
	t_mlx_img	tex_ea;
	t_mlx_img	tex_door;
	int			background;
	int			no;
	int			ea;
	int			so;
	int			we;
	int			f;
	int			c;
	int			*col;
}	t_map_col;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		f;
	int		c;
}	t_texture;

typedef struct s_minimap
{
	float	coef;
	int		x0;
	int		y0;
	int		w;
	int		h;
	int		w_tile;
	int		mmp_x;
	int		mmp_y;
	float	mmp_px;
	float	mmp_py;
	float	mmp_dx;
	float	mmp_dy;
}	t_minimap;

#endif
