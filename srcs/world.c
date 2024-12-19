/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:24:29 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 17:46:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

t_map	*map_constructor(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		print_error_and_exit();
	else
	{
		map = malloc(sizeof(t_map));
		check_shape_map(fd, map);
	}
	
	return (map);
}

/*
if (check_file_name(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			check_shape_map(fd);
			check_content_map(fd);

		}
		*/

void	check_shape_map(int fd, t_map *map)
{
	int		height;
	int		width;
	int		i;
	char	*line;
	
	height = 0;
	while (line = get_next_line(fd))
	{
		if (height == 0)
			width = ft_strlen(line);
		else
		{
			if (width != ft_strlen(line))
				print_error_and_exit();
		}
		height++;
	}
	map->map = (char**)malloc(height * sizeof(char *));
	i = -1;
	while (++i < height)
		map->map[i] = (char *)malloc(width * sizeof(char));
}

void	check_content_map(int fd)
{
	char	*line;
	int		i;
	int		height;

	height = 0;
	while(line = get_next_line(fd))
	{
		i = -1;
		if (height == 0)
		{
			while(line[++i])
			{
				if (line[i] != '1')
					print_error_and_exit();
			}
		}
		else
		{
			while(line[++i])
			{
				if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P')
					print_error_and_exit();
			}
		}
	}
}
