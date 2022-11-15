/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:24 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:20 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_BONUS_H
# define FDF_MLX_BONUS_H

void	ft_mlx_set(t_fdf_mlx *mlx_data, int win_width, int win_height);
void	ft_mlx_new_img(t_fdf_mlx *mlx_data, int win_width, int win_height);

void	ft_mlx_img_pixel(t_fdf_img	*img, int pixel_x, int pixel_y, int color);

#endif