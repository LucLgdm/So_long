/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:42:01 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/03 12:44:54 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../libft/libft.h"
# include "data.h"
# include "map.h"
# include "player.h"
# include "utils.h"
# include <stdint.h>
# include <errno.h>

typedef struct s_world
{
	t_map		*map;
	t_data		*data;
	t_player	*player;
}	t_world;

// World construction
t_world		*world_constructor(int argc, char **argv, t_world *world);
void		extract_map(int fd, t_world *world);
void		new_line_in_map(t_world *world, int height, char *line);
void		check_map_error(t_world *world);


// World liberation
void		free_all(t_world *world);
void		free_map(t_world *world);

#endif

// # include <X11/Xatom.h>
// # include <X11/Xlib.h>
// # include <X11/Xos.h>
// # include <X11/Xutil.h>
// # include <X11/extensions/Xext.h>