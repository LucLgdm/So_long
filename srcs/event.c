/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:17:45 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/09 09:01:45 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hook.h"

void	event_handle(t_world *world)
{
	mlx_hook(world->window, 17, 1L << 19, close_window, NULL);
	mlx_key_hook(world->window, key_handle, world);
}
