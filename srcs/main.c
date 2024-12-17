/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:38:34 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 13:53:45 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	int offset = (y * data->line_length + x * (data->bits_per_pixel / 8));

	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

void	square(t_data *img, int full){
	if (!full){
		for(int i = 350; i <= 450; i++){
			for (int j = 0; j < 6; j++){
				my_mlx_pixel_put(img, i, 10 + j, 0x00FF0000);
				my_mlx_pixel_put(img, i, 110 - j, 0x00FF0000);
				my_mlx_pixel_put(img, 350 + j, i - 340, 0x00FF0000);
				my_mlx_pixel_put(img, 450 - j, i - 340, 0x00FF0000);
			}
		}
	}else{
		for(int i = 351; i < 449; i++){
			for(int j = 11; j < 109; j++){
				my_mlx_pixel_put(img, i, j, 0x0000FF00);
			}
		}
	}
}

void circle(t_data *img, int full, int x, int y, int r){
	if (!full){
		for(int i = x - r; i < x + r + 1; i++){
			for(int j = y - r; j < y + r + 1; j++){
				if (((i-x) * (i-x) + (j-y) * (j-y)) <= (r * r))
					my_mlx_pixel_put(img, x + i, y + j, 0x00FF0000);
			}
		}
	}else{
		for(int i = x - r; i < x + r + 1; i++){
			for(int j = y - r; j < y + r + 1; j++){
				if (((i-x) * (i-x) + (j-y) * (j-y)) <= r * r &&
					((i-x) * (i-x) + (j-y) * (j-y)) >= (r - r/10) * (r - r/10))
					my_mlx_pixel_put(img, x + i, y + j, 0x0000FF00);
			}
		}
	}
}

int	main()
{
	void    *mlx;
	void	*window;
    t_data 	img;
    int		height, width;
	
    mlx = mlx_init();
	mlx_get_screen_size(mlx, &height, &width);
	window = mlx_new_window(mlx, height, width, "so_long");
    img.img = mlx_new_image(mlx, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	square(&img, 1);
	square(&img, 0);
	
	ft_printf("heigth = %i, width = %i\n", height, width);
	circle(&img, 0, 1750, 300, 200);
	circle(&img, 1, 1750, 300, 200);
	
	// circle(&img, 0, 2500, 685, 75);
	// circle(&img, 1, 2500, 685, 75);

	// circle(&img, 0, 1920, 1080, 75);
	// circle(&img, 1, 1920, 1080, 75);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);
	return (0);
}
