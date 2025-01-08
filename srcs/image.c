/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 09:36:55 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	image_generator(t_world *world)
{
	world->width_w = world->map->width;
	world->height_w = world->map->height;
	image_map(world);
	world->player->image = mlx_xpm_file_to_image(world->mlx,
			"../textures/player.xpm", &(world->player->position->x),
			&(world->player->position->y));
	image_coin(world);
}

void	image_map(t_world *world)
{
	int	i;
	int	j;

	i = -1;
	world->map->image = malloc(world->map->height * sizeof(void *));
	if (!world->map->image)
		print_message_and_exit("Error malloc image\n");
	while (++i < world->map->height)
	{
		world->map->image[i] = malloc(world->map->width * sizeof(void));
		if (!world->map->image[i])
			print_message_and_exit("Error malloc image[i]\n");
	}
	i = -1;
	while (++i < world->map->width)
	{
		j = -1;
		while (++j < world->map->height)
		{
			if (world->map->map[i][j] == '1')
				world->map->image[i][j] = mlx_xpm_file_to_image(world->mlx,
						"../textures/wall.xpm", &i, &j);
			if (world->map->map[i][j] == '0')
				world->map->image[i][j] = mlx_xpm_file_to_image(world->mlx,
						"../textures/empty.xpm", &i, &j);
		}
	}
}

void	image_coin(t_world *world)
{
	int	i;

	i = -1;
	while (world->map->coin->position[++i])
	{
		world->map->coin->image = mlx_xpm_file_to_image(world->mlx,
				"../texture/coin.xmp", &(world->map->coin->position[i]->x),
				&(world->map->coin->position[i]->y));
	}
}
