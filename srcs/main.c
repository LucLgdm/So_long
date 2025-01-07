/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/07 15:24:50 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int height_screen, width_screen;

int	main(int argc, char **argv)
{
	t_world	*world;

	// Initialisation
	world = (t_world *)malloc(sizeof(t_world));
	world = world_constructor(argc, argv, world);

	// image_generator(world);
	
	world->mlx = mlx_init();
	mlx_get_screen_size(world->mlx, &width_screen, &height_screen);
	world->height_w = height_screen / 2;
	world->width_w = width_screen / 2;
	
	// Creation of the window
    world->window = mlx_new_window(world->mlx, world->width_w, world->height_w, "so_long");
	
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