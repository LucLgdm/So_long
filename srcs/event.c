/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:17:45 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 16:24:05 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hook.h"

void	event_handle(t_world *world)
{
	mlx_key_hook(world->window, key_handle, world);
}

int	key_handle(int key, void *data)
{
	t_world	*world;

	world = (t_world *)data;
	if (key == 65307)
		close_window();
	if (key == 97)
		world->player->position->x -= world->map->image[0]->img_width;
	if (key == 100)
		world->player->position->x += world->map->image[0]->img_width;
	if (key == 115)
		world->player->position->y += world->map->image[0]->img_width;
	if (key == 119)
		world->player->position->y -= world->map->image[0]->img_width;
    world->move++;
    ft_printf("\rNombre de deplacement : %i", world->move);
	return (0);
}

int	close_window(void)
{
	printf("Closing window...\n");
	exit(0);
}
