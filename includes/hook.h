/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:15:19 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 18:58:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "world.h"

int		close_window(t_world *world);
int		key_handle(int key, void *data);
void	clear_image(char *str, t_world *world);
void	move_player(t_world *world, int key);
void	case_c(t_world *world, int x_new, int y_new);

#endif