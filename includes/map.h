/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:38:27 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/02 14:30:35 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "position.h"
# include "utils.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char		**map;
	bool		e;
	int			c;
	int			height;
	int			width;
	t_position	*exit;
	t_position	*start_pos;
}	t_map;


void	check_border(t_map *map);
void	check_content(t_map *map);
void	fill_struct(t_map *map, int i, int j);

// DFS Algo
void	check_way(t_map *map);
void	dfs(int x, int y, t_map *map, char **visited);
bool	is_valid(int x, int y, t_map *map, char **visited);
#endif