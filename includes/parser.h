/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edawood <edawood@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:04:23 by abeznik           #+#    #+#             */
/*   Updated: 2023/02/19 11:27:32 by edawood          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ERROR -1

# include <cub3D.h>

bool	parser(int argc, char *argv[], t_file_data *file_data);
void	init_map_file_data(t_file_data *file_data);
bool	check_ext(char *file_name, t_file_data *file_data);
bool	check_map(char *file_name, t_file_data *file_data);
char	*read_file(t_file_data *data);

#endif
