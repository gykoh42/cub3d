/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:19:32 by gykoh             #+#    #+#             */
/*   Updated: 2024/03/20 09:19:32 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	choose_texture(t_game_info *game, t_raycast *ray)
{
	if (ray->side == DECIDE_N_OR_S && ray->ray_dir.y < 0)
		ray->wall_type = &game->so_texture;
	else if (ray->side == DECIDE_N_OR_S && ray->ray_dir.y > 0)
		ray->wall_type = &game->no_texture;
	else if (ray->side == DECIDE_W_OR_E && ray->ray_dir.x < 0)
		ray->wall_type = &game->we_texture;
	else if (ray->side == DECIDE_W_OR_E && ray->ray_dir.x > 0)
		ray->wall_type = &game->ea_texture;
}
