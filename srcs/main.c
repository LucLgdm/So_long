/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/02 14:27:58 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int	main(int argc, char **argv)
{
	t_world	*world;
	void    *mlx;
	void	*window;
	int		height;
	int		width;

	world = NULL;
	world = world_constructor(argc, argv, world);
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &height, &width);
	window = mlx_new_window(mlx, height, width, "So_long");
    world->data->img = mlx_new_image(mlx, height, width);
	world->data->addr = mlx_get_data_addr(world->data->img, 
		&world->data->bits_per_pixel, &world->data->line_length,
		&world->data->endian);
	mlx_put_image_to_window(mlx, window, world->data->img, 0, 0);
    mlx_loop(mlx);
	free_all(world);
	return (0);
}

/************************************************************************
 * Map's parsing
 * 	_ char : 1, 0, C, E, P; only 1 S, 1 P, at least 1 C : return Error\n
 * 	_ surrounded by wall : return Error\n
 * 	_ must be a rectangle : return Error\n
 * 	_ One valid way to reach the exit and all the items : return Error\n
 ************************************************************************/