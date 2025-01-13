/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:17:45 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/13 11:11:25 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hook.h"

void	event_handle(t_world *world)
{
	mlx_hook(world->window, 17, 1L << 19, close_window, world);
	mlx_hook(world->window, 2, 1L << 0, key_handle, world);
}
