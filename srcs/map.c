/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/08 15:52:08 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

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
	map->coin = malloc(sizeof(t_coin));
	map->coin->position = malloc(sizeof(t_position *));
	if (!map->coin || !map->coin->position)
		print_message_and_exit("Error malloc check content\n");
	map->c = 0;
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
	{
		map->c++;
		if (map->c == 1)
			fill_coin_first(map, i, j);
		else
			fill_coin_last(map, i, j);
	}
}

void	fill_coin_first(t_map *map, int i, int j)
{
	map->coin->position[0] = (t_position *)malloc(sizeof(t_position));
	if (!map->coin->position[0])
		print_message_and_exit("Error malloc first coin\n");
	map->coin->position[0]->x = j;
	map->coin->position[0]->y = i;
}

void	fill_coin_last(t_map *map, int i, int j)
{
	t_position	**tmp_pos;
	int			k;

	tmp_pos = map->coin->position;
	map->coin->position = (t_position **)malloc(map->c * sizeof(t_position *));
	if (!map->coin->position)
		print_message_and_exit("Error malloc coin\n");
	k = -1;
	while (++k < map->c - 1)
	{
		map->coin->position[k] = (t_position *)malloc(sizeof(t_position));
		if (!map->coin->position[k])
			print_message_and_exit("Error malloc coin\n");
		map->coin->position[k]->x = tmp_pos[k]->x;
		map->coin->position[k]->y = tmp_pos[k]->y;
		free(tmp_pos[k]);
	}
	map->coin->position[k] = (t_position *)malloc(sizeof(t_position));
	if (!map->coin->position[k])
		print_message_and_exit("Error malloc coin\n");
	map->coin->position[k]->x = j;
	map->coin->position[k]->y = i;
	free(tmp_pos);
}
