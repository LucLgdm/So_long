/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:42:01 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/08 16:07:51 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../libft/libft.h"
# include "map.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "player.h"
# include <stdint.h>
# include <errno.h>
# include "utils.h"

typedef struct s_world
{
	void		*mlx;
	void		*window;
	int			width_w;
	int			height_w;
	t_map		*map;
	t_player	*player;
	int			move;
}	t_world;

// World construction
t_world		*world_constructor(int argc, char **argv, t_world *world);
void		extract_map(int fd, t_world *world);
void		new_line_in_map(t_world *world, int height, char *line);
void		check_map_error(t_world *world);

// Image generator
void		image_generator(t_world *world);
void		image_map(t_world *world);
void		image_coin(t_world * world);
void		image_player(t_world *world);
void		image_exit(t_world *world);

// World liberation
void		free_all(t_world *world);
void		free_map(t_world *world);
void		free_coin(t_world *world);
void		free_image(t_world *world);

// Event
void	event_handle(t_world *world);

#endif
