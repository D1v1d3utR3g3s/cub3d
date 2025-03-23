/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DMlx_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:20:58 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 21:57:27 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DMLX_H
# define C3DMLX_H

# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_pix
{
	int	x;
	int	y;
	int	col;
}	t_pix;

typedef struct s_mlx_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_mlx_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			h;
	int			w;
	char		*title;
	t_mlx_img	img_ptr;
}	t_mlx;

typedef struct s_event
{
	int	f_xk_left;
	int	f_xk_right;
	int	f_xk_w;
	int	f_xk_a;
	int	f_xk_s;
	int	f_xk_d;
}	t_event;

#endif
