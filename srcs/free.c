/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:49 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/20 11:47:01 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	free_all(t_world *world)
{
	int	i;

	i = -1;
	while (world->map->map[++i])
		free(world->map->map[i]);
	// free(world->map->exit);
	// free(world->map->collect);
	// free(world->map->start_pos);
	free(world->map->map);
}
