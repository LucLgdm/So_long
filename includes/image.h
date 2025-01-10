/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:34:58 by lde-merc          #+#    #+#             */
/*   Updated: 2025/01/10 10:04:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

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