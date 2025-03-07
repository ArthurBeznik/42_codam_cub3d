#include <cub3D.h>
#include <graphics.h>

int	main(int argc, char *argv[])
{
	t_general_data	data;

	if (!parser(argc, argv, &data))
	{
		free_data(&data);
		return (1);
	}
	if (!run_graphics(&data))
	{
		free_data(&data);
		return (1);
	}
	free_data(&data);
	terminate_textures(&data);
	return (0);
}
