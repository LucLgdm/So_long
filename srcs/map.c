/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/03 15:20:54 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	check_map_error(t_world *world)
{
	check_border(world->map);
	check_content(world->map);
	check_way(world->map);
}

void	check_border(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			print_message_and_exit("Error\n");
	}
	i = -1;
	while (++i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			print_message_and_exit("Error\n");
	}
}

void	check_content(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			c = map->map[i][j];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
				print_message_and_exit("Error\n");
			fill_struct(map, i, j);
		}
	}
	if (map->c == 0 || map->e == 0)
		print_message_and_exit("Error\n");
}

void	fill_struct(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		map->start_pos = (t_position *)malloc(sizeof(t_position));
		if (!map->start_pos)
			print_message_and_exit("Error malloc start_pos\n");
		map->start_pos->x = i;
		map->start_pos->y = j;
	}
	else if (map->map[i][j] == 'E')
	{
		map->exit = (t_position *)malloc(sizeof(t_position));
		if (!map->exit)
			print_message_and_exit("Error malloc exit\n");
		map->exit->x = i;
		map->exit->y = j;
		map->e = 1;
	}
	else if (map->map[i][j] == 'C')
		map->c++;
	else
		return ;
}
