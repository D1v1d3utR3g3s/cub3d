/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DMlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxane <roxane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:20:58 by roxane            #+#    #+#             */
/*   Updated: 2025/02/14 12:25:20 by roxane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DMLX_H
# define C3DMLX_H

# include "../minilibx-linux/mlx.h"
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
//	int f_XK_Up;
//	int f_XK_Down;
	int f_XK_Left;
	int f_XK_Right;
	int f_XK_W;
	int f_XK_A;
	int f_XK_S;
	int f_XK_D;
}	t_event;

#endif