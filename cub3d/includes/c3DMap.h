/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DMap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:04:06 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/03 21:25:14 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DMAP_H
# define C3DMAP_H

# include "c3DMlx.h"

typedef struct s_maze
{
	int		nb_col;
	int		nb_line;
	int		w_tile;
	char	*map;
}	t_maze;

/*typedef struct s_line
{
	int	x;
	int	y;
	int	text_y0;
	int	text_yn;
	int	tex_x;
	int	tex_y;
}	t_line;*/

typedef struct s_map_col
{
	t_mlx_img	tex_no;
	t_mlx_img	tex_so;
	t_mlx_img	tex_we;
	t_mlx_img	tex_ea;
	int			background;
	int			no;
	int			ea;
	int			so;
	int			we;
	int			f;
	int			c;
	int			*col;
//	t_line		line;
}	t_map_col;

typedef struct s_texture
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int		F;
	int		C;
}	t_texture;

#endif