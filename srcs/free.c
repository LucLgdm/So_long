/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/03 14:11:41 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	free_all(t_world *world)
{
	free_map(world);
	free(world);
}

void	free_map(t_world *world)
{
	int	i;

	i = -1;
	if (world->map->start_pos)
		free(world->map->start_pos);
	if (world->map->exit)
		free(world->map->exit);
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
