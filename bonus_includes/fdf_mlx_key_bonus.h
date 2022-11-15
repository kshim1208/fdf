/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:33:31 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:23 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_KEY_BONUS_H
# define FDF_MLX_KEY_BONUS_H

typedef struct s_key_hook_param{
	int			keycode;
	t_fdf_univ	*fdf_data;
}			t_key_param;

void	ft_mlx_loop(t_fdf_univ *fdf_data);
int		ft_key_press(int keycode, t_fdf_univ *fdf_data);
void	ft_mlx_key_window_destroy_projection_change(int keycode,
			t_fdf_univ *fdf_data);
void	ft_mlx_rebuild_img(t_fdf_univ *fdf_data);

#endif