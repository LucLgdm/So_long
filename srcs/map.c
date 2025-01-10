/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/10 12:46:30 by lde-merc         ###   ########.fr       */
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

void	check_content(t_world *world)
{
	int		i;
	int		j;
	char	ch;

	i = -1;
	world->coin = (t_position **)malloc(sizeof(t_position *));
	if (!world->coin)
		print_message_and_exit("Error malloc coin\n");
	world->map->c = 0;
	while (++i < world->map->height)
	{
		j = -1;
		while (++j < world->map->width)
		{
			ch = world->map->map[i][j];
			if (ch != '1' && ch != '0' && ch != 'P' && ch != 'E' && ch != 'C')
				print_message_and_exit("Error\n");
			fill_struct(world, i, j);
		}
	}
	if (world->map->c == 0 || world->map->e == 0)
		print_message_and_exit("Error\n");
}

void	fill_struct(t_world *world, int i, int j)
{
	if (world->map->map[i][j] == 'P')
	{
		world->player->x = j;
		world->player->y = i;
	}
	else if (world->map->map[i][j] == 'E')
	{
		world->exit->x = j;
		world->exit->y = i;
		world->map->e = 1;
	}
	else if (world->map->map[i][j] == 'C')
	{
		world->map->c++;
		if (world->map->c == 1)
			fill_coin_first(world, i, j);
		else
			fill_coin_last(world, i, j);
	}
}

void	fill_coin_first(t_world *world, int i, int j)
{
	world->coin[0] = malloc(sizeof(t_position *));
	if (!world->coin[0])
		print_message_and_exit("Error malloc coin first\n");
	world->coin[0]->x = j;
	world->coin[0]->y = i;
}

void	fill_coin_last(t_world *world, int i, int j)
{
	t_position	**tmp_pos;
	int			k;

	tmp_pos = (t_position **)malloc(world->map->c * sizeof(t_position *));
	if (!tmp_pos)
		print_message_and_exit("Error malloc last coin\n");
	k = -1;
	while (++k < world->map->c - 1)
	{
		tmp_pos[k] = (t_position *)malloc(sizeof(t_position));
		if (!tmp_pos[k])
			print_message_and_exit("Error malloc last coin\n");
		tmp_pos[k]->x = world->coin[k]->x;
		tmp_pos[k]->y = world->coin[k]->y;
	}
	free_coin(world);
	world->coin = (t_position **)malloc(world->map->c * sizeof(t_position *));
	tmp_pos[k] = (t_position *)malloc(sizeof(t_position));
	if (!tmp_pos[k] || !world->coin)
		print_message_and_exit("Error malloc last coin\n");
	tmp_pos[k]->x = j;
	tmp_pos[k]->y = i;
	k = -1;
	while (++k < world->map->c)
		world->coin[k] = tmp_pos[k];
}
