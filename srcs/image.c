/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/13 09:15:40 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	image_generator(t_world *world)
{
	int		x;
	int		y;

	world->image = malloc(sizeof(t_image));
	if (!world->image)
		print_message_and_exit("Error malloc image\n");
	world->image->wall = mlx_xpm_file_to_image(world->mlx, WALL,
			&world->image->img_width, &world->image->img_height);
	x = world->image->img_width;
	y = world->image->img_height;
	world->image->grass = mlx_xpm_file_to_image(world->mlx, FLOOR, &x, &y);
	world->image->coin = mlx_xpm_file_to_image(world->mlx, COIN, &x, &y);
	world->image->player = mlx_xpm_file_to_image(world->mlx, PLAYER, &x, &y);
	world->image->exit = mlx_xpm_file_to_image(world->mlx, EXIT, &x, &y);
	world->player->x *= world->image->img_width;
	world->player->y *= world->image->img_height;
}
