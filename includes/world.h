/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:42:01 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 17:41:42 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"


# include <stdint.h>

# include "data.h"
# include "map.h"
# include "player.h"
# include "utils.h"

typedef struct s_world
{
	t_map		*map;
	t_data		*data;
	t_player	*player;
}	t_world;


t_map	*map_constructor(int argc, char **argv);
void	check_shape_map(int fd, t_map *map);

#endif



// # include <X11/Xatom.h>
// # include <X11/Xlib.h>
// # include <X11/Xos.h>
// # include <X11/Xutil.h>
// # include <X11/extensions/Xext.h>