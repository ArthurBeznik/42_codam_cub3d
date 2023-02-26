/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edawood <edawood@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:05:10 by arthurbezni       #+#    #+#             */
/*   Updated: 2023/02/22 19:14:38 by edawood          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int	main(int argc, char *argv[])
{
	t_graphics	graphics;

	(void)argc;
	(void)argv;
	if (!run_graphics(&graphics))
		return (1);
	return (0);
}
