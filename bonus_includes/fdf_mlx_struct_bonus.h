/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:24 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:55 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_STRUCT_BONUS_H
# define FDF_MLX_STRUCT_BONUS_H

typedef struct s_fdf_mlx_img_data{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fdf_img;

typedef struct s_fdf_mlx_data{
	void		*mlx_ptr;
	void		*mlx_win;
	t_fdf_img	*img;
}			t_fdf_mlx;

#endif