#include <graphics.h>

static void	init_direction(t_general_data *data, int x, int y)
{
	int	centered;

	centered = PIXELS / 2;
	if (data->file_data->map_data->map[y][x] == 'N')
		data->file_data->player->angle = 1.5 * PI;
	else if (data->file_data->map_data->map[y][x] == 'S')
		data->file_data->player->angle = 0.5 * PI;
	else if (data->file_data->map_data->map[y][x] == 'W')
		data->file_data->player->angle = 1.0 * PI;
	else if (data->file_data->map_data->map[y][x] == 'E')
		data->file_data->player->angle = 2.0 * PI;
	// fprintf(stderr, "x: %d | y: %d\n", x, y); // ? testing
	// log_positions(data, "init_dir", 'A'); // ? testing
	data->file_data->player->x = (x * PIXELS) + centered; // (+ PIXELS / 2) => gets the exact player x
	data->file_data->player->y = (y * PIXELS) + centered; // "" gets the exact player y
	// log_positions(data, "init_dir", 'P'); // ? testing
	// log_positions(data, "init_dir", 'G'); // ? testing
	data->file_data->player->dx = cos(data->file_data->player->angle) * MOVE_SPEED; // ? * 5 because these are very small values
	data->file_data->player->dy = sin(data->file_data->player->angle) * MOVE_SPEED; // ? also affects the speed of the player
	// log_positions(data, "init_dir", 'D'); // ? testing
	data->graphics->init_dir = true;
}

static bool	draw_gridlines(char	**map, t_general_data *data, int map_height)
{
	int	y;
	int	x;
	int	curr_line_len;
	int	ret_v;
	int	ret_h;

	y = 0;
	while (y < map_height)
	{
		curr_line_len = ft_strlen(map[y]);
		x = 0;
		while (x < curr_line_len)
		{
			ret_v = draw_line(data, x * PIXELS, y * PIXELS, V);
			ret_h = draw_line(data, x * PIXELS, y * PIXELS, H);
			if (!ret_v || !ret_h)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static bool	draw_cells(char	**map, t_general_data *data, int map_height)
{
	int	y;
	int	x;
	int	curr_line_len;
	int	ret;

	y = 0;
	curr_line_len = 0;
	while (y < map_height)
	{
		curr_line_len = ft_strlen(map[y]);
		x = 0;
		while (x < curr_line_len)
		{
			if (map[y][x] == '1')
				ret = draw_square(data, x * PIXELS, y * PIXELS, 0x000000FF, false);
			else if (map[y][x] == '0')
				ret = draw_square(data, x * PIXELS, y * PIXELS, 0xFFFFFFFF, false);
			else if (map[y][x] == 'X')
				ret = draw_square(data, x * PIXELS, y * PIXELS, 0x00000000, false);
			else if (is_player((const char)map[y][x]))
			{
				ret = draw_square(data, x * PIXELS, y * PIXELS, 0xFFFFFFFF, false);
				if (data->graphics->init_dir == false)
					init_direction(data, x, y);
			}
			if (ret == false)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	draw_2d_map(t_general_data *data)
{
	if (!draw_cells(data->file_data->map_data->copy, data, data->file_data->map_data->row))
		return (error_msg("Drawing cells"));
	if (!draw_gridlines(data->file_data->map_data->copy, data, data->file_data->map_data->row))
		return (error_msg("Drawing gridlines"));
	if (!draw_player(data, data->graphics->img))
		return (error_msg("Drawing player"));
	return (true);
}
