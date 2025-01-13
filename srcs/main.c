/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/13 11:12:15 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	world = (t_world *)malloc(sizeof(t_world));
	world = world_constructor(argc, argv, world);
	world->move = 0;
	world->mlx = mlx_init();
	mlx_get_screen_size(world->mlx, &world->width_w, &world->height_w);
	image_generator(world);
	world->width_w = world->map->width * world->image->img_width;
	world->height_w = world->map->height * world->image->img_height;
	world->window = mlx_new_window(world->mlx, world->width_w, world->height_w,
			"so_long");
	display(world);
	event_handle(world);
	mlx_loop(world->mlx);
	return (0);
}
