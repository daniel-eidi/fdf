/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:17:05 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/04/02 22:15:50 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mod(float x)
{
	if (x >= 0)
		return (x);
	return (x * -1);
}

int	max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	min(float x, float y)
{
	if (x >= y)
		return (y);
	return (x);
}
