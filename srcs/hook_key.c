/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:15:43 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/09 14:05:37 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hook.h"

int	key_handle(int key, void *data)
{
	t_world	*world;

	world = (t_world *)data;
	if (key == 65307)
		close_window(world);
	move_player(world, key);
	ft_printf("\rNombre de deplacement : %i", world->move);
	return (0);
}

int	close_window(t_world *world)
{
	// mlx_destroy_image(world->mlx, world->player->image->img);
	// mlx_destroy_image(world->mlx, world->map->texit->image->img);
	// mlx_destroy_image(world->mlx, world->map->image[0]->img);
	// mlx_destroy_image(world->mlx, world->map->image[1]->img);
	// mlx_destroy_image(world->mlx, world->map->coin->image->img);
	// mlx_destroy_window(world->mlx, world->window);
	// return (0);
	(void)world;
	exit(0);
}

void	move_player(t_world *world, int key)
{
	mlx_put_image_to_window(world->mlx, world->window, world->map->image[1]->img, world->player->position->x, world->player->position->y);
	if (key == 97 && world->player->position->x - world->map->image[1]->img_width > 0)
	{
		world->player->position->x -= world->map->image[1]->img_width;
		world->move += 1;
	}
	else if (key == 100 && world->player->position->x + world->map->image[1]->img_width < world->width_w - 1)
	{
		world->player->position->x += world->map->image[1]->img_width;
		world->move += 1;
	}
	else if (key == 119 && world->player->position->y - world->map->image[1]->img_height > 0)
	{
		world->player->position->y -= world->map->image[1]->img_height;
		world->move += 1;
	}
	else if (key == 115 && world->player->position->y - world->map->image[1]->img_height < world->height_w - 1)
	{
		world->player->position->y += world->map->image[1]->img_height;
		world->move += 1;
	}
	mlx_put_image_to_window(world->mlx, world->window, world->player->image->img, world->player->position->x, world->player->position->y);
}
