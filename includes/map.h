/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:38:27 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/20 15:02:38 by lde-merc         ###   ########.fr       */
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
	t_position	exit;
	t_position	start_pos;
}	t_map;

void	check_map_error(t_world *world);
void	check_border(t_map *map);
void	check_content(t_map *map);
void	fill_struct(t_map *map, char c);

#endif