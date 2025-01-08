/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 16:08:09 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	// Initialisation
	world = (t_world *)malloc(sizeof(t_world));
	world = world_constructor(argc, argv, world);

	for(int i = 0; i < world->map->height; i++)
	{
		for(int j = 0; j < world->map->width; j++)
			printf("%c", world->map->map[i][j]);
		printf("\n");
	}
	world->move = 0;
	world->mlx = mlx_init();
	mlx_get_screen_size(world->mlx, &world->width_w, &world->height_w);
	world->height_w /= 3;
	world->width_w = 2 * world->width_w / 3;
	// Creation of the window
	world->window = mlx_new_window(world->mlx, world->width_w, world->height_w, "so_long");
	image_generator(world);
	event_handle(world);
	mlx_loop(world->mlx);
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