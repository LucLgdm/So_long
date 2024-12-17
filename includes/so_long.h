/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:42:01 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 14:01:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"


# include <stdint.h>

# include "data.h"
# include "map.h"
# include "player.h"

typedef struct s_world
{
	t_map		*map;
	t_data		*data;
	t_player	*player;
}	t_world;

#endif



// # include <X11/Xatom.h>
// # include <X11/Xlib.h>
// # include <X11/Xos.h>
// # include <X11/Xutil.h>
// # include <X11/extensions/Xext.h>