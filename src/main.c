#include "../include/so_long.h"

int	closeprogram(int keycode, t_player *player)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(player->vars.mlx, player->vars.win);
		exit(0);
	}
	printf("%d\n", keycode);
	if (keycode == UPKEY)
		player->y_pos -= 1;
	if (keycode == DOWNKEY)
		player->y_pos += 1;
	if (keycode == LEFTKEY)
		player->x_pos -= 1;
	if (keycode == RIGHTKEY)
		player->x_pos += 1;
	return (0);
}

int	printkeycode(int keycode, t_player *player)
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

void	update_frame(t_player *player, int keycode)
{
	mlx_clear_window(player->vars.mlx, player->vars.win);
	player->steps += 1;
	if (keycode == UPKEY)
		player->y_pos -= 1;
	if (keycode == DOWNKEY)
		player->y_pos += 1;
	if (keycode == LEFTKEY)
		player->x_pos -= 1;
	if (keycode == RIGHTKEY)
		player->x_pos += 1;
}

//Similar to player_init but will init different images to be used for walls, floors etc aswell as the size of the map
//given as x and y
void	env_init(t_env *env, t_vars vars, char **map)
{
	my_xpm_file_to_image("exit.xpm", vars, &env->exit);
	get_map_size(map, &env->y_len, &env->x_len);
}

int	render(t_player *player)
{
	mlx_clear_window(player->vars.mlx, player->vars.win);
	mlx_put_image_to_window(player->vars.mlx, player->vars.win,
		player->img.img, (player->x_pos * 16), (player->y_pos * 16));
	mlx_key_hook(player->vars.win, closeprogram, player);
	mlx_string_put(player->vars.mlx, player->vars.win, 5, 15, 0xFFFFFF, "Steps:");
	mlx_string_put(player->vars.mlx, player->vars.win, 75, 15, 0xFFFFFF, ft_itoa((long long) player->steps));
	return (0);
}

int	move_player(int keycode, t_player player)
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
	t_env		env;
	t_player	player;
	char		**map;

	checkarg(argc);
	map = convertmaptostring(argv[1]);
	errorhandling(checkmap(map));
	player.vars.mlx = mlx_init();
	player.vars.win = mlx_new_window(player.vars.mlx, 600, 400, "So long, and thanks for all the fish!");
	player_init(&player, map);
	env_init(&env, player.vars, map);
	mlx_hook(player.vars.win, ON_DESTROY, 0, closeondestroy, &player.vars);
	mlx_loop_hook(player.vars.mlx, render, &player);
	mlx_loop(player.vars.mlx);

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