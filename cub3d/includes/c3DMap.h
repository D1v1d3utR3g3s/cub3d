
#ifndef C3DMAP_H
# define C3DMAP_H

typedef struct s_maze
{
	int		nb_col;
	int		nb_line;
	int		w_tile;
	char	*map;
}   t_maze;

typedef struct s_map_col
{
	int	background;

	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
	int	f;

	int	*col;
}	t_map_col;

typedef struct s_texture
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int		F;
	int		C;
}   t_texture;

#endif