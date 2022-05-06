#ifndef SO_LONG_H
# define SO_LONG_H
# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

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
	ON_DESTROY = 17,
	UPKEY = 126,
	DOWNKEY = 125,
	LEFTKEY = 123,
	RIGHTKEY = 124,
	ESC = 53
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

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
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_player
{
	char	**map;
	t_vars	vars;
	t_data	pimg;
	t_data	s_pimg;
	t_data	floor;
	t_data	s_floor;
	t_data	wall;
	t_data	coll;
	t_data	o_coll;
	t_data	s_coll;
	t_data	s_o_coll;
	t_data	exit;
	t_data	s_exit;
	int		x_pos;
	int		y_pos;
	int		x_map;
	int		y_map;
	int		steps;
	int		max_collectibles;
	int		held_collectibles;
}	t_player;

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
void			player_init(t_player *player, char **map);
void			my_xpm_file_to_image(char	*pathtoimg, t_vars vars, t_data *img);
void			my_get_data_addr(t_data *img);
int				render(t_player *player);
void			update_frame(t_player *player, int keycode);
void			get_map_size(char **map, int *y_map, int *x_map);
int				closeondestroy(t_vars *data);
void			closeprogram(t_player *player);
void			render_floor(t_player *player);
void			move_up(t_player *player);
void			move_down(t_player *player);
void			move_left(t_player *player);
void			move_right(t_player *player);
void			my_mlx_put_img(t_vars *vars, t_data *img, int x, int y);
int				checkcoll(char **map);
int				move_player(int keycode, t_player *player);
int				render(t_player *player);
void			render_walls(t_player *player);
void			render_floor(t_player *player);
void			replace_p(t_player *player);
void			update_coll(t_player *player, int x, int y);
void			update_ocoll(t_player *player, int x, int y);
void			update_exit(t_player *player, int x, int y);
int				checkmapformat(char *argv);

#endif