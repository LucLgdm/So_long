/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:01 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 10:06:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COIN_H
# define COIN_H

# include "image.h"
# include "position.h"

typedef struct s_coin
{
	t_position	**position;
}				t_coin;

#endif