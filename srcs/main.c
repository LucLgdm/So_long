/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/09 13:57:40 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	world = (t_world *)malloc(sizeof(t_world));
	world = world_constructor(argc, argv, world);
	world->move = 0;
	for(int i = 0; i < world->map->height; i++)
	{
		for(int j = 0; j < world->map->width; j++)
			printf("%c", world->map->map[i][j]);
		printf("\n");
	}
	world->mlx = mlx_init();
	mlx_get_screen_size(world->mlx, &world->width_w, &world->height_w);
	image_generator(world);
	world->width_w = world->map->width * world->map->image[0]->img_width;
	world->height_w = world->map->height * world->map->image[0]->img_height;
    ft_printf("taille fenetre : (%i, %i)\n", world->width_w, world->height_w);
	ft_printf("taille wall : (%i, %i)\n", world->map->image[0]->img_width, world->map->image[0]->img_height);
	ft_printf("taille herbe : (%i, %i)\n", world->map->image[1]->img_width, world->map->image[1]->img_height);
	ft_printf("taille player : (%i, %i)\n", world->player->image->img_width, world->player->image->img_height);
	ft_printf("taille exit : (%i, %i)\n", world->map->texit->image->img_width, world->map->texit->image->img_height);
	world->window = mlx_new_window(world->mlx, world->width_w, world->height_w, "so_long");
	display(world);
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

/*

	for(int i = 0; i < world->map->height; i++)
	{
		for(int j = 0; j < world->map->width; j++)
			printf("%c", world->map->map[i][j]);
		printf("\n");
	}
*/