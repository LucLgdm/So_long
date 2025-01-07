/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:01 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/07 15:53:42 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COIN_H
# define COIN_H

# include "position.h"

typedef struct s_coin
{
    t_position  **position;
    void        *image;
}   t_coin;

#endif