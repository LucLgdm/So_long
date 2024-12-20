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
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char		**map;
	int			e;
	int			c;
	t_position	exit;
	t_position	collect;
	t_position	start_pos;
}	t_map;

#endif