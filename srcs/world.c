/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:24:29 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/20 16:18:43 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

t_world	*world_constructor(int argc, char **argv, t_world *world)
{
	int	fd;

	if (argc != 2)
		print_message_and_exit("Ereor\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_message_and_exit("Error while opening the file\n");
	extract_map(fd, world);
	return (world);
}

void		extract_map(int fd, t_world *world)
{
	char 	*line;
	int		height;

	world->map = (t_map *)malloc(sizeof(t_map));
	if (!world->map)
		print_message_and_exit("Error with map malloc");
	height = 0;
	while ((line = get_next_line(fd)))
	{
		++height;
		if (height == 1)
		{
			world->map->map = (char *)malloc(height * sizeof(char *));
			if (!world->map->map)
				print_message_and_exit("Error with map->map malloc");
		}
		new_line_in_map(world, height);
		
	}
}

void	new_line_in_map(t_world *world, int height)
{
	// reprendre l'idee du dico du rush 02
}
