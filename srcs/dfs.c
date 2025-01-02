/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:14:38 by marvin            #+#    #+#             */
/*   Updated: 2025/01/02 14:27:20 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map.h"

void	check_way(t_map *map)
{
	char    **visited;
    int     i;
    int     j;

    visited = malloc((map->height) * sizeof(char *));
    if (!visited)
        print_message_and_exit("Error malloc dfs");
    i = -1;
    while (++i < map->height)
    {
        visited[i] = malloc((map->width) * sizeof(char));
        if (!visited[i])
            print_message_and_exit("Error malloc dfs");
    }
    dfs(map->start_pos->x, map->start_pos->y, map, visited);
    i = -1;
    while (++i < map->height)
    {
        j = -1;
        while (++j < map->width)
        {
            if ((map->map[i][j] == 'C' || map->map[i][j] == 'E') && !visited[i][j])
                print_message_and_exit("Error\n");
        }
    }
}

void    dfs(int x, int y, t_map *map, char **visited)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int i;

    // dx = (int *)malloc(4 * sizeof(int));
    // if (!dx)
    //     print_message_and_exit("Error dfs\n");
    // dy = (int *)malloc(4 * sizeof(int));
    // if (!dy)
    //     print_message_and_exit("Error dfs\n");
    // dx = {-1, 1, 0, 0};
    // dy = {0, 0, -1, 1};    
    visited[x][y] = 1;
    i = -1;
    while (++i < 4)
    {
        if (is_valid(x + dx[i], y + dy[i], map, visited))
            dfs(x + dx[i], y + dy[i], map, visited);
    }
}

bool    is_valid(int x, int y, t_map *map, char **visited)
{
    return (x >= 0 && x < map->height && y >= 0 && y < map->width \
            && !visited[x][y] \
            && (map->map[x][y] == '0' || map->map[x][y] == 'C' \
            || map->map[x][y] == 'E'));
}