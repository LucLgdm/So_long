/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:34:58 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/13 09:14:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define PLAYER "textures/player.xpm"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define ENEMY "textures/enemy.xpm"
# define EXIT "textures/exit.xpm"
# define COIN "textures/coin.xpm"

typedef struct s_image
{
	void	*wall;
	void	*grass;
	void	*player;
	void	*exit;
	void	*coin;
	int		img_height;
	int		img_width;
}			t_image;

#endif