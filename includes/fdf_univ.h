/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_univ.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:04 by kshim             #+#    #+#             */
/*   Updated: 2022/10/31 18:29:25 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UNIV_H
# define FDF_UNIV_H

t_fdf_univ	*ft_init_fdf_univ(void);
void		ft_set_univ(t_fdf_univ *fdf, t_fdf_mlx *mlx_data);
void		ft_set_rend_val(t_fdf_rend_val *rend_val);

#endif