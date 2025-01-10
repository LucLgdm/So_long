/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:15:43 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 17:54:14 by lde-merc         ###   ########.fr       */
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
	(void)world;
	mlx_destroy_image(world->mlx, world->image->wall);
    mlx_destroy_image(world->mlx, world->image->grass);
    mlx_destroy_image(world->mlx, world->image->player);
    mlx_destroy_image(world->mlx, world->image->coin);
    mlx_destroy_image(world->mlx, world->image->exit);
	mlx_destroy_window(world->mlx, world->window);
	free_all(world);
	ft_printf("\nClosing window... End of game !\n");
	exit(0);
}

void	move_player(t_world *world, int key)
{
	int		x_new;
	int		y_new;
	char	c;

	x_new = world->player->x;
	y_new = world->player->y;
	if (key == 97 && x_new - world->image->img_width > 0)
		x_new -= world->image->img_width;
	else if (key == 100 && x_new + world->image->img_width < world->width_w - 1)
		x_new += world->image->img_width;
	else if (key == 115 && y_new + world->image->img_height < world->height_w
		- 1)
		y_new += world->image->img_height;
	else if (key == 119 && y_new - world->image->img_height > 0)
		y_new -= world->image->img_height;
	c = world->map->map[y_new / world->image->img_height][x_new
		/ world->image->img_width];
	if (c == 'E' && world->map->c == 0)
		close_window(world);
	else if (c != '1')
	{
		if (world->map->map[world->player->y
			/ world->image->img_height][world->player->x
			/ world->image->img_width] == 'E')
			mlx_put_image_to_window(world->mlx, world->window,
				world->image->exit, world->player->x, world->player->y);
		else
			mlx_put_image_to_window(world->mlx, world->window,
				world->image->grass, world->player->x, world->player->y);
		mlx_put_image_to_window(world->mlx, world->window, world->image->player,
			x_new, y_new);
		world->player->x = x_new;
		world->player->y = y_new;
		if (c == 'C')
		{
			world->map->map[y_new / world->image->img_height][x_new
				/ world->image->img_width] = '0';
			world->map->c--;
		}
		world->move++;
	}
}
