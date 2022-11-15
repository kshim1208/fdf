/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:41:13 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:06 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_parser_struct_bonus.h"
#include "../../bonus_includes/fdf_parser_bonus.h"

#include "../../bonus_includes/fdf_error_bonus.h"

void	ft_fdf_set_gl_to_lst(char *str_start, char **str_end,
	t_list **val_list, int min_max_z[2])
{
	t_list				*tmp_list;
	t_parse_value_node	*parse_value_node;
	int					value;

	parse_value_node = (t_parse_value_node *)malloc(sizeof(t_parse_value_node));
	tmp_list = ft_lstnew(parse_value_node);
	if (parse_value_node == 0 || tmp_list == 0)
		ft_fdf_exit("ft_fdf_set_gl_to_lst", FAIL_MEMORY_ALLOC);
	ft_memset(parse_value_node, 0, sizeof(t_parse_value_node));
	value = ft_atoi_fdf(str_start, str_end);
	if (value >= min_max_z[1])
		min_max_z[1] = value;
	if (value <= min_max_z[0])
		min_max_z[0] = value;
	parse_value_node -> val = value;
	if (**str_end == ',')
	{
		value = ft_hex_atoi_fdf(*str_end, str_end);
		parse_value_node -> color = value;
	}
	else
		parse_value_node -> color = 0xFFFFFF;
	ft_lstadd_back(val_list, tmp_list);
	return ;
}

int	ft_atoi_fdf(char *str, char **end)
{
	long long	ret;
	int			sign;
	int			num;

	ret = 0;
	sign = 1;
	sign = 1 - ((*str == '-') << 1);
	str += (*str == '+' || *str == '-');
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		if ((ret * sign) > 10000 || (ret * sign) < -10000)
			ft_fdf_exit("ft_atoi_fdf", FAIL_INPUT_LEN);
		str++;
	}
	if (*str == '\0' || *str == ' ' || *str == '\n' || *str == ',')
	{
		num = (int)(ret * sign);
		*end = str;
		return (num);
	}
	else
		ft_fdf_exit("ft_atoi_fdf", FAIL_ATOI);
	return (0);
}

int	ft_hex_atoi_fdf(char *str, char **end)
{
	int	ret;
	int	num;

	ret = 0;
	str++;
	if (*str == '0')
		str++;
	else
		ft_fdf_exit("ft_hex_atoi_fdf", FAIL_HEX_ATOI);
	if (*str == 'x')
		str++;
	else
		ft_fdf_exit("ft_hex_atoi_fdf", FAIL_HEX_ATOI);
	if (ft_hex_c_to_val(&str, &ret) == 0)
		ft_fdf_exit("ft_hex_atoi_fdf", FAIL_HEX_ATOI);
	if (*str == '\0' || *str == ' ' || *str == '\n')
	{
		num = ret;
		*end = str;
		return (num);
	}
	else
		ft_fdf_exit("ft_hex_atoi_fdf", FAIL_HEX_ATOI);
	return (0);
}

int	ft_hex_c_to_val(char **str, int *ret)
{
	int	len;

	len = 0;
	while (len < 8)
	{
		if (**str >= '0' && **str <= '9')
			*ret = *ret * 16 + (**str - '0');
		else if (**str >= 'A' && **str <= 'F')
			*ret = *ret * 16 + ((**str - 'A') + 10);
		else if (**str >= 'a' && **str <= 'f')
			*ret = *ret * 16 + ((**str - 'a') + 10);
		else if (**str == '\0' || **str == ' ' || **str == '\n')
			return (1);
		else
			return (0);
		len++;
		(*str)++;
	}
	return (1);
}
