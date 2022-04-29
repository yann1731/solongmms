#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../src/libft/libft.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_criteria
{
	int	C;
	int	P;
	int	E;
}	t_criteria;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_player
{
	t_data	img1;
	t_data	img2;
	t_data	img3;
	t_data	img4;
	t_data	img5;
	t_data	img6;
	int		x_pos;
	int		y_pos;
	int		steps;
}	t_player;

typedef struct s_env
{
	t_data	floor1;
	t_data	floor2;
	t_data	floor3;
	t_data	floor4;
	t_data	wall1;
	t_data	wall2;
	t_data	wall3;
	t_data	wall4;
	t_data	exit;
	int		x_map;
	int		y_map;
}	t_env;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

char			**convertmaptostring(char *mapfile);
int				countlines(char *mapfile);
int				checkmap(char **map);
int				validchar(char c);
int				checkboundaries(char **map, int lines);
int				checkbody(char **map, int lines);
int				checkcriteria(char **map, int lines, t_criteria info);
int				parsecriteria(t_criteria info);
int				checkshape(char **map, int lines);
void			checkarg(int argc);
void			initinfo(t_criteria *info);
void			errorhandling(int status);
unsigned int    get_colors(t_data *data, int x, int y);
t_data    		image_scale_init(t_data *image, float scale, void *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			get_player_pos(char **map, int *x_pos, int *y_pos);
void			player_init(t_player *player, t_vars vars, char **map);
void			my_xpm_file_to_image(char	*pathtoimg, t_vars vars, t_data *img);
void			my_get_data_addr(t_data *img);

#endif