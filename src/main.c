#include "../include/so_long.h"

typedef struct	s_data
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_data;

int	closeprogram(int keycode, t_vars *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode != 53)
	{
		data->counter++;
		if (data->counter == 40)
			printf("coucou\n");
	}
	return (0);
}

int	resetcounter(int keycode, t_vars *data)
{
	data->counter = 0;
	return (0);
}

int	printkeycode(int keycode, t_vars *data)
{
	printf("%d\n", keycode);
	return (0);
}

int	closeondestroy(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	longkeydown(int keycode, t_vars *data)
{
	printf("%d\n", keycode);
	return (0);
}

int	printmousepos(int x, int y, t_vars *data)
{
	return (0);
}

/*  

ON_KEYDOWN		2	int (*f)(int keycode, void *param)
ON_KEYUP*		3	int (*f)(int keycode, void *param)
ON_MOUSEDOWN*	4	int (*f)(int button, int x, int y, void *param)
ON_MOUSEUP		5	int (*f)(int button, int x, int y, void *param)
ON_MOUSEMOVE	6	int (*f)(int x, int y, void *param)
ON_EXPOSE*		12	int (*f)(void *param)
ON_DESTROY		17	int (*f)(void *param)

*/

int main(int argc, char *argv[])
{
	t_vars	data;
	t_fence	fence;
	void	*img;
	char	**map;
	char	*relativepath = "../assets/tilesets/picket_hor.xpm";
	int	x,y;
	x = 600;
	y = 400;

	checkarg(argc);
	map = convertmaptostring(argv[1]);
	errorhandling(checkmap(map));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, x, y, "So long, and thanks for all the fish!");
	data.counter = 0;
	fence.img2 = mlx_xpm_file_to_image(data.mlx, "../assets/characters/player.xpm", &fence.img_width2, &fence.img_height2);
	fence.img1 = mlx_xpm_file_to_image(data.mlx, relativepath, &fence.img_width1, &fence.img_height1);
	mlx_put_image_to_window(data.mlx, data.win, fence.img1, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, fence.img2, 14, 0);
	mlx_hook(data.win, ON_KEYDOWN, 0, closeprogram, &data);
	mlx_hook(data.win, ON_DESTROY, 0, closeondestroy, &data);
	mlx_hook(data.win, ON_KEYUP, 0, resetcounter, &data);
	mlx_loop(data.mlx);

	/******* Function defs ********/

	// mlx_clear_window;
	// mlx_destroy_image;
	// mlx_destroy_window;
	// mlx_do_key_autorepeatoff;
	// mlx_do_key_autorepeaton;
	// mlx_do_sync;
	// mlx_expose_hook;
	// mlx_get_color_value;
	// mlx_get_data_addr;
	// mlx_get_screen_size;
	// mlx_hook;
	// mlx_key_hook;
	// mlx_loop_hook;
	// mlx_mouse_get_pos;
	// mlx_mouse_hide;
	// mlx_mouse_hook;
	// mlx_mouse_move;
	// mlx_mouse_show;
	// mlx_new_image;
	// mlx_new_window;
	// mlx_pixel_put;
	// mlx_png_file_to_image;
	// mlx_put_image_to_window;
	// mlx_string_put;
	// mlx_sync;
	// mlx_xpm_file_to_image;
	// mlx_xpm_to_image;
	
	return (0);
}