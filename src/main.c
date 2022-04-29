#include "../include/so_long.h"

int	closeprogram(int keycode, t_vars *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
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

//x and y coordinates passed by adressed for values
//to be modified in accordance with the length of the map on the x axis and y axis
void	get_map_size(char **map, int *y_map, int *x_map)
{
	*y_map = 0;
	*x_map = 0;
	while (map[*y_map])
		*y_map += 1;
	while (map[0][*x_map] != '\n')
		*x_map += 1;
}

//Similar to player_init but will init different images to be used for walls, floors etc aswell as the size of the map
//given as x and y
void	env_init(t_env *env, t_vars vars, char **map)
{
	env->exit.img = mlx_xpm_file_to_image(vars.mlx, "../assets/tilesets/exit/exit.xpm", &env->exit.width, &env->exit.height);
	env->exit.addr = mlx_get_data_addr(env->exit.img, &env->exit.bits_per_pixel, &env->exit.line_length, &env->exit.endian);
	get_map_size(map, &env->y_map, &env->x_map);
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
	t_vars		vars;
	t_env		env;
	t_player	player;
	char		**map;

	checkarg(argc);
	map = convertmaptostring(argv[1]);
	errorhandling(checkmap(map));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So long, and thanks for all the fish!");
	player_init(&player, vars, map);
	//env_init(&env, vars, map);
	//player.img1 = image_scale_init(&player.img1, 3.0, vars.mlx);
	//env.exit1 = image_scale_init(&env.exit1, 4.0, vars.mlx);
	mlx_put_image_to_window(vars.mlx, vars.win, player.img1.img, 60, 60);
	mlx_hook(vars.win, ON_KEYDOWN, 0, closeprogram, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, closeondestroy, &vars);
	mlx_loop(vars.mlx);

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