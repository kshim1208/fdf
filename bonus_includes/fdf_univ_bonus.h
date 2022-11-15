/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_univ_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:04 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:36 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UNIV_BONUS_H
# define FDF_UNIV_BONUS_H

t_fdf_univ	*ft_init_fdf_univ(void);
void		ft_set_univ(t_fdf_univ *fdf, t_fdf_mlx *mlx_data);
void		ft_set_rend_val(t_fdf_rend_val *rend_val);

#endif