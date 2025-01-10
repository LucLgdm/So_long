/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 12:47:49 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	free_all(t_world *world)
{
	free_coin(world);
	// free_map(world);
	// free_image(world);
	free(world);
}

void	free_coin(t_world *world)
{
	int	i;

	i = -1;
	if (world->coin)
	{
		while (++i < world->map->c - 1)
			free(world->coin[i]);
	}
	free(world->coin);
}

// void	free_map(t_world *world)
// {
// 	int	i;

// 	i = -1;
// 	if (world->map->start_pos)
// 		free(world->map->start_pos);
// 	if (world->map->exit)
// 		free(world->map->exit);
// 	if (world->map->texit->image)
// 	{
// 		free(world->map->texit->image->img);
// 		free(world->map->texit->image);
// 	}
// 	if (world->map->texit)
// 		free(world->map->texit);
// 	if (world->map->map)
// 	{
// 		while (++i < world->map->height)
// 		{
// 			if (world->map->map[i])
// 				free(world->map->map[i]);
// 		}
// 		free(world->map->map);
// 	}
// 	free(world->map);
// }



// void	free_image(t_world *world)
// {
// 	int	i;

// 	i = -1;
// 	if (world->map->image)
// 	{
// 		while (world->map->image[++i])
// 		{
// 			free(world->map->image[i]->img);
// 			free(world->map->image[i]);
// 		}
// 		free(world->map->image);
// 	}
// }
