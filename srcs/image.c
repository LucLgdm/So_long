/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 12:42:08 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	image_generator(t_world *world)
{
	world->width_w = world->map->width;
	world->height_w = world->map->height;
	image_map(world);
	image_player(world);
	image_coin(world);
	image_exit(world);
}

void	image_map(t_world *world)
{
	int	i;
	int	j;

	i = -1;
	world->map->image = malloc(2 * sizeof(t_image *));
	if (!world->map->image)
		print_message_and_exit("Error malloc image\n");
	world->map->image[0] = malloc(sizeof(t_image));
	world->map->image[1] = malloc(sizeof(t_image));
	if (!world->map->image[0] || !world->map->image[1])
		print_message_and_exit("Error malloc map image\n");
	world->map->image[0]->img = malloc(sizeof(void));
	world->map->image[1]->img = malloc(sizeof(void));
	if (!world->map->image[0]->img || !world->map->image[1]->img)
		print_message_and_exit("Error malloc map image\n");
	i = -1;
	while (++i < world->map->height)
	{
		j = -1;
		while (++j < world->map->width)
		{
			if (world->map->map[i][j] == '1')
			{
				world->map->image[0]->img = mlx_xpm_file_to_image(world->mlx, "textures/wall.xpm", &world->map->image[0]->img_width, &world->map->image[0]->img_height);
				mlx_put_image_to_window(world->mlx, world->window, world->map->image[0]->img, j * world->map->image[0]->img_width, i * world->map->image[0]->img_height);
			}
			else
			{
				world->map->image[1]->img = mlx_xpm_file_to_image(world->mlx, "textures/empty.xpm", &world->map->image[1]->img_width, &world->map->image[1]->img_height);
				mlx_put_image_to_window(world->mlx, world->window, world->map->image[1]->img, j * world->map->image[0]->img_width, i * world->map->image[0]->img_height);
			}
		}
	}
}

void	image_coin(t_world *world)
{
	int	i;

	i = -1;
	world->map->coin->image = malloc(sizeof(t_image));
	if (!world->map->coin->image)
		print_message_and_exit("Error malloc image coin\n");
	world->map->coin->image->img = malloc(sizeof(void));
	if (!world->map->coin->image->img)
		print_message_and_exit("Error malloc image coin\n");
	world->map->coin->image->img = mlx_xpm_file_to_image(world->mlx, "textures/coin.xpm", &world->map->coin->image->img_width, &world->map->coin->image->img_height);
	while (world->map->coin->position[++i])
		mlx_put_image_to_window(world->mlx, world->window, world->map->coin->image->img, world->map->image[0]->img_width * world->map->coin->position[i]->x, world->map->image[0]->img_height * world->map->coin->position[i]->y);
}

void	image_player(t_world *world)
{
	world->player = malloc(sizeof(t_player));
	if (!world->player)
		print_message_and_exit("Error malloc player\n");
	world->player->image = malloc(sizeof(t_image));
	if (!world->player->image)
		print_message_and_exit("Error malloc image player\n");
	world->player->image->img = malloc(sizeof(void));
	if (!world->player->image->img)
		print_message_and_exit("Error malloc image player\n");
	world->player->image->img = mlx_xpm_file_to_image(world->mlx, "textures/player.xpm", &world->player->image->img_width, &world->player->image->img_height);
	mlx_put_image_to_window(world->mlx, world->window, world->player->image->img, world->map->image[0]->img_width * world->map->start_pos->x, world->map->image[0]->img_height * world->map->start_pos->y);
}

void	image_exit(t_world *world)
{
	world->map->texit = malloc(sizeof(t_exit));
	if (!world->map->texit)
		print_message_and_exit("Error malloc exit\n");
	world->map->texit->image = malloc(sizeof(t_image));
	if (!world->map->texit->image)
		print_message_and_exit("Error malloc image exit\n");
	world->map->texit->image->img = malloc(sizeof(void));
	if (!world->map->texit->image->img)
		print_message_and_exit("Error malloc image exit\n");
	world->map->texit->image->img = mlx_xpm_file_to_image(world->mlx, "textures/exit.xpm", &world->map->texit->image->img_width, &world->map->texit->image->img_height);
	mlx_put_image_to_window(world->mlx, world->window, world->map->texit->image->img, world->map->image[0]->img_width * world->map->exit->x, world->map->image[0]->img_height * world->map->exit->y);
}
