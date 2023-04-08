#include <cub3D.h>
#include "../includes/graphics.h"

int	main(int argc, char *argv[])
{
	t_general_data	data;
	// t_file_data		file_data;
	// t_graphics	graphics;

	if (!parser(argc, argv, &data))
		return (1);
	if (!run_graphics(&data))
	{
		return (1);
		// return (terminate(data.graphics), false);
		// mlx_terminate(data.graphics->mlx);
	}
	// free(file_data.line);
	// system("leaks cub3D");
	return (0);
}
