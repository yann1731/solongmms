#include "../include/so_long.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_data
{
	void	*img;
}	t_data;

int	closeprogram(int keycode, t_vars *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	printkeycode(int keycode, t_vars *data)
{
	printf("%d\n", keycode);
	return (0);
}

int main(int argc, char *argv[])
{
	// t_vars	data;
	// void	*img;
	char	**map;
	int		mapstatus;

	if (argc != 2)
	{
		write(2, "Needs map as input\n", ft_strlen("Needs map as input\n"));
		exit(1);
	}
	map = convertmaptostring(argv[1]);
	mapstatus = checkmap(map);
	printf("%d\n", mapstatus);
	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, 1024, 768, "So long, and thanks for all the fish!");
	// mlx_string_put(data.mlx, data.win, 334, 30, 0x913FDA, "It's dangerous to go alone. Take this!");
	// mlx_hook(data.win, 2, 0, closeprogram, &data);
	// mlx_loop(data.mlx);

	//****** Function defs ********
//	mlx_clear_window;
//	mlx_destroy_image;
//	mlx_destroy_window;
//	mlx_do_key_autorepeatoff;
//	mlx_do_key_autorepeaton;
//	mlx_do_sync;
//	mlx_expose_hook;
//	mlx_get_color_value;
//	mlx_get_data_addr;
//	mlx_get_screen_size;
//	mlx_hook;
//	mlx_key_hook;
//	mlx_loop_hook;
//	mlx_mouse_get_pos;
//	mlx_mouse_hide;
//	mlx_mouse_hook;
//	mlx_mouse_move;
//	mlx_mouse_show;
//	mlx_new_image;
//	mlx_new_window;
//	mlx_pixel_put;
//	mlx_png_file_to_image;
//	mlx_put_image_to_window;
//	mlx_string_put;
//	mlx_sync;
//	mlx_xpm_file_to_image;
//	mlx_xpm_to_image;
	
	return (0);
}