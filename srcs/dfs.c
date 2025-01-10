/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:14:38 by marvin            #+#    #+#             */
/*   Updated: 2025/01/10 11:10:41 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

void	check_e_c(t_map *map, char **visited)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
				&& !visited[i][j])
				print_message_and_exit("Error\n");
		}
	}
}

void	check_way(t_world *world)
{
	char	**visited;
	int		i;

	visited = ft_calloc(world->map->height, sizeof(char *));
	i = -1;
	while (++i < world->map->height)
		visited[i] = ft_calloc((world->map->width), sizeof(char));
	dfs(world->player->x, world->player->y, world->map, visited);
	check_e_c(world->map, visited);
}

void	dfs(int x, int y, t_map *map, char **visited)
{
	int	*dx;
	int	*dy;
	int	i;

	dx = (int *)malloc(4 * sizeof(int));
	if (!dx)
		print_message_and_exit("Error dfs\n");
	dy = (int *)malloc(4 * sizeof(int));
	if (!dy)
		print_message_and_exit("Error dfs\n");
	fill_dx_dy(dx, dy);
	visited[x][y] = 1;
	i = -1;
	while (++i < 4)
	{
		if (is_valid(x + dx[i], y + dy[i], map, visited))
			dfs(x + dx[i], y + dy[i], map, visited);
	}
	free(dx);
	free(dy);
}

bool	is_valid(int x, int y, t_map *map, char **visited)
{
	char	c;

	c = map->map[x][y];
	return (x >= 0 && x < map->height && y >= 0 && y < map->width
		&& !visited[x][y] && (c == '0' || c == 'C' || c == 'E'));
}

void	fill_dx_dy(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}
