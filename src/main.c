#include "include/so_long.h""
#include <mlx.h>

int main(void)
{
	void	*display;
	void	*window;
	void	*img;

	display = mlx_init();
	window = mlx_new_window(display, 1024, 768, "So long, and thanks for all the fish!");
	mlx_string_put(display, window, 334, 30, 0x913FDA, "It's dangerous to go alone. Take this!");
	img = mlx_new_image(display, 768, 40);
	mlx_loop(display);
	mlx_clear_window;
	mlx_destroy_image;
	mlx_destroy_window;
	mlx_do_key_autorepeatoff;
	mlx_do_key_autorepeaton;
	mlx_do_sync;
	mlx_expose_hook;
	mlx_get_color_value;
	mlx_get_data_addr;
	mlx_get_screen_size;
	mlx_hook;
	mlx_key_hook;
	mlx_loop_hook;
	mlx_mouse_get_pos;
	mlx_mouse_hide;
	mlx_mouse_hook;
	mlx_mouse_move;
	mlx_mouse_show;
	mlx_new_image;
	mlx_new_window;
	mlx_pixel_put;
	mlx_png_file_to_image;
	mlx_put_image_to_window;
	mlx_string_put;
	mlx_sync;
	mlx_xpm_file_to_image;
	mlx_xpm_to_image;
	
	return (0);
}