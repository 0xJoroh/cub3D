/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:24:35 by mait-si-          #+#    #+#             */
/*   Updated: 2020/03/08 20:59:28 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return ((float)sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2)));
}