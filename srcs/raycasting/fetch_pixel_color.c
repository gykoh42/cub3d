/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pixel_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:19:42 by gykoh             #+#    #+#             */
/*   Updated: 2024/03/20 09:19:43 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	fetch_pixel_color(t_texture *texture, int x, int y)
{
	int	res;
	int	*texture_addr;

	texture_addr = (int *)texture->addr;
	if (x >= texture->width || y >= texture->height
		|| x < 0 || y < 0)
		return (0);
	res = texture_addr[texture->line_length / (texture->bpp / 8) * y + x];
	return (res);
}
