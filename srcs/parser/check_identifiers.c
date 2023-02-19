/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_identifiers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/19 13:23:01 by abeznik       #+#    #+#                 */
/*   Updated: 2023/02/19 13:30:28 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static bool	st_check_color_range(int color)
{
	// color = 270; // ? testing
	// color = -67; // ? testing
	// color = 9999999; // ? testing
	if (color >= 0 && color <= 255)
		return (true);
	return (false);
}

static bool	st_check_colors(t_rgb *colors)
{
	// colors = NULL; // ? testing
	if (!colors)
		return (false);
	if (!st_check_color_range(colors->red)
		|| !st_check_color_range(colors->green)
		|| !st_check_color_range(colors->blue))
		return (false);
	return (true);
}

bool	check_identifiers(t_identifiers_data *id_data,
	char *extension)
{
	if (!id_data)
		return (false);
	if (!id_data->north_texture || !id_data->south_texture
		|| !id_data->east_texture || !id_data->west_texture
		|| !id_data->floor || !id_data->ceiling)
		return (false);
	if (!check_ext(id_data->north_texture, extension)
		|| !check_ext(id_data->south_texture, extension)
		|| !check_ext(id_data->east_texture, extension)
		|| !check_ext(id_data->west_texture, extension))
		return (false);
	if (!st_check_colors(id_data->floor)
		|| !st_check_colors(id_data->ceiling))
		return (false);
	return (true);
}
