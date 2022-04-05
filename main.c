#include "so_long.h"
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
	
	return (0);
}