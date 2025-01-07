/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/07 15:23:58 by lde-merc         ###   ########.fr       */
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
	char	ch;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ch = map->map[i][j];
			if (ch != '1' && ch != '0' && ch != 'P' && ch != 'E' && ch != 'C')
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
		// fill_coin(map, i, j);
		map->c++;
	else
		return ;
}

void	fill_coin(t_map *map, int i, int j)
{
	t_coin	*tmp_coin;
	int	k;
	
	tmp_coin = NULL;
	if (map->coin->position)
		tmp_coin->position = map->coin->position;
	map->c++;
	map->coin->position = (t_position **)malloc(map->c * sizeof(t_position *));
	if (!map->coin)
		print_message_and_exit("Error malloc coin\n");
	k = -1;
	while(tmp_coin->position[++k])
		map->coin->position[k] = tmp_coin->position[k];
	map->coin->position[k]->x = i;
	map->coin->position[k]->y = j;
	k = -1;
	while (tmp_coin->position[++k])
		free(tmp_coin->position[k]);
	free(tmp_coin->position);
	free(tmp_coin);
}
