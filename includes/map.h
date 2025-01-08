/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:38:27 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 14:14:05 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "position.h"
# include "utils.h"
# include <fcntl.h>
# include <unistd.h>
# include "coin.h"
# include "exit.h"

typedef struct s_map
{
	char		**map;
	bool		e;
	int			c;
	int			height;
	int			width;
	t_position	*exit;
	t_position	*start_pos;
	t_coin		*coin;
	t_image		**image;
	t_exit		*texit;
}	t_map;

void	check_border(t_map *map);
void	check_content(t_map *map);
void	fill_struct(t_map *map, int i, int j);
void	fill_coin_first(t_map *map, int i, int j);
void	fill_coin_last(t_map *map, int i, int j);

// DFS Algo
void	check_way(t_map *map);
void	check_e_c(t_map *map, char **visited);
void	dfs(int x, int y, t_map *map, char **visited);
bool	is_valid(int x, int y, t_map *map, char **visited);
void	fill_dx_dy(int *dx, int *dy);

#endif