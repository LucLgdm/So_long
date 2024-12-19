/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:46:07 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 16:41:25 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/world.h"

int	main(int argc, char **argv)
{
	t_world	world;
	
	world.map = map_constructor(argc, argv);
	
}


/************************************************************************
 * Map's parsing
 * 	_ char : 1, 0, C, E, P; only 1 S, 1 P, at least 1 C : return Error\n
 * 	_ surrounded by wall : return Error\n
 * 	_ must be a rectangle : return Error\n
 * 	_ One valid way to reach the exit and all the items : return Error\n
 ************************************************************************/