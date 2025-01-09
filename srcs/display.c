/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:47:52 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/09 14:06:51 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	display(t_world *world)
{
	map_display(world);
	player_display(world);
	coin_display(world);
	exit_display(world);
}

void	map_display(t_world *world)
{
	int	i;
	int	j;

	i = -1;
	while (++i < world->map->height)
	{
		j = -1;
		while (++j < world->map->width)
		{
			if (world->map->map[i][j] == '1')
				mlx_put_image_to_window(world->mlx, world->window,
					world->map->image[0]->img, j * world->map->image[0]->img_width, i * world->map->image[0]->img_height);
			else
				mlx_put_image_to_window(world->mlx, world->window,
					world->map->image[1]->img, j * world->map->image[1]->img_height, i * world->map->image[1]->img_width);
		}
	}
}

void	player_display(t_world *world)
{
	// int	x_tmp;
	// int	y_tmp;

	// x_tmp = world->map->image[0]->img_width;
	// y_tmp = world->map->image[0]->img_height;
	mlx_put_image_to_window(world->mlx, world->window,
		world->player->image->img, world->player->position->x, world->player->position->y);
	
}

void	coin_display(t_world *world)
{
	int	i;
	int	x_tmp;
	int	y_tmp;

	i = -1;
	x_tmp = world->map->image[0]->img_width;
	y_tmp = world->map->image[0]->img_height;
	while (world->map->coin->position[++i])
		mlx_put_image_to_window(world->mlx, world->window,
			world->map->coin->image->img, x_tmp
			* world->map->coin->position[i]->x, y_tmp
			* world->map->coin->position[i]->y);
}

void	exit_display(t_world *world)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = world->map->image[0]->img_width;
	y_tmp = world->map->image[0]->img_height;
	mlx_put_image_to_window(world->mlx, world->window,
		world->map->texit->image->img, x_tmp * world->map->exit->x, y_tmp
		* world->map->exit->y);
}
