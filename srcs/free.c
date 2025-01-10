/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 18:05:30 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	free_all(t_world *world)
{
	free_coin(world);
	free_map(world);
	free_image(world);
	free_player_exit(world);
	free(world);
}

void	free_coin(t_world *world)
{
	int	i;

	i = -1;
	if (world->coin)
	{
		while (world->coin[++i])
			free(world->coin[i]);
		free(world->coin);
	}
}

void	free_map(t_world *world)
{
	int	i;

	i = -1;
	if (world->map)
	{
		if (world->map->map)
		{
			while (++i < world->map->height)
			{
				if (world->map->map[i])
					free(world->map->map[i]);
			}
			free(world->map->map);
		}
		free(world->map);
	}
}

void	free_image(t_world *world)
{
	if (world->image)
		free(world->image);
}

void	free_player_exit(t_world *world)
{
	if (world->player)
		free(world->player);
	if (world->exit)
		free(world->exit);
}
