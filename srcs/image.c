/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 12:08:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	image_generator(t_world *world)
{
	int		x;
	int		y;
	char	*str;

	world->image = malloc(sizeof(t_image));
	if (!world->image)
		print_message_and_exit("Error malloc image\n");
	str = "textures/1_tiles/FieldsTile_01.xpm";
	world->image->wall = mlx_xpm_file_to_image(world->mlx, str,
			&world->image->img_width, &world->image->img_height);
	x = world->image->img_width;
	y = world->image->img_height;
	str = "textures/1_tiles/FieldsTile_38.xpm";
	world->image->grass = mlx_xpm_file_to_image(world->mlx, str, &x, &y);
	str = "textures/2_objects/6_Flower/1.xpm";
	world->image->coin = mlx_xpm_file_to_image(world->mlx, str, &x, &y);
	str = "textures/1_tiles/FieldsTile_19.xpm";
	world->image->player = mlx_xpm_file_to_image(world->mlx, str, &x, &y);
	str = "textures/1_tiles/FieldsTile_25.xpm";
	world->image->exit = mlx_xpm_file_to_image(world->mlx, str, &x, &y);
	world->player->x *= world->image->img_width;
	world->player->y *= world->image->img_height;
}
