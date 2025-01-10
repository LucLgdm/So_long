/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:47:52 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 14:16:36 by lde-merc         ###   ########.fr       */
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
					world->image->wall, j * world->image->img_width, i
					* world->image->img_height);
			else
				mlx_put_image_to_window(world->mlx, world->window,
					world->image->grass, j * world->image->img_height, i
					* world->image->img_width);
		}
	}
}

void	player_display(t_world *world)
{
	mlx_put_image_to_window(world->mlx, world->window, world->image->player,
		world->player->x, world->player->y);
}

void	coin_display(t_world *world)
{
	int	i;
	int	x_tmp;
	int	y_tmp;

	i = -1;
	x_tmp = world->image->img_width;
	y_tmp = world->image->img_height;
	while (world->coin[++i])
		mlx_put_image_to_window(world->mlx, world->window, world->image->coin,
			x_tmp * world->coin[i]->x, y_tmp * world->coin[i]->y);
}

void	exit_display(t_world *world)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = world->image->img_width;
	y_tmp = world->image->img_height;
	mlx_put_image_to_window(world->mlx, world->window, world->image->exit, x_tmp
		* world->exit->x, y_tmp * world->exit->y);
}
