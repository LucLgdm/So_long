/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:15:43 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/09 16:10:44 by lde-merc         ###   ########.fr       */
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
	free_all(world);
    exit(0);
}

void	move_player(t_world *world, int key)
{
    int	x_tmp;
	int	y_tmp;

    x_tmp = world->player->position->x;
    y_tmp = world->player->position->y;
	if (key == 97 && x_tmp - world->map->image[1]->img_width > 0)
		x_tmp -= world->map->image[1]->img_width;
	else if (key == 100 && x_tmp + world->map->image[1]->img_width < world->width_w - 1)
		x_tmp += world->map->image[1]->img_width;
	else if (key == 119 && y_tmp - world->map->image[1]->img_height > 0)
		y_tmp -= world->map->image[1]->img_height;
	else if (key == 115 && y_tmp + world->map->image[1]->img_height < world->height_w - 1)
		y_tmp += world->map->image[1]->img_height;
    ft_printf("\tposition player : (%i, %i)\tmap = %c\n", x_tmp / world->map->image[0]->img_width, y_tmp / world->map->image[0]->img_height, world->map->map[y_tmp / world->map->image[0]->img_height][x_tmp / world->map->image[0]->img_width]);
    if (world->map->map[y_tmp / world->map->image[0]->img_height][x_tmp / world->map->image[0]->img_width] != '1') 
    {
        if (world->map->map[y_tmp / world->map->image[0]->img_height][x_tmp / world->map->image[0]->img_width] == 'E' && world->map->c == 0)
        {
            close_window(world);
        }
	    mlx_put_image_to_window(world->mlx, world->window, world->map->image[1]->img, world->player->position->x, world->player->position->y);
        mlx_put_image_to_window(world->mlx, world->window, world->player->image->img, x_tmp, y_tmp);
        world->player->position->x = x_tmp;
        world->player->position->y = y_tmp;
        if (world->map->map[y_tmp / world->map->image[0]->img_height][x_tmp / world->map->image[0]->img_width] == 'C')
        {
            world->map->map[y_tmp / world->map->image[0]->img_height][x_tmp / world->map->image[0]->img_width] = '0';
            world->map->c--;
        }
        world->move++;
    }
}
