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
		print_message_and_exit("Error\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_message_and_exit("Error while opening the file\n");
	extract_map(fd, world);
	check_map_error(world);
	if (world->map->height == world->map->width)
		print_message_and_exit("Error\n");
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
		if (height == 0)
		{
			world->map->map = (char *)malloc(sizeof(char *));
			if (!world->map->map)
				print_message_and_exit("Error with map->map malloc");
		}
		new_line_in_map(world, height, line);
		++height;
	}
	world->map->map[height] = NULL;
	world->map->height = height;
	world->map->width = ft_strlen(world->map->map[0]);
}

void	new_line_in_map(t_world *world, int height, char *line)
{
	int		i;
	char	**tmp;

	tmp = world->map->map;
	world->map->map = malloc((height + 1) * sizeof(char *));
	if (!world->map->map)
		print_message_and_exit("Error with map->map malloc");
	i = -1;
	while (++i < height)	
		world->map->map[i] = tmp[i];
	world->map->map[height] = ft_strdup(line);
	free(tmp);
}

