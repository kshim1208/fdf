/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:38:58 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"

#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_bonus.h"
#include "../../bonus_includes/fdf_error_bonus.h"

#include <stdlib.h>

void	ft_mlx_set(t_fdf_mlx *mlx_data, int win_width, int win_height)
{
	mlx_data -> mlx_ptr = mlx_init();
	mlx_data -> mlx_win
		= mlx_new_window(mlx_data -> mlx_ptr, win_width, win_height, "fdf");
	ft_mlx_new_img(mlx_data, win_width, win_height);
	return ;
}

void	ft_mlx_new_img(t_fdf_mlx *mlx_data, int win_width, int win_height)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_data -> mlx_ptr, win_width, win_height);
	mlx_data -> img = (t_fdf_img *)malloc(sizeof(t_fdf_img));
	if (mlx_data -> img == 0)
		ft_fdf_exit("ft_mlx_new_img", FAIL_MEMORY_ALLOC);
	mlx_data -> img -> img_ptr = img_ptr;
	mlx_data -> img -> addr = mlx_get_data_addr(mlx_data -> img -> img_ptr,
			&(mlx_data -> img -> bits_per_pixel),
			&(mlx_data -> img -> size_line), &(mlx_data -> img -> endian));
	return ;
}

void	ft_mlx_img_pixel(t_fdf_img	*img, int pixel_x, int pixel_y, int color)
{
	char	*pnt;

	pnt = img -> addr + (pixel_y * img -> size_line) + (
			pixel_x * (img -> bits_per_pixel / 8));
	*(unsigned int *)pnt = color;
	return ;
}
